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
#include <unistd.h>

/* rules: https://www.linux.org.ru/forum/development/10349962?cid=10352344 */

char *string = "debug debugfs debug debug=1 systemd.debug debug";
char *target = "debugfs debug=1 systemd.debug";
char *needle = "debug";
int rounds = 100000;
int passes = 100;

char *cutout(char *, char *);
char *undebug(char *, char *);
char *split(char *, char *);
char *delsubstr(char *, char *);
char *_remove(char *, char *);
char *process_wrapper(char *, char *);
char *strdel_wrapper(char *, char *);
char *remove_string(char *, char *);
char *remove_string_2(char *, char *);
char *wordstrips(char *, char *);
char *cut(char *, char *);
char *cut2(char *, char *);
char *strremove_wrapper(char *, char *);
char *remove_word_wrapper(char *, char *);
char *strcut_wrapper(char *, char *);

struct part {
	char *name;
	char *(*f) (char *, char *);
	int pass;
	int clob;
	double time;
	int needsfree;
	char *output;
}   *p, part[] = {
	{ .name = "beastie cutout", .f = &cutout },
	{ .name = "beastie undebug", .f = &undebug },
	{ .name = "beastie split", .f = &split },
	{ .name = "Eddy_Em", .f = &delsubstr },
#if 0				/* never returns */
	{ .name = "Eddy_Em", .f = &_remove },
#endif
	{ .name = "Gvidon", .f = &process_wrapper },
	{ .name = "KennyMinigun", .f = &strdel_wrapper },
	{ .name = "nokachi", .f = &remove_string },
	{ .name = "qulinxao", .f = &wordstrips },
	{ .name = "true_admin", .f = &cut },
	{ .name = "true_admin 2", .f = &cut2 },
	{ .name = "wota", .f = &strremove_wrapper },
	{ .name = "wota whiteout", .f = &remove_word_wrapper },
	{ .name = "anonymous", .f = &strcut_wrapper },
	{ NULL },
};

char *passstat[] = {"fails", "passes"};
char *clobstat[] = {"xerox", "clobber"};
char *freestat[] = {"no alloc", "needs free"};

/* strip whitespaces */
char *
strip(char *s)
{
	char *r, *p;

	r = p = s;
	while (*s && *p) {
		if (*p == ' ')
			p++;
		else
			*s++ = *p++;
	}
	*s = '\0';

	return r;
}


void
go(struct part *p, char *s)
{
	char *o;

	/* prepare a copy of test string for clobber functions */
	if (p->clob)
		s = strdup(s);

	/* fire! */
	o = p->f(s, needle);

	if (p->clob)
		free(s);

	/* free internal allocated space */
	if (p->needsfree)
		free(o);
}

void
prepare(struct part *p)
{
	char *s, *t, *o;

	s = strdup(string);
	t = strdup(target);
	o = p->f(s, needle);
	p->output = strdup(o);

	/* returns another pointer as passed, requiers free */
	p->needsfree = o != s;

	/* check input clobber */
	p->clob = !!strcmp(s, string);

	/* remove whitespaces from output for compare */
	p->pass = !strcmp(strip(o), strip(t));
	p->time = 0.0;

	/* free internal allocated space */
	if (p->needsfree)
		free(o);

	free(s);
	free(t);
}

void
usage()
{
	extern char *__progname;
	fprintf(stderr, "usage: %s [-s <string>] [-t <taget>] [-n <needle>] [-p passess] [-r <rounds>] [-h]\n",
	    __progname);
	exit(1);
}

int
main(int argc, char **argv)
{
	struct timeval begin, end;
	int k, i, ch;
	double minimal = 1000000.0;
	int initonly = 0;

	while ((ch = getopt(argc, argv, "s:t:n:p:r:ih")) != -1)
		switch (ch) {
		case 's':
			string = strdup(optarg);
			break;
		case 't':
			target = strdup(optarg);
			break;
		case 'n':
			needle = strdup(optarg);
			break;
		case 'p':
			passes = atoi(optarg);
			break;
		case 'r':
			rounds = atoi(optarg);
			break;
		case 'i':
			initonly = 1;
			break;
		case 'h':
		default:
			usage();
		}

	/* initialize */
	for (p = part; p->name != NULL; p++)
		prepare(p);

	if (initonly)
		return 0;

	printf("input  \"%s\"\n", string);
	printf("expect \"%s\"\n", target);

	for (p = part; p->name != NULL; p++) {
		printf("%-16s%-8s\"%s\"\n", p->name, passstat[p->pass], p->output);

		p->time = 0.0;
		for (k = 0; k < passes; k++) {
			gettimeofday(&begin, NULL);
			for (i = 0; i < rounds; i++)
				go(p, string);
			gettimeofday(&end, NULL);
			p->time += (end.tv_sec - begin.tv_sec) * 1000.0;
			p->time += (end.tv_usec - begin.tv_usec) / 1000.0;
		}
		/* average time */
		p->time /= passes;
		if (p->pass && p->time < minimal)
			minimal = p->time;
	}

	for (p = part; p->name != NULL; p++) {
		/* results */
		printf("%-16s%10.2f ms%7s%10.1f %% slower than best\n",
		    p->name, p->time,
		    passstat[p->pass],
		    100.0 * (p->time - minimal) / minimal);


		free(p->output);
	}

	return 0;
}
