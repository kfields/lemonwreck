#include "scanner.h"
#include "malloc.h"

void capture_begin(scanner_state *state)
{
	state->ccursor = state->cursor;
}
void capture(scanner_state *state)
{
	size_t len = state->cursor - state->ccursor;
	memcpy(state->cbuffer, state->ccursor, len);
	state->cbuffer[len] = '\0';
	capture_begin(state);
}
char *capture_string(scanner_state *state)
{
	size_t len = state->cursor - state->ccursor;
	char* str = (char*)malloc(len + 1);
	memcpy(str, state->ccursor, len);
	str[len] = '\0';
	capture_begin(state);
	return str;
}
int capture_int(scanner_state *state)
{
	capture(state);
	return atoi(state->cbuffer);
}
float capture_float(scanner_state *state)
{
	capture(state);
	return (float)atof(state->cbuffer);
}