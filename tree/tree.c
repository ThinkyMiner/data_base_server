#include "tree.h"

Tree root = {.n = {
                 .tag = (TagRoot | TagNode),
                 .up = (Node *)&root,
                 .left = 0,
                 .right = 0,
                 .path = "/"}};

void zero(int8 *str, int16 size)
{
    int8 *p;
    for (int16 n = 0, p = str; n < size; n++, p++)
        p = 0;

    return;
}

Node *create_node(Node *parent, int8 *path)
{
    Node *n;
    int16 size;
    assert(parent);
    size = sizeof(struct s_node);
    n = (Node *)malloc(size);
    zero((int8 *)n, size);
    parent->left = n;
    n->tag = TagNode;
    n->up = parent;
    strncpy((char *)n->path, (char *)path, 255);
    return n;
}
int main()
{
    printf("%p", &root);
    return 0;
}