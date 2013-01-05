#ifndef _SCANNER_H
#define _SCANNER_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>

#include "TokenStream.h"
#include "Token.h"

typedef char scanchar_t;

#define TOKEN_EOF 0

class Lexer : TokenStream {
public:
	std::queue<Token*> queue;
	std::stack<int> indentstack;
	//int fd; //file descriptor
	FILE *file;
	int line;
	int column;
	//
	scanchar_t buffer[BUFSIZ]; //fill buffer
	scanchar_t cbuffer[BUFSIZ]; //capture buffer
	scanchar_t* cursor;
	scanchar_t* ccursor;
	scanchar_t* bot;
	scanchar_t* lim;
	scanchar_t* ptr;
	scanchar_t* pos;
	scanchar_t* top;
	scanchar_t* marker;
	scanchar_t* eof;
	//
	Lexer(const char *filename);
	virtual Token *read();
	Token *scan();
	void fill();

	Token* emit_newline();

	Token* create_token(int kind);
	Token* create_name_token(char* value);
	Token* create_int_token(int value);
	Token* create_float_token(float value);

	void capture_begin();
	void capture();
	scanchar_t *capture_string();
	int capture_int();
	float capture_float();
};

#endif
