#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}node ,*list,*pile;

void printlist(list l)
{
    if (l)
    {
        printf("%d ", l->val);
        printlist(l->next);
    }
    else 
        printf("\n");
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


pile creatPile()
{
    return NULL ;
}

int PileVide(pile p)
{
    return p == NULL ;
}

void piler(pile *p, int n)
{
    pile y = (pile)malloc(sizeof(node)) ;
    y->val = n ;
    y->next = *p ;
    *p = y ;
}

void depiler(pile *p)
{
    pile t = *p ;
    *p = (*p)->next;
    free(t);
}

int tetePile(pile p)
{
    return p->val ;
}

int LongeurPile(pile p)
{
    int num = 0 ;
    pile q = creatPile();
    while(p)
    {
        num ++ ;
        piler(&q, tetePile(p));
        depiler(&p);
    }
    while(q)
    {
        piler(&p, tetePile(q));
        depiler(&q);
    }
    return num ;
}

void printpile(pile p)
{
    pile q = creatPile();
    while(p)
    {
        printf("%d ", tetePile(p));
        piler(&q, tetePile(p));
        depiler(&p);
    }
    while(q)
    {
        piler(&p, tetePile(q));
        depiler(&q);
    }
    printf("\n");
}

//file
typedef struct file
{
    struct node *first, *last ;
} file;

file creatFile()
{
    file temp ;
    temp.first = NULL ;
    temp.last = NULL ;
    return temp ;
}

int VideFile(file f)
{
    return (f.first == NULL && f.last == NULL) ;
}

void enfiler(file *f, int n)
{
    node *temp ;
    temp = (node *)malloc(sizeof(node));
    temp->val = n ;
    temp->next = NULL;
    if (VideFile(*f))
    {
        f->last = temp ;
        f->first = temp ;
    }
    else
    {
        f->last->next = temp ;
        f->last = temp ;
    }
}

void defiler(file *f)
{
    if (f->first == f->last)
    {
        free(f->first);
        *f = creatFile();
    }
    else
    {
        node *t = f->first ;
        f->first = f->first->next ;
        free(t);
    }
}

int teteFile(file f)
{
    return f.first->val;
}

int LongeurFile(file *f)
{
    int num = 0 ;
    file g = creatFile() ;
    while(!VideFile(*f))
    {
        enfiler(&g, teteFile(*f));
        defiler(f);
        num ++ ;
    }
    while(!VideFile(g))
    {
        enfiler(f, teteFile(g));
        defiler(&g);
    }
    return num ;
}

void printFile(file *f)
{
    file g = creatFile() ;
    while(!VideFile(*f))
    {
        printf("%d ", teteFile(*f));
        enfiler(&g, teteFile(*f));
        defiler(f);
    }
    while(!VideFile(g))
    {
        enfiler(f, teteFile(g));
        defiler(&g);
    }
    printf("\n");
}

