#pragma once

#include "TokenStream.h"

class TokenFilter : public TokenStream
{
public:
	TokenStream *input;
	//
	TokenFilter(TokenStream &in);
	~TokenFilter(void);
};
