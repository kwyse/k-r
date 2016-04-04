// 5.8 : day_of_year and month_day with error checking

#include "header.h"

int dayofyear(int year, int month, int day);
void monthday(int year, int yearday, int* monthptr, int* dayptr);

static char daytab[2][12] = {
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

static bool isleapyear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int dayofyear(int year, int month, int day)
{
    if (!inrange(month, 1, 12) || !inrange(day, 1, 31))
	return -1;

    bool leapyear = isleapyear(year);
    if (day > daytab[leapyear][month - 1])
	return -1;

    for (int i = 0; i < month - 1; i++)
	day += daytab[leapyear][i];

    return day;
}

void monthday(int year, int yearday, int* monthptr, int* dayptr)
{
    bool leapyear = isleapyear(year);
    if ((yearday > (365 + leapyear)) || (yearday < 1)) {
	*monthptr = -1;
	*dayptr = -1;
	return;
    }

    int i = 0;
    for ( ; yearday > daytab[leapyear][i]; i++)
	yearday -= daytab[leapyear][i];

    *monthptr = i + 1;
    *dayptr = yearday;
}

int main()
{
    a(dayofyear(2000, 2, 1) == 32);
    a(dayofyear(2015, 5, 5) == 125);
    a(dayofyear(2016, 5, 5) == 126);
    a(dayofyear(2016, 13, 5) == -1);
    a(dayofyear(2016, 5, 32) == -1);
    a(dayofyear(2016, 2, 30) == -1);

    int monthptr[] = { -1 };
    int dayptr[] = { -1 };

    monthday(2000, 32, monthptr, dayptr);
    a(*monthptr == 2);
    a(*dayptr == 1);
    monthday(2015, 125, monthptr, dayptr);
    a(*monthptr == 5);
    a(*dayptr == 5);
    monthday(2016, 126, monthptr, dayptr);
    a(*monthptr == 5);
    a(*dayptr == 5);
    monthday(2016, 366, monthptr, dayptr);
    a(*monthptr == 12);
    a(*dayptr == 31);
    monthday(2015, 366, monthptr, dayptr);
    a(*monthptr == -1);
    a(*dayptr == -1);
    monthday(2015, 365, monthptr, dayptr);
    a(*monthptr == 12);
    a(*dayptr == 31);
    monthday(2016, 367, monthptr, dayptr);
    a(*monthptr == -1);
    a(*dayptr == -1);
    monthday(2016, 0, monthptr, dayptr);
    a(*monthptr == -1);
    a(*dayptr == -1);

    return 0;
}
