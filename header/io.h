/* io.h 
 *
 * for Class Bench Rule List and bitstring header
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __TANAKALAB_IO_H__
#define __TANAKALAB_IO_H__

#ifndef __TANAKALAB_CONST_H__
#include <const.h>
#endif

#ifndef __TANAKALAB_LIST_H__
#include <list.h>
#endif

#ifndef __TANAKALAB_TOOLS_H__
#include <tools.h>
#endif

#define HEADER_LENGTH 104

struct RULE {
  unsigned num;
  char* sa;
  char* da;
  string_list* sp;
  string_list* dp;
  char* prot;
};
typedef struct RULE rule;

rule* read_rule_list(char*);
char** read_header_list(char*);

void free_header_list(char**);
void free_rule_list(rule*);

#endif
