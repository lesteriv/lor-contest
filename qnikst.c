// Copyright: 2014 (C) Alexander Vershilov
// License:   MIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strmatch(char *p, const char *n) {
    for (;*n != '\0';n++,p++) {
        if (*p != *n) return NULL;
    }
    return p;
}

char *
undebugq(char *in, char *needle)
{
	char *p = in;
    char *eoi = NULL, // pointer to the end of input
         *pt = NULL;  // temporary pointer

	do {
        if ((pt = strmatch(p, needle)) != NULL) {
            if (*pt == ' ') {
               if (!eoi) eoi = pt + strlen(pt);
               memmove(p, pt + 1, eoi - pt + 1);	// we need to copy \0
               eoi -= pt - p;
               continue;
            } 
            if (*pt == '\0') {
                *p = '\0';
                return in;
            }
            p = pt;
        }
        p = strchr(p, ' ');
    } while (p && p++);
	return in;
}
