/*
 * Copyright (c) 2014 nokachi
 *
 * https://www.linux.org.ru/forum/development/10349962?cid=10350815
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_string(const char *haystack, char *needle) {
  int n = strlen(needle);
  char *result = malloc(1+strlen(haystack));
  memset(result, 0, 1+strlen(haystack));

  int state = -1; // will be from 0 to strlen(needle)-1
  int i=0; // writing output
  
  for (; *haystack; haystack++) {
    if (*haystack == needle[state+1]) {
      state++;
      if (state == n-1) {
        state = -1;
        continue;
      }
    }
    else if (state == -1) {
      result[i++] = *haystack;
    }
    else {
      // dump the (state + 1) chars to the result
      memcpy(result+i, needle, state+1);
      i += state+1;
      state = -1;
    }
  }
  result[i] = '\0';
  return result;
}

char *remove_string_2(const char *haystack, const char *needle) {
  int n = strlen(needle);
  char *result = malloc(1+strlen(haystack));
  memset(result, 0, 1+strlen(haystack));

  int state = -1; // will be from 0 to strlen(needle)-1
  int i=0; // writing output

  char prev = ' ';
  
  for (; *haystack; prev=*haystack, haystack++) {
    if (*haystack == needle[state+1]) {
      if (state == -1 && prev != ' ') {
        result[i++] = *haystack;
        continue;
      }

      state++;
      if (state == n-1) {
        state = -1;
        if (!*(haystack+1) ||
            *(haystack+1)==' ')
          continue;
        else {
          memcpy(result+i, needle, n);
          i += n;
        }
      }
    }
    else if (state == -1) {
      result[i++] = *haystack;
    }
    else {
      // dump the (state + 1) chars to the result
      memcpy(result+i, needle, state+1);
      i += state+1;
      state = -1;
    }
  }
  result[i] = '\0';
  return result;
}
