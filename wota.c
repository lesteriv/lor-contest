/*
 * Copyright (c) 2014 wota
 *
 * https://www.linux.org.ru/forum/development/10349962?cid=10350284
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void 
strremove(char *s, const char *t)
{
	size_t l = strlen(t);
	char *d = s;

	do
		while (!strncmp(s, t, l))
			s += l;
	while ((*d++ = *s++));
}

char *
strremove_wrapper(char *hay, char *needle)
{
	strremove(hay, needle);

	return hay;
}

void 
remove_word(char *s, const char *w)
{
	int l = strlen(w);
	char *p = s;

	while ((p = strstr(p, w))) {
		if ((p == s || isspace(p[-1])) && (!p[l] || isspace(p[l])))
			memset(p, ' ', l);

		p += l;
	}
}

char *
remove_word_wrapper(char *hay, char *needle)
{
	remove_word(hay, needle);

	return hay;
}
