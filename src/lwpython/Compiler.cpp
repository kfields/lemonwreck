#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "token.h"
#include "compiler.h"
#include "Lexer.h"
#include "parser.h"

int compiler::compile_file(char* s)
{
	scanner_token *token;
	Lexer *state;
	void* pParser = ParseAlloc(malloc);

	clear();

	ParseTrace(stdout, ">>");

	state = new Lexer();
	state->init(s);

	for(;;) {
		token = state->scan();
		if(token == NULL) break;
		Parse(pParser, token->kind, token, this);
	}

	Parse(pParser, 0, 0, this);
	ParseFree(pParser, free);

	if(errormsg != NULL)
		return 0;
	else
		return 1;
}
void compiler::clear()
{
	errormsg = NULL;
}
void compiler::error(char *errmsg)
{
	errormsg = errmsg;
}