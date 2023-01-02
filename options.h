#ifndef MESA_CISC187_PROJECT03_OPTIONS_H
#define MESA_CISC187_PROJECT03_OPTIONS_H

#include <string>

// Name : Jamie Anzai
// ID : 5550091018

struct option{
  bool verboseOutput = false;
};

std::string usage(const char*);
std::string help(const char*);
option get_options(int, char**);

#endif
