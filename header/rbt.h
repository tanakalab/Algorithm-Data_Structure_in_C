/* rbt.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __DTREE_RBT_H__
#define __DTREE_RBT_H__

#ifndef __DTREE_CONST_H__
#include <const.h>
#endif

#ifndef __DTREE_LIST_H__
#include <list.h>
#endif

#ifndef __DTREE_TOOLS_H__
#include <tools.h>
#endif

#ifndef __DTREE_IO_H__
#include <io.h>
#endif

struct RBT_NODE {
  struct RBT_NODE* left;
  struct RBT_NODE* right;
};
typedef struct RBT_NODE rbt_node;

#endif
