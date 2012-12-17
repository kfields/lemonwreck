#include "malloc.h"
#include "token.h"
#include "calculator.h"

#ifdef _MSC_VER
#define INFINITY (DBL_MAX+DBL_MAX)
#define NAN (INFINITY-INFINITY)
#endif

void clear(calculator* pCalc){
	pCalc->answer = 0;
}
scanner_token* set_int(calculator* pCalc, scanner_token* B){
	scanner_token* A;
	pCalc->answer = B->data.n_int;
	A = create_float_token(pCalc->answer);
	return A;
}
scanner_token* set_float(calculator* pCalc, scanner_token* B){
	pCalc->answer = B->data.n_float;
	return B;
}
scanner_token* add(calculator* pCalc, scanner_token* B, scanner_token* C) {
	scanner_token* A;
	pCalc->answer = B->data.n_float + C->data.n_float;
	A = create_float_token(pCalc->answer);
	return A;
}
scanner_token* subtract(calculator* pCalc, scanner_token* B, scanner_token* C) {
	scanner_token* A;
	pCalc->answer = B->data.n_float - C->data.n_float;
	A = create_float_token(pCalc->answer);
	return A;
}
scanner_token* multiply(calculator* pCalc, scanner_token* B, scanner_token* C) {
	scanner_token* A;
	pCalc->answer = B->data.n_float * C->data.n_float;
	A = create_float_token(pCalc->answer);
	return A;
}
scanner_token* divide(calculator* pCalc, scanner_token* B, scanner_token* C) {
	scanner_token* A;
	pCalc->answer = B->data.n_float / C->data.n_float;
	A = create_float_token(pCalc->answer);
	return A;
}
