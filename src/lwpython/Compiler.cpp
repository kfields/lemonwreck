#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "Token.h"
#include "Compiler.h"
#include "Lexer.h"
#include "Parser.h"

int Compiler::compile_file(char* s)
{
	Token *token;
	Lexer *lexer;
	void* pParser = ParseAlloc(malloc);

	clear();

	ParseTrace(stdout, ">>");

	lexer = new Lexer(s);

	for(;;) {
		token = lexer->read();
		Parse(pParser, token->kind, token, this);
		if(token->kind == TOKEN_EOF) break;
	}

	ParseFree(pParser, free);

	if(errormsg != NULL)
		return 0;
	else
		return 1;
}
void Compiler::clear()
{
	errormsg = NULL;
}
void Compiler::error(char *errmsg)
{
	errormsg = errmsg;
}