#ifndef _SCANNER_H
#define _SCANNER_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token.h"

typedef char scanchar_t;

class Lexer {
public:
	//int fd; //file descriptor
	FILE *file;
	int line;
	int column;
	//
	scanchar_t buffer[BUFSIZ]; //fill buffer
	scanchar_t cbuffer[BUFSIZ]; //capture buffer
	scanchar_t* cursor;
	scanchar_t* ccursor;
	scanchar_t* bot;
	scanchar_t* lim;
	scanchar_t* ptr;
	scanchar_t* pos;
	scanchar_t* top;
	scanchar_t* marker;
	scanchar_t* eof;
	//
	void init(const char *filename);
	scanner_token *scan();
	void fill();

	scanner_token* emit_newline();

	scanner_token* create_token(int kind);
	scanner_token* create_name_token(char* value);
	scanner_token* create_int_token(int value);
	scanner_token* create_float_token(float value);

	void capture_begin();
	void capture();
	scanchar_t *capture_string();
	int capture_int();
	float capture_float();
};

#endif
