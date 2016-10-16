// tail.c

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "../common/io.h"
#include "../common/string_util.h"

const char EOL = '\n';
const char FLAG_LINES = 0b1;

int parse_nlines(const char* str);
char parse_flags(int argc, char* argv[], char* operands[]);

int main(int argc, char* argv[]) {
    char* operands[100];
    char flags = parse_flags(argc, argv, operands);

    size_t nlines = 10;
    if (flags & FLAG_LINES)
	nlines = parse_nlines(operands[0]);

    size_t buf_size = 1000;
    char buffer[nlines + 1][buf_size];
    size_t c = 0;
    while (c < nlines && fgets(buffer[c++], buf_size, stdin));
    while (fgets(buffer[c], buf_size, stdin)) {
	for (size_t i = 0; i < c; i++)
	    strcpy(buffer[i], buffer[i+1]);
    }

    for (size_t i = 0; i < nlines; i++) {
	print(buffer[i]);
    }

    return 0;
}

int parse_nlines(const char* str) {
    if (isnumber(str))
	return atoi(str);
    else {
	puts("Error: could not parse argument as a number");
	exit(-1);
    }
}

char parse_flags(int argc, char* argv[], char* operands[]) {
    char flags = 0;
    bool operand_expected = false;
    if (argc > 1) {
	char* arg;
	while (argc-- && (arg = *(++argv))) {
	    if ((flags & FLAG_LINES) && operand_expected) {
		*operands++ = arg;
		operand_expected = false;
	    }

	    if (arg[0] == '-') {
		if (strcmp(arg, "-n") == 0 || strcmp(arg, "--lines") == 0) {
		    flags |= FLAG_LINES;
		    operand_expected = true;
		    arg++;
		} else {
		    printf("Error: unknown argument '%s'\n", arg);
		    exit(-1);
		}
	    }
	}
    }

    if (operand_expected) {
	puts("Error: operand expected");
	exit(-1);
    }

    return flags;
}
