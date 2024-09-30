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
    int16 n;
    for (n = 0, p = str; n < size; n++, p++)
        p = 0;

    return;
}

Node *create_node(Node *parent, int8 *path)
{
    Node *n;
    int16 size;
    errno = NoError;
    assert(parent);
    size = sizeof(struct s_node);
    n = (Node *)malloc((int)size);
    zero((int8 *)n, size);
    parent->left = n;
    n->tag = TagNode;
    n->up = parent;
    strncpy((char *)n->path, (char *)path, 255);
    return n;
}

Leaf *find_last_leaf(Node *parent){
    Leaf *l;
    errno = NoError;
    assert(parent);

    if(!parent->right){
        reterr(NoError);
    }

    for(l = parent->right; l->left; l = l->right);
    assert(l);

    return l;
}

Leaf *create_leaf(Node* parent, int8* key, int8 *value, int16 count){
    Leaf* l, *new;
    // Node* n;
    int16 size;
    assert(parent);
    l = find_last_leaf(parent);

    size = sizeof(struct s_leaf);
    new = (Leaf *)malloc((int)size);
    assert(new);

    if(!l){
        // root
        parent->right = new;
    }else{
        //leaf
        l->right = new;
    }

    zero((int8 *)new, size);
    new->tag = TagLeaf;
    new->left = (!l) ? (Tree*)parent : (Tree*)l;
    strncpy((char *)new->key, (char *)key, 127);
    new->value = (int8*)malloc(count);
    zero(new->value, count);
    assert(new->value);
    strncpy((char *)new->value, (char *)value, count);
    new->size = count;
    return new;
}

int main(){
    Node *n, *n2;
    Leaf *l, *l2;
    n = create_node((Node *)&root, (int8 *)"/User");
    assert(n);
    n2 = create_node(n, (int8 *)"/User/login");
    assert(n2);

    l = create_leaf(n, (int8 *)"Kartik", (int8 *)"1234567", 7);
    assert(l);
    printf("%s", l->key);

    printf("%p  %p", n, n2);
    free(n);
    free(n2);
    return 0;
}