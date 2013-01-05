#pragma once

#include "Token.h"

class TokenStream
{
public:
	TokenStream(void);
	~TokenStream(void);
	virtual Token *read() = 0;
};
