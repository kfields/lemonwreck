#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "scanner.h"
#include "parser.h"
#include "calculator.h"

int eval_string(calculator* calc, char* s)
{
	scanner_token *token;
	scanner_state *state;

	void* pParser = ParseAlloc(malloc);
	ParseTrace(stdout, ">>");

	state = malloc(sizeof(scanner_state));

	state->cursor = s;

	for(;;) {
		token = scan(state);
		if(token == NULL) break;
		Parse(pParser, token->kind, token, calc);
	}
	Parse(pParser, 0, 0, calc);
	ParseFree(pParser, free);
	return 0;
}
void error(calculator *calc, char *errmsg)
{
	calc->errormsg = errmsg;
}
void clear(calculator* calc)
{
	calc->answer = 0;
	calc->errormsg = NULL;
}
scanner_token* add(calculator* calc, scanner_token* b, scanner_token* c)
{
	return create_float_token(b->data.num + c->data.num);
}
scanner_token* subtract(calculator* calc, scanner_token* b, scanner_token* c)
{
	return create_float_token(b->data.num - c->data.num);
}
scanner_token* multiply(calculator* calc, scanner_token* b, scanner_token* c)
{
	return create_float_token(b->data.num * c->data.num);
}
scanner_token* divide(calculator* calc, scanner_token* b, scanner_token* c)
{
	if(c->data.num == 0){
		error(calc, "Division by zero");
		return create_float_token(0);
	}
	else
		return create_float_token(b->data.num / c->data.num);
}
