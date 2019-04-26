#include "../../Mylibs/tree.h"

tree minBSt(tree t)
{
    while(t->l)
        t = t->l ;
    return t ;
}

tree deleteFromBST (tree t, int key)
{

    if (!t)
    	return NULL;
    else if (key > t->data)
    {
        t->r = deleteFromBST(t->r, key);
        return t ;
    }

    else if (key < t->data)
    {
        t->l = deleteFromBST(t->l, key);
        return t ;
    }

    else
    {
        if (t->l == NULL)
        {
            tree q = t->r ;
            free(t);
            return q ;
        }
        else if (t->r == NULL)
        {
            tree q = t->l ;
            free(t);
            return q ;
        }
        tree q = minBSt(t->r);
        t->data = q->data ;
        t->r = deleteFromBST(t->r, q->data);
        return t ;
    }

}

int main()
{
    freopen("../in.txt", "r+", stdin);
    freopen("../out.txt", "w+", stdout);
    tree t = newLeaf(7);
    t->l = newLeaf(4);
    t->r = newLeaf(8);
    t->l->r = newLeaf(5);
    t->l->l = newLeaf(3);
    t->l->l->l = newLeaf(2);
    t->l->r->r = newLeaf(6) ;
    printTree(t);
    printf("\n\n\n");
    t =  deleteFromBST(t, 7);
    printTree(t);
}
