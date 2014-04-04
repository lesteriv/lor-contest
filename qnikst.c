#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
undebugq(char *in, char *needle)
{
	char *p = in;
	size_t l = 0, nl = strlen(needle);

	for (; *p;) {
		for (; *p == ' '; p++);
		if (*p == *needle) {
			if (!strncmp(p, needle, nl)) {
				//if (!l)
				l = strlen(p);
				if (p[nl] == ' ') {
					memmove(p, p + nl + 1, l - nl + 1);	// we need to copy \0
					continue;
				} else if (p[nl] == '\0') {
					*p = '\0';
					return in;
				} else if (l < nl) {
					return in;
				}
				//p += nl;
			}
		}
		for (; *p != ' ' && *p; p++);
		//for (; ! (*p == ' ' || *p == '\t') && *p; p++);
	}
	return in;
}
