#include <stdio.h>
#include <stdlib.h> 


struct node
{
  int val;
  struct node *next;
};
typedef struct node Node;
typedef Node *list;


void printlist(list l)
{
  if (l)
  {
    printf("%d ", l->val);
    printlist(l->next);
  } 
}

list createnode(int x)
{
  list l;
  l = (list)malloc(sizeof(node));
  l->val = x;
  l->next = NULL;
  return l;
}

list adjt(list l, int e)
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

list adjq(list l, int e)
{
  if (!l)
    return adjt(l, e);
  else
    return adjt(adjq(l->next, e), l->val);
}

list readList(list l, int n)
{
  if (n)
  {
    int x;
    scanf("%d", &x);
    l = createnode(x);
    l->next = readList(l->next, n - 1);
  }
  else
    return l;
}


//EX3


list ExtraitInf(list *p, int n)
{
  list temp;
  if (!(*p))
  {
    return NULL;
  }
  else if ((*p)->val < n)
  {
    list tem = adjt(ExtraitInf(&((*p)->next), n), (*p)->val);
    list lt =  *p;
    *p = (*p)->next;
    free(lt);
    return tem;
  }
  else
    return ExtraitInf(&((*p)->next), n);
}


int main()
{
  list l1, l2;
  l1 = readList(l1, 5);
  l2 = ExtraitInf(&l1, 4);
  printlist(l2);
  return 0;
}
