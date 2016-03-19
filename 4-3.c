// 4.3 : RPN calculator + modulus operator, negative numbers

#include <math.h>
#include "header.h"

#define NUMBER '0'

int getop(char s[]);
void push(double f);
double pop(void);

int main()
{
    const size_t MAX_OP_SIZE = 100;

    char s[MAX_OP_SIZE];

    double op2 = 0.0;
    int type;
    while ((type = getop(s)) != EOF) {
	switch (type) {
	case NUMBER:
	    push(atof(s));
	    break;
	case '+':
	    push(pop() + pop());
	    break;
	case '*':
	    push(pop() * pop());
	    break;
	case '-':
	    op2 = pop();
	    push(pop() - op2);
	    break;
	case '/':
	    op2 = pop();
	    if (op2 != 0.0)
		push(pop() / op2);
	    else
		perror("dividing by zero");
	    break;
	case '%':
	    op2 = pop();
	    if (op2 != 0.0)
		push(fmod(pop(), op2));
	    else
		perror("dividing by zero");
	    break;
	case '\n':
	    putf(pop());
	    break;
	default:
	    fprintf(stderr, "Unknown command '%s'\n", s);
	    break;
	}
    }

    return EXIT_SUCCESS;
}

// Cannot be a constant because C constants not constants, just RO
// Memory addresses can change for constants
#define STACK_SIZE 100

double stack[STACK_SIZE];
size_t stackpos = 0;

void push(double f)
{
    if (stackpos < STACK_SIZE)
	stack[stackpos++] = f;
    else
	fprintf(stderr, "Stack full, cannot push %f\n", f);
}

double pop(void)
{
    if (stackpos > 0)
	return stack[--stackpos];
    else {
	perror("Stack empty, cannot pop");
	return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int c);

int getop(char s[])
{
    int c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
	return c;

    size_t i = 0;
    if (isdigit(c))
	while (isdigit(s[++i] = c = getch()));

    if (c == '.')
	while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if (c != EOF)
	ungetch(c);

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
size_t bufpos = 0;

int getch(void)
{
    return (bufpos > 0) ? buf[--bufpos] : getchar();
}

void ungetch(int c)
{
    if (bufpos >= BUFSIZE)
	perror("Cannot ungetch, too many characters");
    else
	buf[bufpos++] = c;
}
