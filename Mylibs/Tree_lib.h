#include <stdio.h>
#include <stdlib.h>

typedef struct leaf
{
    int value ;
    struct leaf *l, *r ;
} leaf;

typedef  leaf *tree  ;

tree creatLeaf(int n)
{
    tree t = (tree)malloc(sizeof(leaf)) ;
    t->value = n ;
    t->l = NULL ;
    t->r = NULL ;
}

int max (int a, int b)
{
    if (a > b)
        return a;
    return b ;
}

void preOrderTraversal(tree t)
{
    if (!t)
        return ;
    printf("%d\n", t->value);
    preOrderTraversal(t->l);
    preOrderTraversal(t->r);
}

void inOrderTraversal(tree t)
{
    if (!t)
        return ;
    inOrderTraversal(t->l);
    printf("%d\n", t->value);
    inOrderTraversal(t->r);
}

void postOrderTraversal(tree t)
{
    if (!t)
        return ;
    postOrderTraversal(t->l);
    postOrderTraversal(t->r);
    printf("%d\n", t->value);
}

int treeHeight(tree t)
{
    if (!t)
        return 0 ;
    else
        return 1 + max(treeHeight(t->l), treeHeight(t->r));
}

void printlevel(tree t, int n)
{
    if (!n)
        printf("%d | ", t->value);
    else
    {
        if (t->l)
            printlevel(t->l, n - 1);
        if (t->r)
            printlevel(t->r, n - 1);
    }
}

tree adjd(tree h, tree t)
{
    h->r = t ;
    return h ;
}

tree adjg(tree h, tree t)
{
    h->l = t ;
    return h ;
}

typedef struct Tnode
{
    tree val;
    struct Tnode *next;
} Tnode, *Tlist;

void printTlist(Tlist l)
{
    if (l)
    {
        printf("%d ", l->val->value);
        printTlist(l->next);
    }
}

Tlist createTnode(tree x)
{
    Tlist l;
    l = (Tlist)malloc(sizeof(Tnode));
    l->val = x;
    l->next = NULL;
    return l;
}

Tlist adjtT(Tlist l, tree e)
{
    if (!l)
    {
        l = createTnode(e);
        return l;
    }
    Tlist temp = createTnode(e);
    temp->next = l;
    return temp;
}

Tlist adjqT(Tlist l, tree e)
{
    if (!l)
        return adjtT(l, e);
    else
        return adjtT(adjqT(l->next, e), l->val);
}

void printInversedList(Tlist l)
{
    if (l)
    {
        printInversedList(l->next) ;
        printf("%d ", l->val->value);
    }
}

void LevT(Tlist l)
{
    Tlist l2 = NULL ;
    if (l)
    {
        //traitement sur l
        printInversedList(l);
        printf("\n");
        while (l)
        {
            if (l->val->r)
                l2 = adjqT(l2, l->val->r);
            if (l->val->l)
                l2 = adjqT(l2, l->val->l) ;
            l = l->next ;
        }
        LevT(l2);
    }
    else
        return ;
}

void levelOrderTraversal(tree t)
{
    Tlist l = createTnode(t);
    LevT(l);
    printf("\n");
}

int searchElement(Tlist l, int n)
{
    if (!l)
        return 0 ;
    else
    {
        if (l->val->value == n)
            return 1 ;
        else
            return searchElement(l->next, n);
    }
}

void LevTinsert(Tlist *l, int e)
{
    Tlist l2 = NULL ;
    if (l)
    {
        //traitement sur l
        Tlist nav = *l;
        while(nav)
        {
            if (searchElement(nav, e))
                return ;
            if(!nav->val->r)
            {
                nav->val->r = creatLeaf(e);
                return ;
            }
            else if (!nav->val->l)
            {
                nav->val->l = creatLeaf(e);
                return ;
            }
            nav = nav->next;
        }
        while (*l)
        {
            if ((*l)->val->r)
                l2 = adjqT(l2, (*l)->val->r);
            if ((*l)->val->l)
                l2 = adjqT(l2, (*l)->val->l) ;
            *l = (*l)->next ;
        }
        LevTinsert(&l2, e);
    }
    else
        return ;
}

void insertIntoTree(tree *t, int e)
{
    //insert into the first free position of t
    if (!(*t))
    {
        *t = creatLeaf(e) ;
    }
    Tlist l = createTnode(*t);
    LevTinsert(&l, e);
}

tree fillfromArray(int *a, int n)
{
    tree t = NULL ;
    for (int i = 0 ; i < n ; i++)
    {
        insertIntoTree(&t, a[k + i]);
    }
    return t ;
}

void printTreeTool(tree t, int space)
{
    if (!t)
    {
        printf("\n");
        return ;
    }
    else
    {
        printTreeTool(t->r, space + 5);
        for (int i = 0 ; i < space ; i++)
            printf(" ");
        printf("%5d", t->value);
        printTreeTool(t->l, space + 5);
    }
}
void printTree(tree t)
{
    printTreeTool(t, 0);
}