#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include "ast.h"

typedef struct _calculator {
	ast_node *ast;
	float answer;
	char* errormsg;
} calculator;

void clear(calculator* calc);
int eval_string(calculator* calc, char* s);
void error(calculator *calc, char *errmsg);

scanner_token* add(calculator* calc, scanner_token* B, scanner_token* C);
scanner_token* subtract(calculator* calc, scanner_token* B, scanner_token* C);
scanner_token* multiply(calculator* calc, scanner_token* B, scanner_token* C);
scanner_token* divide(calculator* calc, scanner_token* B, scanner_token* C);

#endif //_CALCULATOR_H
