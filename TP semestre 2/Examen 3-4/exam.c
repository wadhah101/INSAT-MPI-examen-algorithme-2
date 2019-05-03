#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    double note1, note2, moy ;
    struct  node *next ;
} node, *pile;

pile newPile()
{
    return NULL ;
}
pile empiler(pile p, double note1, double note2 )
{
    pile ptemp;
    ptemp  = (pile)malloc(sizeof(node));
    ptemp->note1 = note1 ;
    ptemp->note2 = note2 ;
    ptemp->moy = (note1 + note2) / 2 ;
    ptemp->next = p ;
    return ptemp ;
}

pile depiler(pile p)
{
    pile ptemp  = p ;
    p = p->next ;
    free(ptemp);
    return p ;
}

int emptyPile(pile p)
{
    return p == NULL ;
}

pile deleteLesserThan10(pile p)
{
    pile ptemp = newPile() ;
    while (!emptyPile(p))
    {
        if (p->moy >= 10)
            ptemp = empiler(ptemp, p->note1, p->note2);
        p = depiler(p);
    }
    while(!emptyPile(ptemp))
    {
        p = empiler(p, ptemp->note1, ptemp->note2);
        ptemp = depiler(ptemp);
    }
    return p ;
}

void printPile(pile p)
{
    pile ptemp  = newPile();
    while(!emptyPile(p))
    {
        printf("Note1 = %2.2lf | Note2 = %2.2lf | moy = %2.2lf\n", p->note1, p->note2, p->moy);
        ptemp = empiler(ptemp, p->note1, p->note2);
        p = depiler(p);
    }
    while(!emptyPile(ptemp))
    {
        p = empiler(p, ptemp->note1, ptemp->note2);
        ptemp = depiler(ptemp);
    }

}

int main()
{
    int n ;
    double *a, *b ;
    printf("Saisir le nombre de note : ");
    scanf("%d", &n);
    a = (double *)malloc(sizeof(double) * n);
    b = (double *)malloc(sizeof(double) * n);
    for (int i = 0; i < n ; i++)
    {
        printf("note1[%d] = ", i + 1 );
        scanf("%lf", a + i);
    }
    printf("\n");
    for (int i = 0; i < n ; i++)
    {
        printf("note2[%d] = ", i + 1);
        scanf("%lf", b + i);
    }
    printf("\n");
    pile p = newPile();
    for (int i = 0 ; i < n ; i++)
    {
        p = empiler(p, a[i], b[i]);
    }
    printf("Affichage Pile:\n");
    printPile(p);
    printf("\nAffichage Pile apres la supression des noeud a moyenne inferieur a 10:\n");
    p = deleteLesserThan10(p);
    printPile(p);

}

