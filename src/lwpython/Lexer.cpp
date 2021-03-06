#include <stdio.h>
#include <malloc.h>

#include "Token.h"
#include "Lexer.h"

#define BSIZE BUFSIZ

Lexer::Lexer(const char *filename)
{
	this->file = fopen(filename, "r" );
	this->indentstack.push(0);
	this->line = 0;
	this->column = 0;

	this->eof = 0;
	this->bot = 0;
	this->top = 0;
	this->cursor = 0;
	this->ccursor = 0;
	this->lim = 0;
}
Token *Lexer::read(){
	Token *tok, *latok;
	int indent = 0;
	if(!this->queue.empty()){
		tok = this->queue.front();
		this->queue.pop();
		return tok;
	}
	//else
	tok = scan();

	switch(tok->kind){

		case TOKEN_EOF:
			while(this->indentstack.top() > 0){
				this->indentstack.pop();
				this->queue.push(new Token(TOKEN_DEDENT));
			}
			this->queue.push(tok);
			break;

		case TOKEN_NEWLINE:
			this->queue.push(tok); //push newline
			latok = scan(); //get lookahead token
			indent = latok->column;
			if(indent > this->indentstack.top()){
				this->queue.push(new Token(TOKEN_INDENT));
				this->indentstack.push(indent);
			}
			else if(indent < this->indentstack.top()){
				while(indent > this->indentstack.top()){
					this->indentstack.pop();
					this->queue.push(new Token(TOKEN_DEDENT));
				}
			}
			this->queue.push(latok);
			break;

		default:
			this->queue.push(tok);
			break;
	}
	tok = this->queue.front();
	this->queue.pop();
	return tok;
}
void Lexer::fill()
{
	if(!this->eof) {
		int cnt = this->ccursor - this->bot;
		if(cnt){
			memcpy(this->bot, this->ccursor, this->lim - this->ccursor);
			this->ccursor = this->bot;
			this->ptr -= cnt;
			this->cursor -= cnt;
			this->pos -= cnt;
			this->lim -= cnt;
		}
		if((this->top - this->lim) < BSIZE){
			scanchar_t *buf = (scanchar_t*) malloc(((this->lim - this->bot) + BSIZE)*sizeof(scanchar_t));
			memcpy(buf, this->ccursor, this->lim - this->ccursor);
			this->ccursor = buf;
			this->ptr = &buf[this->ptr - this->bot];
			this->cursor = &buf[this->cursor - this->bot];
			this->pos = &buf[this->pos - this->bot];
			this->lim = &buf[this->lim - this->bot];
			this->top = &this->lim[BSIZE];
			free(this->bot);
			this->bot = buf;
		}
		if((cnt = fread((char*) this->lim, sizeof(scanchar_t), BSIZE, this->file)) != BSIZE){
			this->eof = &this->lim[cnt]; *(this->eof)++ = '\0';
		}
		this->lim += cnt;
	}
}
Token* Lexer::create_token(int kind) {
	Token* token = (Token*)malloc(sizeof(Token));
	token->kind = kind;
	token->line = this->line;
	token->column = this->column;
	return token;
}
Token* Lexer::emit_newline() {
	Token* token = create_token(TOKEN_NEWLINE);
	this->pos = this->cursor;
	this->line++;
	return token;
}
Token* Lexer::create_name_token(char* value) {
	Token* token = create_token(TOKEN_NAME);
	token->data.str = value;
	return token;
}
Token* Lexer::create_int_token(int value) {
	Token* token = create_token(TOKEN_INTEGER);
	token->data.num = value;
	return token;
}
Token* Lexer::create_float_token(float value) {
	Token* token = create_token(TOKEN_FLOAT);
	token->data.num = value;
	return token;
}
void Lexer::capture_begin()
{
	this->ccursor = this->cursor;
	this->column = this->ccursor - this->pos;
}
void Lexer::capture()
{
	size_t len = this->cursor - this->ccursor;
	memcpy(this->cbuffer, this->ccursor, len);
	this->cbuffer[len] = '\0';
}
scanchar_t *Lexer::capture_string()
{
	size_t len = this->cursor - this->ccursor;
	scanchar_t* str = (scanchar_t*)malloc(len + 1);
	memcpy(str, this->ccursor, len);
	str[len] = '\0';
	return str;
}
int Lexer::capture_int()
{
	capture();
	return atoi(this->cbuffer);
}
float Lexer::capture_float()
{
	capture();
	return (float)atof(this->cbuffer);
}