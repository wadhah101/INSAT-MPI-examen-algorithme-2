#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int value ;
    struct node *next ;
} node, *pile ;


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
    y->value = n ;
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
    return p->value ;
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
    temp->value = n ;
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
    return f.first->value;
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

int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    printf("Partie pile\n");
    pile p = creatPile();
    printf("Pile initiale: ");
    piler(&p, 100);
    piler(&p, 50);
    piler(&p, 0);
    printpile(p);
    printf("Pile empiler: ");
    piler(&p, 10);
    printpile(p);
    printf("Pile depiler: ");
    depiler(&p);
    printpile(p);
    printf("Longeur de Pile : %d\nPile apres Longeur Pile :", LongeurPile(p));
    printpile(p);
    printf("\nPartie File\n");
    file f = creatFile();
    printf("File initiale: ");
    enfiler(&f, 89);
    enfiler(&f, 90);
    enfiler(&f, 5);
    printFile(&f);
    enfiler(&f, 100);
    enfiler(&f, 1008);
    printf("File apres enfiler: ");
    printFile(&f);
    defiler(&f);
    defiler(&f);
    printf("File apres 2 defiler: ");
    printFile(&f);
    printf("Longeur de File: %d\n", LongeurFile(&f));
    return 0 ;


    //k
}