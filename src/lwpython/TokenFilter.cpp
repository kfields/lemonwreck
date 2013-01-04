#include "TokenFilter.h"

TokenFilter::TokenFilter(TokenStream &in)
{
	input = &in;
}

TokenFilter::~TokenFilter(void)
{
}
