/* This source has been formatted by an unregistered SourceFormatX */
/* If you want to remove this info, please register this shareware */
/* Please visit http://www.textrush.com to get more information    */

/* This source has been formatted by an unregistered SourceFormatX */
/* If you want to remove this info, please register this shareware */
/* Please visit http://www.textrush.com to get more information    */

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