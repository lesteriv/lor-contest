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

/* rules: https://www.linux.org.ru/forum/development/10349962?cid=10352344 */

struct test {
	char *string;
	char *target;
	char *needle;
} testcases[] = {
	{ "debug", "", "debug" },
	{ "debugfs", "debugfs", "debug" },
	{ "debug=1", "debug=1", "debug" },
	{ "systemd.debug", "systemd.debug", "debug" },
	{ "debug 123 debug 456", "123 456", "debug" },
	{ "debug debugfs debug debug=1 systemd.debug debug", "debugfs debug=1 systemd.debug", "debug" },
	{ "debu", "debu", "debug" },
	{ "BOOT_IMAGE=/debug/vmlinuz-3.2.0-debug-amd64 debug=UUID=42debug5-6ee1-464c-bc41-debug42debug ro debug",
	  "BOOT_IMAGE=/debug/vmlinuz-3.2.0-debug-amd64 debug=UUID=42debug5-6ee1-464c-bc41-debug42debug ro", "debug" },
	{ "BOOT_IMAGE=/debug/vmlinuz-3.2.0-debug-amd64 dolvm debug debug=UUID=42debug5-6ee1-464c-bc41-debug42debug debug ro",
	  "BOOT_IMAGE=/debug/vmlinuz-3.2.0-debug-amd64 dolvm debug=UUID=42debug5-6ee1-464c-bc41-debug42debug ro", "debug" },
	{ NULL }
};

int rounds = 500000;
int passes = 20;

char *nop(char *, char *);
char *cutout(char *, char *);
char *cutout_orig(char *, char *);
char *undebug(char *, char *);
char *split(char *, char *);
char *delsubstr(char *, char *);
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
char *str_drop_str(char *, char *);
char *undebugq(char *, char *);
char *strcutm(char *, char *);
char *carb_wrapper(char *, char *);
char *anon_strcut(char *, char *);

struct part {
	char *name;
	char *(*f) (char *, char *);
	char *fname;
	int pass;
	double time;
	double grostime;
	int passed;
} part[] = {
	{ .name = "anonymous", .fname = "nop", .f = &nop },
	{ .name = "beastie", .fname = "cutout", .f = &cutout },
	{ .name = "beastie", .fname = "cutout_orig", .f = &cutout_orig },
	{ .name = "beastie", .fname = "undebug", .f = &undebug },
	{ .name = "beastie", .fname = "split", .f = &split },
	{ .name = "Eddy_Em", .fname = "delsubstr", .f = &delsubstr },
	{ .name = "Gvidon", .fname = "process", .f = &process_wrapper },
	{ .name = "KennyMinigun", .fname = "strdel", .f = &strdel_wrapper },
	{ .name = "nokachi", .fname = "remove", .f = &remove_string },
	{ .name = "qulinxao", .fname = "wordstrings", .f = &wordstrips },
	{ .name = "true_admin", .fname = "cut", .f = &cut },
	{ .name = "true_admin", .fname = "cut2", .f = &cut2 },
	{ .name = "wota", .fname = "strremove", .f = &strremove_wrapper },
	{ .name = "wota", .fname = "remove_word", .f = &remove_word_wrapper },
	{ .name = "anonymous", .fname = "strcut", .f = &strcut_wrapper },
	{ .name = "anonymous", .fname = "anon_strcut", .f = &anon_strcut},
	{ .name = "puzan", .fname = "str_drop_str", .f = &str_drop_str },
	{ .name = "qnikst", .fname = "undebugq", .f = &undebugq },
	{ .name = "mix-mix", .fname = "strcut", .f = &strcutm },
	{ .name = "Carb", .fname = "debugdel", .f = &carb_wrapper },
	{ NULL },
};

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

	s = strdup(s);

	/* fire! */
	o = p->f(s, n);

	/* free internal allocated space */
	if (o != s)
		free(o);

	free(s);
}

void
prepare(struct part *p, struct test *test)
{
	char *s, *t, *o;

	s = strdup(test->string);
	t = strdup(test->target);
	o = p->f(s, test->needle);

	/* remove whitespaces from output for compare */
	p->pass = !strcmp(strip(o), strip(t));
	p->passed += p->pass;

	if (o != s)
		free(o);
	free(s);
	free(t);
}

void
runtest(struct part *p, struct test *t)
{
	char *stat[] = {"fail", "pass"};
	struct timeval begin, end;
	int i, k;

 	prepare(p, t);

	fprintf(stderr, "%16s ", p->fname);
	p->time = 0.0;
	for (k = 0; k < passes; k++) {
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
	fprintf(stderr, "%5s%9.2f ms\n", stat[p->pass], p->time);
}

void
result(struct part *p)
{
	struct part *z;
	double minval = 100000.0;

	for (z = p; z->name != NULL; z++)
		if (strcmp(z->fname, "nop") && z->grostime < minval)
			minval = z->grostime;

	printf("\nGros Relults\n----\n\n");
	printf("%-16s| %-16s| %-8s| %-12s| %-12s\n",
	    "name", "func name", "passed", "gros time", "slower");
	printf("%-16s| %-16s| %-8s| %-12s| %-12s\n",
	    "---", "---", "---", "---", "---");
	for (; p->name != NULL; p++)
		printf("%-16s| %-16s|%8d |%9.2f ms | %9.2f %% \n",
		    p->name, p->fname, p->passed,
		    p->grostime, 100.0 * (p->grostime - minval) / minval);
}

int
main(int argc, char **argv)
{
	struct part *p;
	struct test *t;

	for (t = testcases; t->string; t++) {
		fprintf(stderr, "\n%16s \"%s\"\n", "input", t->string);
		for (p = part; p->name; p++)
			runtest(p, t);
	}

	result(part);

	return 0;
}
