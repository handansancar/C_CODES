#include "stdio.h"

#define YEARBASE    2000

typedef struct DATE_ {
    int day;
    int month;
    int year;
}DATE;

int days_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap(int);
int day_of_year(DATE);
int date_to_number(DATE);
int date_diff(DATE, DATE);

int main(void)
{
    DATE date1, date2;

    printf("Baslangic tarihini girin:");
    scanf("%d%d%d", &date1.day, &date1.month, &date1.year);
    printf("Bitis tarihini girin:");
    scanf("%d%d%d", &date2.day, &date2.month, &date2.year);

    printf("Girilen tarihler arasindaki gun farki %d'dir", date_diff(date1, date2));
}

int is_leap(int year)
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
int day_of_year(DATE date)
{
    int month;
    int sum_of_day = date.day;

    for(month = 0; month < date.month - 1; month++)
    {
        sum_of_day += days_of_month[month];
    }

    return sum_of_day + is_leap(date.year);
}

int date_to_number(DATE date)
{
    int sum_of_day = 0;
    int year;

    for(year = YEARBASE; year < date.year; year++)
        sum_of_day += 365 + is_leap(year);

    sum_of_day += day_of_year(date);

    return  sum_of_day;
}

int date_diff(DATE date1, DATE date2)
{
    return date_to_number(date2) - date_to_number(date1);
}