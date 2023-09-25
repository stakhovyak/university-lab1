#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>
using namespace std;

typedef struct sDate
{
  int day;
  int month;
  int year;
} date;

date parseString (const string &str);

#endif
