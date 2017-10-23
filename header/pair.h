/* pair.h */

#ifndef __TANAKALAB_PAIR_H__
#define __TANAKALAB_PAIR_H__

#ifndef __TANAKALAB_CONST_H__
#include <const.h>
#endif

struct PAIR_UNSIGNED {
  unsigned first;
  unsigned second;
};
typedef struct PAIR_UNSIGNED pair_unsigned;

bool eq_pair_unsigned(pair_unsigned, pair_unsigned);
bool lt_pair_unsigned(pair_unsigned, pair_unsigned);
bool leq_pair_unsigned(pair_unsigned, pair_unsigned);


#endif
