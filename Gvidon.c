/*
 * Copyright (c) 2014 Gvidon
 *
 * https://www.linux.org.ru/forum/development/10349962?cid=10350155
 */
 
#include <string.h>

void process(const char *str, const char *substr, char *buffer, size_t bufferSize)
{
    char *ptr = buffer;
    size_t substrLength = strlen(substr);

    while (*str && (ptr - buffer < bufferSize - 1))
    {
        if (!strncmp(str, substr, substrLength))
            str += substrLength;
        *ptr++ = *str++;
    }
    *ptr = '\0';
}

char *
process_wrapper(char *hay, char *needle)
{
	char buffer[512];

	process(hay, needle, buffer, sizeof(buffer));
	memcpy(hay, buffer, strlen(hay));

	return hay;
}
