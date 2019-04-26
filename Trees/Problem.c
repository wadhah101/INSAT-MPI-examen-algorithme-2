#include "../Mylibs/tree.h"

int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    tree t = creatLeaf(8);
    t->l = creatLeaf(3);
    t->r = creatLeaf(10);
    t->r->r = creatLeaf(14);
    t->r->r->l = creatLeaf(13);
    t->l->l = creatLeaf(1);
    t->l->r = creatLeaf(6);
    t->l->r->l = creatLeaf(4);
    t->l->r->r = creatLeaf(8);
}
