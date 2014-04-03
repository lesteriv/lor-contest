/*
 * Copyright (c) 2014 wota
 *
 * https://www.linux.org.ru/forum/development/10349962?cid=10350284
 */

#include <stdio.h>
#include <string.h>

void strremove( char* s, const char* t )
{
    size_t l = strlen( t );
    char *d = s;
	
    do while( !strncmp( s, t, l ) ) s += l;
    while( *d++ = *s++ );
}

char *
strremove_wrapper(char *hay, char *needle)
{
	strremove(hay, needle);

	return hay;
}
