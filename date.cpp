#include "date.h"
#include <sstream>

date parseString (const string &str)
{
  date input;
  istringstream value (str);
  char delemeter = '/';
  value >> input.day >> delemeter >> input.month >> delemeter >> input.year;
  return input;
}

