#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node, *list, *pile;

void printlist(list l)
{
    if (l)
    {
        printf("%d ", l->data);
        printlist(l->next);
    }
    else
        printf("\n");
}

list newNode(int x)
{
    list l;
    l = (list)malloc(sizeof(node));
    l->data = x;
    l->next = NULL;
    return l;
}

list adjt(list l, int e)
{
    if (!l)
    {
        l = newNode(e);
        return l;
    }
    list temp = newNode(e);
    temp->next = l;
    return temp;
}

list adjq(list l, int e)
{
    if (!l)
        return adjt(l, e);
    else
        return adjt(adjq(l->next, e), l->data);
}

list readList(list l, int n)
{
    if (n)
    {
        int x;
        scanf("%d", &x);
        l = newNode(x);
        l->next = readList(l->next, n - 1);
    }
    else
        return l;
}


pile newPile()
{
    return NULL ;
}

int emptyPile(pile p)
{
    return p == NULL ;
}

void empiler(pile *p, int n)
{
    pile y = (pile)malloc(sizeof(node)) ;
    y->data = n ;
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
    return p->data ;
}

int pileLength(pile p)
{
    int num = 0 ;
    pile q = newPile();
    while(p)
    {
        num ++ ;
        empiler(&q, tetePile(p));
        depiler(&p);
    }
    while(q)
    {
        empiler(&p, tetePile(q));
        depiler(&q);
    }
    return num ;
}

void printPile(pile p)
{
    pile q = newPile();
    while(p)
    {
        printf("%d ", tetePile(p));
        empiler(&q, tetePile(p));
        depiler(&p);
    }
    while(q)
    {
        empiler(&p, tetePile(q));
        depiler(&q);
    }
    printf("\n");
}

//file
typedef struct file
{
    struct node *first, *last ;
} file;

file newFile()
{
    file temp ;
    temp.first = NULL ;
    temp.last = NULL ;
    return temp ;
}

int emptyFile(file f)
{
    return (f.first == NULL && f.last == NULL) ;
}

void emfiler(file *f, int n)
{
    node *temp ;
    temp = (node *)malloc(sizeof(node));
    temp->data = n ;
    temp->next = NULL;
    if (emptyFile(*f))
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
    if (emptyFile(*f))
        return ;
    if (f->first == f->last)
    {
        free(f->first);
        *f = newFile();
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
    return f.first->data;
}

int LongeurFile(file *f)
{
    int num = 0 ;
    file g = newFile() ;
    while(!emptyFile(*f))
    {
        emfiler(&g, teteFile(*f));
        defiler(f);
        num ++ ;
    }
    while(!emptyFile(g))
    {
        emfiler(f, teteFile(g));
        defiler(&g);
    }
    return num ;
}

void printFile(file *f)
{
    file g = newFile() ;
    while(!emptyFile(*f))
    {
        printf("%d ", teteFile(*f));
        emfiler(&g, teteFile(*f));
        defiler(f);
    }
    while(!emptyFile(g))
    {
        emfiler(f, teteFile(g));
        defiler(&g);
    }
    printf("\n");
}

