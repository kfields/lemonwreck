#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "token.h"
#include "calculator.h"
#include "scanner.h"
#include "parser.h"

scanner_token *eval_ast(calculator* calc, ast_node* ast)
{
	switch(ast->kind){
		case AST_LITERAL:
			return ast->token;
			break;
		case AST_BINARY:
			switch(ast->token->kind){
		case TOKEN_ADD:
			return add(calc, eval_ast(calc, ast->node.binary.left), eval_ast(calc, ast->node.binary.right));
		case TOKEN_SUB:
			return subtract(calc, eval_ast(calc, ast->node.binary.left), eval_ast(calc, ast->node.binary.right));
		case TOKEN_MUL:
			return multiply(calc, eval_ast(calc, ast->node.binary.left), eval_ast(calc, ast->node.binary.right));
		case TOKEN_DIV:
			return divide(calc, eval_ast(calc, ast->node.binary.left), eval_ast(calc, ast->node.binary.right));
			}
	}
	return NULL;
}

int eval_string(calculator* calc, char* s)
{
	scanner_token *token;
	scanner_state *state;
	void* pParser = ParseAlloc(malloc);

	clear(calc);

	//ParseTrace(stdout, ">>");

	state = malloc(sizeof(scanner_state));

	state->cursor = s;

	for(;;) {
		token = scan(state);
		if(token == NULL) break;
		Parse(pParser, token->kind, token, calc);
	}
	Parse(pParser, 0, 0, calc);
	ParseFree(pParser, free);

	calc->answer = eval_ast(calc, calc->ast)->data.num;

	if(calc->errormsg != NULL)
		return 0;
	else
		return 1;
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
