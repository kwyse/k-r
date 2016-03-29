// 5.7 : readlines without alloc

#include <errno.h>
#include "header.h"

#define MAXLINES 5000
char* lineptr[MAXLINES]; // array of MAXLINE elements, each of which is ptr to char

int readlines(char* lineptr[], int maxlines);
int myreadlines(char* lineptr[], int maxlines, char* store, size_t storesize);
void writelines(char* lineptr[], int nlines);
void myqsort(char* v[], int left, int right);

int main()
{
    int nlines = 0;
    static const size_t BUFSIZE = 10000;
    char buf[BUFSIZE];
    //if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    if ((nlines = myreadlines(lineptr, MAXLINES, buf, BUFSIZE)) >= 0) {
	bench(myqsort(lineptr, 0, nlines - 1));
	writelines(lineptr, nlines);
	return 0;
    } else {
	errno = ENOMEM;
	perror("Input is too big to sort");
	return 1;
    }
}

int getln(char* s, int maxlen);
char* alloc(int bytes);

int readlines(char* lineptr[], int maxlines)
{
    static const int MAXLEN = 1000;
    char line[MAXLEN];
    int nlines = 0;
    char* p = NULL;

    int len = -1;
    while ((len = getln(line, MAXLEN)) > 0) {
	if (nlines >= maxlines || (p = alloc(len)) == NULL)
	    return -1;
	else {
	    line[len - 1] = '\0'; // Delete newline
	    strcpy(p, line);
	    lineptr[nlines++] = p;
	}
    }

    return nlines;
}

int myreadlines(char* lineptr[], int maxlines, char* store, size_t storesize)
{
    static const int MAXLEN = 1000;
    char line[MAXLEN];
    int nlines = 0;
    char* p = NULL;
    size_t used = 0;

    int len = -1;
    while ((len = getln(line, MAXLEN)) > 0) {
	if (nlines >= maxlines || (p = store + used) >= store + storesize)
	    return -1;
	else {
	    used += len;
	    line[len - 1] = '\0'; // Delete newline
	    strcpy(p, line);
	    lineptr[nlines++] = p;
	}
    }

    return nlines;
}

void writelines(char* lineptr[], int nlines)
{
    while (nlines--)
	printf("%s\n", *lineptr++);
}

void myqsort(char* v[], int left, int right)
{
    void swap(char* v[], int i, int j);

    if (left >= right)
	return;

    swap(v, left, (left + right) / 2);
    int last = left;
    for (int i = left + 1; i <= right; i++) {
	if (strcmp(v[i], v[left]) < 0)
	    swap(v, ++last, i);
    }

    swap(v, left, last);
    myqsort(v, left, last - 1);
    myqsort(v, last + 1, right);
}

void swap(char* v[], int i, int j)
{
    char* tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
