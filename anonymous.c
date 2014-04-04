/*
 * Copyright (c) 2014 anonymous
 *
 * https://www.linux.org.ru/forum/development/10349962?cid=10352219
 */

#include <string.h>

void 
strcut(char *where, const char *what)
{
	size_t whatlen = strlen(what);
	char *p, *prevp = NULL, *end = where + strlen(where);
	for (p = where, where = prevp; (p = strstr(p, what)); where += p - prevp, p += whatlen, prevp = p)
		if (prevp)
			memmove(where, prevp, p - prevp);
	if (prevp)
		memmove(where, prevp, end - prevp + 1);
}

char *
strcut_wrapper(char *hay, char *needle)
{
	strcut(hay, needle);

	return hay;
}
