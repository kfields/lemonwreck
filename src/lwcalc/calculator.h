#ifndef _CALCULATOR_H
#define _CALCULATOR_H

typedef struct _calculator {
	float answer;
} calculator;

scanner_token* set_int(calculator* pCalc, scanner_token* B);
scanner_token* set_float(calculator* pCalc, scanner_token* B);
scanner_token* add(calculator* pCalc, scanner_token* B, scanner_token* C);
scanner_token* subtract(calculator* pCalc, scanner_token* B, scanner_token* C);
scanner_token* multiply(calculator* pCalc, scanner_token* B, scanner_token* C);
scanner_token* divide(calculator* pCalc, scanner_token* B, scanner_token* C);

#endif //_CALCULATOR_H
