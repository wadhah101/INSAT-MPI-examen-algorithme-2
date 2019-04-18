#include "../../Mylibs/Pile_File.h"

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
    enfiler(&f, 990);
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
}