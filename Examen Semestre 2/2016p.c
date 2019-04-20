#include "../Mylibs/Tree_lib.h"


void destructTree1(tree *t)
{
    tree *a1, *a2;
    a1 = (tree *)malloc(sizeof(tree));
    a1[0] = *t ;
    int n1 = 1, n2;
    while (n1)
    {
        n2 = 0 ;
        a2 = (tree *)malloc(sizeof(tree) * 2 * n1);
        for (int i = 0 ; i < n1; i++)
        {
            if (a1[i]->l)
            {
                n2 ++ ;
                a2[n2 - 1] =  a1[i]->l;
            }
            if (a1[i]->r)
            {
                n2 ++ ;
                a2[n2 - 1] =  a1[i]->r;
            }
            free(a1[i]);
        }
        n1 = n2 ;
        a1 = a2 ;
    }
    *t = NULL ;

}

int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    tree t ;
    t = creatLeaf(4);
    t->l = creatLeaf(2);
    t->r = creatLeaf(33);
    t->l->l = creatLeaf(1);
    t->l->r = creatLeaf(3);
    t->r->l = creatLeaf(22);
    t->r->r = creatLeaf(54);
    //   printTree(t);
    destructTree1(&t);
    printTree(t);


}
