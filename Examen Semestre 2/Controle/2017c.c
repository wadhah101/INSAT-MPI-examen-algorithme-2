#include "../../Mylibs/List_lib.h"
#include "../../Mylibs/Tree_lib.h"
#include <limits.h>
//EX1

int nbfils(tree t)
{
    if (!t)
        return 0 ;
    if (t->r && !t->l)
        return 1 + nbfils(t->r);
    if (!t->r && t->l)
        return 1 + nbfils(t->l);
    return nbfils(t->r) + nbfils(t->l) ;
}

//EX2
int perfectTree(tree t)
{
    if (!t)
        return 1 ;
    if ((!t->r && t->l) || (!t->l && t->r))
        return 0 ;
    if (treeHeight(t->r) != treeHeight(t->l))
        return 0 ;
    else
        return perfectTree(t->r) * perfectTree(t->l);
}

int isBSTtool(tree t, int min, int max)
{
    if (!t)
        return 1 ;
    if (t->data <= min || t->data >= max)
        return 0 ;
    return isBSTtool(t->l, min, t->data) * isBSTtool(t->r, t->data, max);
}

int isBST(tree t)
{
    return isBSTtool(t, INT_MIN, INT_MAX);
}


int main()
{
    freopen("../in.txt", "r+", stdin);
    freopen("../out.txt", "w+", stdout);
    tree t, q = NULL;
    t = newLeaf(4);
    t->l = newLeaf(2);
    t->r = newLeaf(33);
    t->l->l = newLeaf(1);
    t->l->r = newLeaf(3);
    t->r->l = newLeaf(22);
    t->r->r = newLeaf(54);
    q = newLeaf(4);
    q->l = newLeaf(2);
    q->r = newLeaf(33);
    q->l->l = newLeaf(1);
    q->l->r = newLeaf(3);
    q->r->l = newLeaf(22);
    q->r->r = newLeaf(54);
}
