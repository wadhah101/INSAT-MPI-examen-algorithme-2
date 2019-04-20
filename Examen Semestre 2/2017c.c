#include "../Mylibs/List_lib.h"
#include "../Mylibs/Tree_lib.h"
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

pile pairPile(pile *p1)
{
    pile p2 = creatPile();
    file f = creatFile() ;
    while(!emptyPile(*p1))
    {
        if (tetePile(*p1) % 2 == 0)
        {
            empiler(&p2, tetePile(*p1));
            depiler(p1);
        }
        else
        {
            emfiler(&f, tetePile(*p1));
            depiler(p1);
        }
    }
    while(!emptyFile(f))
    {
        empiler(p1, teteFile(f));
        defiler(&f);
    }
    while (!emptyPile(*p1))
    {
        emfiler(&f, tetePile(*p1));
        depiler(p1);
    }
    while(!emptyFile(f))
    {
        empiler(p1, teteFile(f));
        defiler(&f);
    }
    while (!emptyPile(p2))
    {
        emfiler(&f, tetePile(p2));
        depiler(&p2);

    }
    while(!emptyFile(f))
    {
        empiler(&p2, teteFile(f));
        defiler(&f);
    }
    return p2 ;
}
//ex3
int egaux (tree a, tree b)
{
    if (!a && !b)
        return 1 ;
    if (a && !b)
        return 0 ;
    if (!a && b)
        return 0 ;
    if (a->data != b->data)
        return 0 ;
    return egaux(a->l, b->l) * egaux(a->r, b->r);
}

int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    tree t, q = NULL;
    t = creatLeaf(4);
    t->l = creatLeaf(2);
    t->r = creatLeaf(33);
    t->l->l = creatLeaf(1);
    t->l->r = creatLeaf(3);
    t->r->l = creatLeaf(22);
    t->r->r = creatLeaf(54);
    q = creatLeaf(4);
    q->l = creatLeaf(2);
    q->r = creatLeaf(33);
    q->l->l = creatLeaf(1);
    q->l->r = creatLeaf(3);
    q->r->l = creatLeaf(22);
    q->r->r = creatLeaf(54);
    printf("%d\n", egaux(t, q));
}
