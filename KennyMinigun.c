/*
 * Copyright (c) 2014 KennyMinigun
 *
 * https://www.linux.org.ru/forum/development/10349962?cid=10350668
 */

#include <string.h>
#include <assert.h>

static char *
strdel(const char *needle, char *haystack)
{
	const size_t n_length = strlen(needle);
	const size_t h_length = strlen(haystack);
	size_t i, j;

	assert(needle);
	assert(haystack);

	if (n_length == 0)
		return haystack;

	for (i = 0, j = 0; i < h_length; i++) {
		if (haystack[i] == needle[0] && strncmp(&haystack[i], needle, n_length) == 0) {
			i += n_length;
			/* shift iterator position forward */
		} else {
			haystack[j] = haystack[i];
			/* copy symbol to non - shifted position(backwards) */
			j++;
		}
	}
	haystack[j] = '\0';
	/* FINISH HIM ! */

	return haystack;
}

char *
strdel_wrapper(char *hey, char *needle)
{
	return strdel(needle, hey);
}
