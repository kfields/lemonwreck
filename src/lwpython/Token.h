#ifndef _TOKEN_H
#define _TOKEN_H

#include "parserx.h" //include kinds

struct scanner_token {
	int kind;
	int line;
	int column;
	union {
		float num;
		char* str;
	} data;
};

#endif //_TOKEN_H
