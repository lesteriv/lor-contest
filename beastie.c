/*
 * Copyright (c) 2014 Dimitri Sokolyuk <demon@dim13.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
cutout(char *hay, char *needle)
{
	char *p, *s = hay;
	int match;

	while ((p = strchr(s, ' ')) != NULL) {
		*p = '\0';
		match = strcmp(s, needle);
		*p = ' ';

		if (match)
			s = p + 1;
		else
			memmove(s, p + 1, strlen(p));
	}

	do {
		*s-- = '\0';
	} while (*s == ' ');

	return hay;
}
/*
 * "debug" => ""
 * "debugfs" => "debugfs"
 * "debug=1" => "debug=1"
 * "debug systemd.debug" => " systemd.debug"
 * "debug 123 debug 456" => " 123 456"
 */

char *
undebug(char *hay, char *needle)
{
	char *n, *s = hay;
	size_t len = strlen(needle);
	char *end = strchr(hay, '\0');

	while ((s = strstr(s, needle)) != NULL) {
		n = s + len;
		if ((*n == '\0' || *n++ == ' ') && (s == hay || *(s - 1) == ' '))
			memmove(s, n, end - n + 1);
		else
			s = n;
	}

	return hay;
}

char *
split(char *hay, char *needle)
{
	char *p, *s = strdup(hay);
	size_t len = strlen(hay);
	int first = 1;

	while ((p = strsep(&s, " ")) != NULL) {
		if (strcmp(p, needle) != 0) {
			if (first) {
				first = 0;
				strncpy(hay, p, len);
			} else {
				strncat(hay, " ", len);
				strncat(hay, p, len);
			}
		}
	}

	free(s);

	return hay;
}
