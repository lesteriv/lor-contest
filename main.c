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

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[] = "BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug";
char target[] = "BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro";
char needle[] = "debug";

char *passstat[] = {"fails", "pass"};
char *clobstat[] = {"", "clobbes input"};
char *freestat[] = {"", "has memory leaks"};

char *cutout(char *, char *);		// bestie
char *delsubstr(char *, char *);	// Eddy_Em
char *_remove(char *, char *);		// Eddy_Em
char *process_wrapper(char *, char *);	// Gvidon
char *strdel_wrapper(char *, char *);	// KennyMinigun
char *remove_string(char *, char *);	// nokachi
char *remove_string_2(char *, char *);	// nokachi
char *wordstrips(char *, char *);	// qulinxao
char *cut(char *, char *);		// true_admin
char *cut2(char *, char *);		// true_admin
char *strremove_wrapper(char *, char *);// wota

struct part {
	char *name;
	char *(*f)(char *, char *);
	int pass;
	int clob;
	double time;
	int needsfree;
} *p, part[] = {
	{ .name = "beastie",		.f = &cutout },
	{ .name = "Eddy_Em",		.f = &delsubstr },
//	{ .name = "Eddy_Em",		.f = &_remove },	// never returns
	{ .name = "Gvidon",		.f = &process_wrapper },
	{ .name = "KennyMinigun",	.f = &strdel_wrapper },
	{ .name = "nokachi #1"	,	.f = &remove_string },
	{ .name = "nokachi #2",		.f = &remove_string_2 },
	{ .name = "qulinxao",		.f = &wordstrips },
	{ .name = "true_admin #1",	.f = &cut },
	{ .name = "true_admin #2",	.f = &cut2 },
	{ .name = "wota",		.f = &strremove_wrapper },
	{ NULL },
};

void
strip(char *s)
{
	char *p = s; 

	while (*s && *p) {
		if (*p == ' ')
			p++;
		else
			*s++ = *p++;
	}

	*s = '\0';
}


void
go(struct part *p, char *s)
{
	char *o;
	
	if (p->clob)
		s = strdup(s);
	o = p->f(s, needle);
	if (p->clob)
		free(s);
	if (p->needsfree)
		free(o);
}

void
prepare(struct part *p)
{
	char *s, *o;

	s = strdup(string);
	o = p->f(s, needle);

	p->needsfree = o != s;

	p->clob = !!strcmp(s, string);

	strip(o);
	p->pass = !strcmp(o, target);

	free(s);
}

int
main()
{
	struct timeval begin, end;
	int i, rounds = 1000000;

	strip(target);

	for (p = part; p->name != NULL; p++) {

		prepare(p);

		gettimeofday(&begin, NULL);
		for (i = 0; i < rounds; i++)
			go(p, string);
		gettimeofday(&end, NULL);
		p->time = (end.tv_sec - begin.tv_sec) * 1000.0;
		p->time += (end.tv_usec - begin.tv_usec) / 1000.0;
		
		printf("%16s%7s%16s%20s%10.2f ms\n",
				p->name,
				passstat[p->pass],
				clobstat[p->clob],
				freestat[p->needsfree],
				p->time);
	}

	return 0;
}
