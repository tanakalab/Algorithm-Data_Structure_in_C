/* tools.h */

#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef __TANAKALAB_TOOLS_H__
#define __TANAKALAB_TOOLS_H__

#ifndef __TANAKALAB_LIST_H__
#include <list.h>
#endif

#define LOW 0
#define HIGH 65535
#define BIT_LENGTH 16

string_list* range_to_01m_strings(unsigned, unsigned, unsigned, unsigned);
string_list* int_pair_to_01m_string(unsigned, unsigned, unsigned);
  
#endif
