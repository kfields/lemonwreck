#ifndef _TOKEN_H
#define _TOKEN_H

#include "ParserX.h" //include kinds

struct Token {
	int kind;
	int line;
	int column;
	union {
		float num;
		char* str;
	} data;
	//
	Token(int kind){
		this->kind = kind;
	}
};

#endif //_TOKEN_H
