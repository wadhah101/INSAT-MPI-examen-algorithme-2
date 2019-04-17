#include "TreesLib.h"

int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    tree t = createLeaf(8);
    t->l = createLeaf(3);
    t->r = createLeaf(10);
    t->r->r = createLeaf(14);
    t->r->r->l = createLeaf(13);
    t->l->l = createLeaf(1);
    t->l->r = createLeaf(6);
    t->l->r->l = createLeaf(4);
    t->l->r->r = createLeaf(8);
    levelOrderTraversal(t);
    insertIntoBST(&t,70);
    insertIntoBST(&t,89);
    levelOrderTraversal(t);
    //   tree q = NULL ;
    //  int a[] = {1,4,5,6,8,20,78,100,200,700,800,5000,10000} ;
    // levelOrderTraversal(q);

}
