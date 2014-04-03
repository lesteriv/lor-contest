/*
 * Copyright (c) 2014 qulinxao
 *
 * https://www.linux.org.ru/forum/development/10349962?cid=10351023
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

inline char*nxt(char* s){while(isalpha(*++s));return s;}

//fill space in memory
char*
wordstrips(char *src, char * needle)
{
        if(!*needle)return src;
        int n=strlen(needle);
        char *l=src-1,*r;
        do{
                r=nxt(l);
                if(r-++l!=n)continue;
                if(strncmp(l,needle,n))continue;
                while(l<r)*l++=' ';
        }while(*(l=r));
        return src;
}

void
test(char *s,char *ndl)
{
        char *res = (char*)malloc(1+strlen(s));
        printf( "from:%s\n  to:%s\n",s,wordstrips(strcpy(res,s),ndl));
        free(res);
}
