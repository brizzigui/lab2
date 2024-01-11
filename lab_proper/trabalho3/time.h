#ifndef TIME_H
#define TIME_H

struct data {
    int day;
    int month;
    int year;
}; typedef struct data Date;

int daysBetweenDates(Date date1, Date date2);

#endif