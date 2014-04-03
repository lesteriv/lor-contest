/*
 * Copyright (c) 2014 Eddy_Em
 *
 * https://www.linux.org.ru/forum/development/10349962?cid=10350151
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *delsubstr(char *strin, char *substr){
  size_t sl = strlen(substr), ol = strlen(strin);
  char *strout = NULL, *iptr, *optr, *eptr;
  if(sl > ol) return strdup(strin);
  strout = strdup(strin);
  if(!strout) return NULL;
  optr = strout; eptr = strout + ol;
  do{
    iptr = strstr(optr, substr);
    if(!iptr) break;
    optr = iptr;
    iptr += sl;
    if(iptr >= eptr) break;
    ol = strlen(iptr) + 1;
    memmove(optr, iptr, ol);
  }while(1);
  optr = strdup(strout);
  free(strout);
  return optr;
}

char * _remove(char * string, char * needl) {
  char * next = string;
  while((next = strstr(next, needl)))
    strcpy(next, next + strlen(needl) + 1);
  return string;
}
