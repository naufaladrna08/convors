#include "Helpers.hpp"

int Helpers::extractInt(char* s) {
  char* p = s;
  char tmp[5];
  long val;

  while (*p) {
    if (isdigit(*p) || ((*p == '-' || *p == '+') && isdigit(*(p + 1)))) {
      val = strtol(p, &p, 10);
    } else {
      p++;
    }
  }

  return val;
}