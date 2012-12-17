#ifndef _TOKEN_H
#define _TOKEN_H

#include "parserx.h" //include kinds

typedef struct _scanner_token {
	int kind;
	union {
		int n_int;
		float n_float;
		char* str;
	} data;
} scanner_token;

scanner_token* create_token(int kind);
scanner_token* create_int_token(int value);
scanner_token* create_float_token(float value);

#endif //_TOKEN_H
