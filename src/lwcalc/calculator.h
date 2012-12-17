#ifndef _CALCULATOR_H
#define _CALCULATOR_H

typedef struct _calculator {
	float answer;
	char* errormsg;
} calculator;

int eval_string(calculator* calc, char* s);
void error(calculator *calc, char *errmsg);

scanner_token* add(calculator* calc, scanner_token* B, scanner_token* C);
scanner_token* subtract(calculator* calc, scanner_token* B, scanner_token* C);
scanner_token* multiply(calculator* calc, scanner_token* B, scanner_token* C);
scanner_token* divide(calculator* calc, scanner_token* B, scanner_token* C);

#endif //_CALCULATOR_H
