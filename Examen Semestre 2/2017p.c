#include "../Mylibs/List_lib.h"
#include "../Mylibs/Tree_lib.h"

//EX1
typedef struct nodeC
{
    int data ;
    int num ;
    struct nodeC *next ;
} nodeC, *listC;

listC createnodeC(int x)
{
    listC l;
    l = (listC)malloc(sizeof(nodeC));
    l->data = x;
    l->num = 1;
    l->next = NULL;
    return l;
}

listC adjtC(listC l, int e)
{
    if (!l)
    {
        l = createnodeC(e);
        return l;
    }
    listC temp = createnodeC(e);
    temp->next = l;
    return temp;
}

void printlistC(listC l)
{
    if (l)
    {
        printf("(%d , %d) ", l->data, l->num);
        printlistC(l->next);
    }
    else
        printf("\n");
}

listC compression(list l)
{
    if (!l)
        return NULL ;
    else
    {
        listC li = compression(l->next);
        if (!li)
        {
            return createnodeC(l->data);
        }
        if (l->data == li->data)
        {
            li->num ++ ;
            return li ;
        }
        else
            return adjtC(li, l->data);
    }
}

list decompression(listC li)
{
    if (!li)
        return NULL ;
    else
    {
        list l = decompression(li->next);
        for (int i = 0 ; i < li->num; i++)
            l = adjt(l, li->data);
        return l ;
    }

}

//EX2

file inverse(file f)
{
    int kept = 1 ;
    file f0 = creatFile();
    int n = 0 ;
    while (!emptyFile(f))
    {
        emfiler(&f0, teteFile(f));
        defiler(&f);
        n++;
    }
    for (int i = n - 1 ; i >= 0 ; i--)
    {
        for (int j = 0 ; j < i; j++ )
        {
            emfiler(&f0, teteFile(f0));
            defiler(&f0);
        }
        emfiler(&f, teteFile(f0));
        defiler(&f0);
    }

    return f ;
}

//EX3
void suppred(tree *t, int n)
{
    if (*t)
    {
        if ((*t)->data == n && (*t)->l)
        {
            while ((*t)->data == (*t)->l->data)
            {
                tree temp  = (*t)->l ;
                (*t)->l = temp ->l ;
                free(temp);
                if ((*t)->l == NULL)
                    break ;
            }
        }
        suppred(&(*t)->l, n);
        suppred(&(*t)->r, n);
    }

}

int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    tree t = creatLeaf(4);
    t->r = creatLeaf(6);
    t->l = creatLeaf(4);
    t->r->r = creatLeaf(7);
    t->r->l = creatLeaf(6);
    t->l->l = creatLeaf(2);
    t->l->l->l = creatLeaf(1);
    t->l->l->r = creatLeaf(3);
    t->r->l->l = creatLeaf(6);
    t->r->l->l->l = creatLeaf(5);
    printTree(t);
    suppred(&t, 6);
    printf("\n\n\nModified tree: \n\n\n");
    printTree(t);
}
