#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#define NoError 0
#define TagRoot 1 // 00 01
#define TagNode 2 // 00 10
#define TagLeaf 4 // 01 00
#define reterr(x)\
    errno = x;\
    return nullptrr;

typedef void *NullPtr;
NullPtr nullptrr = 0;

typedef unsigned int int32;
typedef unsigned short int16;
typedef unsigned char int8;
typedef unsigned char Tag;

struct s_node
{
    Tag tag;
    struct s_node *up;
    struct s_node *left;
    struct s_leaf *right;
    int8 path[256];
};

typedef struct s_node Node;

struct s_leaf
{
    Tag tag;
    union u_tree *left;
    struct s_leaf *right;
    int8 key[128];
    int8 *value;
    int16 size;
};

typedef struct s_leaf Leaf;

union u_tree
{
    Node n;
    Leaf l;
};

typedef union u_tree Tree;


