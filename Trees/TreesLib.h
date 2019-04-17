#include "stdio.h"
#include "stdlib.h"

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
void levelOrderTraversal(tree t)
{
    int l = treeHeight(t);
    for (int i = 0 ; i < l ; i++)
    {
        printlevel(t, i);
        printf("\n");
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
tree insertIntoBST(tree t, int n)
{
    if (!t)
      {
        t = createLeaf(n);
        return t; 
      }
    if (n > t->value)
    {
        if (!t->r)
        {
            t->r = createLeaf(n);
            return t ;
        }
        else
            t = adjd(t, insertIntoBST(t->r, n)) ;
    }
    else if (n < t->value)
    {
        if (!t->l)
        {
            t->l = createLeaf(n);
            return t ;
        }
        else
            t = adjg(t, insertIntoBST(t->l, n)) ;
    }
}

int treesum(tree t)
{
	if (!t)
		return 0 ;
	return t->value + treesum(t->l)+treesum(t->r) ;
}
int treemax(tree t)
{
	if (!t)
		return -1;
	return max (t->value,max(treemax(t->l),treemax(t->r))) ;
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
  l = (list)malloc(sizeof(node));
  l->val = x;
  l->next = NULL;
  return l;
}

list adjt(list l,tree e)
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