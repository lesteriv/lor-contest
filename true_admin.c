/*
 * Copyright (c) 2014 true_admin
 *
 * https://www.linux.org.ru/forum/development/10349962?cid=10350190
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* cut(char *src, char *what) {
  char *sub, *dst = malloc(strlen(src)+1), *result = dst;
  assert(dst);
  size_t wtflen = strlen(what);

  while (*src) {
    sub = strstr(src, what);
    while(src != sub && (*dst++ = *src++));
    if (src == sub) {
      src = sub + wtflen;
      continue; }
  } 
  return result;
}

char* cut2(char *src, char *what) {
  char *sub, *dst = malloc(strlen(src)+1), *result = dst; assert(dst);

  while (*src) {
    while(src != strstr(src, what) && (*dst++ = *src++));
    if (*src)
      src = src + strlen(what);
  } 
  return result;
}
