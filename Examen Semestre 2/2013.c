#include "../Mylibs/Tree_lib.h"
#include "../Mylibs/List_lib.h"


void sortpile(pile *p)
{
    pile pt = newPile();
    int m, n = pileLength(*p);
    for (int i = n ; i >= 1 ; i--)
    {
        m = tetePile(*p);
        for (int j = 0 ; j < i ; j++)
        {
            if (m < tetePile(*p))
                m = tetePile(*p);
            empiler(&pt, tetePile(*p));
            depiler(p);

        }
        empiler(p, m);
        while(!emptyPile(pt))
        {
            if (tetePile(pt) != m)
                empiler(p, tetePile(pt));
            depiler(&pt);
        }

    }
}
int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    pile p = newPile();
    empiler(&p, 1);
    empiler(&p, 8);
    empiler(&p, 7);
    empiler(&p, 4);
    empiler(&p, 5);
    empiler(&p, 2);
    empiler(&p,888);
    printPile(p);
    sortpile(&p);
    printPile(p);


}
