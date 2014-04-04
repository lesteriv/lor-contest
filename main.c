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

#define nelem(n) (sizeof(n) / sizeof((n)[0]))

/* rules: https://www.linux.org.ru/forum/development/10349962?cid=10352344 */

struct test {
	char *string;
	char *target;
	char *needle;
} *tc, testcases[] = {
	{ "debug", "", "debug" },
	{ "debugfs", "debugfs", "debug" },
	{ "debug=1", "debug=1", "debug" },
	{ "systemd.debug", "systemd.debug", "debug" },
	{ "debug 123 debug 456", "123 456", "debug" },
	{ "debug debugfs debug debug=1 systemd.debug debug", "debugfs debug=1 systemd.debug", "debug" },
	{ NULL }
};

int rounds = 1000;
int passes = 1000;

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
	int needsfree;
	double time;
	double grostime;
	int passed;
}   *p, part[] = {
	{ .name = "beastie cutout", .f = &cutout },
	{ .name = "beastie undebug", .f = &undebug },
//	{ .name = "beastie split", .f = &split },
	{ .name = "Eddy_Em", .f = &delsubstr },
//	{ .name = "Eddy_Em", .f = &_remove }, /* never returns */
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

char *passstat[] = {"fail", "pass"};
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
go(struct part *p, char *s, char *n)
{
	char *o;

	/* prepare a copy of test string for clobber functions */
	if (p->clob)
		s = strdup(s);

	/* fire! */
	o = p->f(s, n);

	if (p->clob)
		free(s);

	/* free internal allocated space */
	if (p->needsfree)
		free(o);
}

void
prepare(struct part *p, struct test *test)
{
	char *s, *t, *o;

	s = strdup(test->string);
	t = strdup(test->target);
	o = p->f(s, test->needle);

	/* returns another pointer as passed, requiers free */
	p->needsfree = o != s;

	/* check input clobber */
	p->clob = !!strcmp(s, test->string);

	/* remove whitespaces from output for compare */
	p->pass = !strcmp(strip(o), strip(t));
	p->passed += p->pass;

	free(s);
	free(t);
	if (p->needsfree)
		free(o);
}

void
runtest(struct part *p, struct test *t)
{
	struct timeval begin, end;
	int i, k;

	prepare(p, t);

	fprintf(stderr, "%16s ", p->name);
	p->time = 0.0;
	for (k = 0; k < passes; k++) {
		if (60 / (k + 1))
			fprintf(stderr, ".");
		gettimeofday(&begin, NULL);
		for (i = 0; i < rounds; i++)
			go(p, t->string, t->needle);
		gettimeofday(&end, NULL);
		p->time += (end.tv_sec - begin.tv_sec) * 1000.0;
		p->time += (end.tv_usec - begin.tv_usec) / 1000.0;
	}
	/* average time */
	p->time /= passes;
	p->grostime += p->time;
	fprintf(stderr, "%5s%9.2f ms\n", passstat[p->pass], p->time);
}

void
result(struct part *p)
{
	printf("\nGros Relults\n----\n\n");
	printf("%-16s| %-12s| %-12s\n", "name", "tests passed", "gros time");
	printf("%-16s| %-12s| %-12s\n", "---", "---", "---");
	for (; p->name != NULL; p++)
		printf("%-16s|%9.2f %% |%8.2f ms\n",
		    p->name, 100.0 * p->passed / (nelem(testcases) - 1),
		    p->grostime);
}

int
main(int argc, char **argv)
{
	int i;

	for (tc = testcases; tc->string; tc++) {
		fprintf(stderr, "\n%16s \"%s\"\n", "input", tc->string);
		for (p = part; p->name != NULL; p++)
			runtest(p, tc);
	}

	result(part);

	return 0;
}
