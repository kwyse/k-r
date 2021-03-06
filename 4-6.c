// 4.6 : RPN calculator + variables

#include <math.h>
#include "header.h"

#define NUMBER '0'
#define VAR 'a'

int getop(char s[]);
void push(double f);
double pop(void);

double vars[26];
bool var_used[26];
double last = 0.0;

int main()
{
    const size_t MAX_OP_SIZE = 100;
    for (size_t i = 0; i < 26; i++) {
	vars[i] = -1;
	var_used[i] = false;
    }

    char s[MAX_OP_SIZE];

    double op2 = 0.0;
    size_t index = 0;
    int type;
    while ((type = getop(s)) != EOF) {
	switch (type) {
	case NUMBER:
	    push(atof(s));
	    break;
	case VAR:
	    push((double) s[0] - 'a');
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
	case 's':
	    push(sin(pop()));
	    break;
	case 'e':
	    push(exp(pop()));
	    break;
	case 'p':
	    op2 = pop();
	    push(pow(pop(), op2));
	    break;
	case '=':
	    op2 = pop();
	    index = (int) pop();
	    vars[index] = op2;
	    var_used[index] = true;
	    push(op2);
	    break;
	case ';':
	    push(last);
	    break;
	case '\n':
	    last = pop();
	    putf(last);
	    break;
	default:
	    fprintf(stderr, "Unknown command '%s' of type '%d'\n", s, type);
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

void peek(void)
{
    if (stackpos > 1) {
	double first = stack[stackpos - 1];
	double second = stack[stackpos - 2];
	printf("Top two elements: %f, %f\n", first, second);
    } else
	perror("The stack contains less than two elements");
}

void dup(double to[])
{
    for (size_t i = 0; i < stackpos; i++)
	to[i] = stack[i];
}

void swap()
{
    if (stackpos > 1) {
	double tmp = stack[stackpos - 1];
	stack[stackpos - 1] = stack[stackpos - 2];
	stack[stackpos - 2] = tmp;
    } else
	perror("The stack contains less than two elements");
}

void clear()
{
    stackpos = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int c);

int getop(char s[])
{
    int c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    if (islower(c)) {
	if (var_used[c - 'a']) {
	    sprintf(s, "%f", vars[c - 'a']);
	    return NUMBER;
	} else
	    return VAR;
    }

    if (c == ';') {
	sprintf(s, "%f", last);
	return NUMBER;
    }

    if (!isdigit(c) && c != '.' && c != '-' && c != '+')
	return c;

    if (c == '=')
	return '=';

    size_t i = 0;
    if (c == '-' || c == '+') {
	char next = getch();
	if (next != EOF)
	    ungetch(next);
	if (!isdigit(next) && next != '.')
	    return c;
	s[++i] = c = getch();
    }

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
