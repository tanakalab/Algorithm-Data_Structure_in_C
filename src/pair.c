/* pair.c */

#include <pair.h>

bool eq_pair_unsigned(pair_unsigned x, pair_unsigned y) {
  if (x.first == y.first && x.second == y.second) { return true; }
  return false;
}

bool lt_pair_unsigned(pair_unsigned x, pair_unsigned y) {
  if (x.first < y.first) { return true; }
  if (x.first == y.first) {
    if (x.second < y.second) { return true; }
    else { return false; }
  }
  return false;
}

bool leq_pair_unsigned(pair_unsigned x, pair_unsigned y) {
  if (eq_pair_unsigned(x,y) || lt_pair_unsigned(x,y)) { return true; }
  return false;
}
