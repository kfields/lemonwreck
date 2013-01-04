#pragma once

#include "TokenFilter.h"

class PythonTokenFilter : public TokenFilter
{
public:
	PythonTokenFilter(TokenStream &in);
	~PythonTokenFilter(void);
};
