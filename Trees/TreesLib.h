#include <stdio.h>
#include <stdlib.h>

typedef struct leaf
{
    int value ;
    struct leaf *l, *r ;
} leaf;

typedef  leaf *tree  ;


tree createLeaf(int n)
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



struct node
{
    tree val;
    struct node *next;
};
typedef struct node Node;
typedef Node *list;

void printlist(list l)
{
    if (l)
    {
        printf("%d ", l->val->value);
        printlist(l->next);
    }
}

list createnode(tree x)
{
    list l;
    l = (list)malloc(sizeof(Node));
    l->val = x;
    l->next = NULL;
    return l;
}

list adjt(list l, tree e)
{
    if (!l)
    {
        l = createnode(e);
        return l;
    }
    list temp = createnode(e);
    temp->next = l;
    return temp;
}

list adjq(list l, tree e)
{
    if (!l)
        return adjt(l, e);
    else
        return adjt(adjq(l->next, e), l->val);
}

void printInversedList(list l)
{
    if (l)
    {
        printInversedList(l->next) ;
        printf("%d ", l->val->value);
    }
}

void LevT(list l)
{
    list l2 = NULL ;
    if (l)
    {
        //traitement sur l
        printInversedList(l);
        printf("\n\n");
        while (l)
        {
            if (l->val->r)
                l2 = adjq(l2, l->val->r);
            if (l->val->l)
                l2 = adjq(l2, l->val->l) ;
            l = l->next ;
        }
        LevT(l2);
    }
    else
        return ;
}

void levelOrderTraversal(tree t)
{
    list l = createnode(t);
    LevT(l);
}

int searchElement(list l, int n)
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

void LevTinsert(list *l, int e)
{
    list l2 = NULL ;
    if (l)
    {
        //traitement sur l
        list nav = *l;
        while(nav)
        {
            if (searchElement(nav, e))
                return ;
            if((nav->val->value < e) && !nav->val->r)
            {
                nav->val->r = createLeaf(e);
                return ;
            }
            else if ((nav->val->value > e) && !nav->val->l)
            {
                nav->val->l = createLeaf(e);
                return ;
            }
            nav = nav->next;
        }
        while (*l)
        {
            if ((*l)->val->r)
                l2 = adjq(l2, (*l)->val->r);
            if ((*l)->val->l)
                l2 = adjq(l2, (*l)->val->l) ;
            *l = (*l)->next ;
        }
        LevTinsert(&l2, e);
    }
    else
        return ;
}

void insertIntoBST(tree *t, int e)
{
    //insert into the first free position of t
    if (!(*t))
    {
        *t = createLeaf(e) ;
    }
    list l = createnode(*t);
    LevTinsert(&l, e);
}

tree fillBSTfromSortedArray(int *a, int n, tree t)
{
    int k = n / 2 ;
    for (int i = 0 ; i + k < n ; i++)
    {
        insertIntoBST(&t, a[k + i]);
        insertIntoBST(&t, a[k - i]);
    }
    if (n % 2 == 0)
        insertIntoBST(&t, a[0]) ;
    return t ;
}