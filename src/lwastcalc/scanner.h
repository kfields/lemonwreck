//--------------------------------------------------------- ./scanner.h

#ifndef _SCANNER_H
#define _SCANNER_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token.h"

typedef struct _scanner_state {
	char buffer[BUFSIZ]; //fill buffer
	char cbuffer[BUFSIZ]; //capture buffer
	char* cursor;	//scan cursor
	char* ccursor;	//capture cursor
	char* limit;
	char* marker;
} scanner_state;

scanner_token *scan(scanner_state *state);

void capture_begin(scanner_state *state);
void capture(scanner_state *state);
char *capture_string(scanner_state *state);
int capture_int(scanner_state *state);
float capture_float(scanner_state *state);

#endif
