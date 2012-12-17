#include "malloc.h"
#include "token.h"
#include "parserx.h"

scanner_token* create_token(int kind) {
	scanner_token* token = malloc(sizeof(scanner_token));
	token->kind = kind;
	return token;
}
scanner_token* create_int_token(int value) {
	scanner_token* token = malloc(sizeof(scanner_token));
	token->kind = TOKEN_INTEGER;
	token->data.n_int = value;
	return token;
}
scanner_token* create_float_token(float value) {
	scanner_token* token = malloc(sizeof(scanner_token));
	token->kind = TOKEN_FLOAT;
	token->data.n_float = value;
	return token;
}