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
	for (p = where, where = prevp; (p = strstr(p, what));
	    where += p - prevp, p += whatlen, prevp = p)
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

char *
anon_strcut(char *where, char *what)
{
	char *dst = where, *p = where, prev;
	for (prev = ' '; *p; prev = *p++)
		if (prev == ' ') {
			char *s1 = p, *s2 = what;
			while (*s2 && *s1 == *s2) {
				++s1;
				++s2;
			}
			if (!(*s2 || (*s1 != ' ' && *s1)))
				p = s1 - 1;
			else
				*dst++ = *p;
		} else
			*dst++ = *p;
	*dst = 0;
	return where;
}
