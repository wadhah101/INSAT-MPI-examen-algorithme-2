#include "../../Mylibs/list.h"
#include "../../Mylibs/tree.h"
//ex3
int egaux (tree a, tree b)
{
    if (!a && !b)
        return 1 ;
    if (a && !b)
        return 0 ;
    if (!a && b)
        return 0 ;
    if (a->data != b->data)
        return 0 ;
    return egaux(a->l, b->l) * egaux(a->r, b->r);
}

//EX2
pile pairPile(pile *p1)
{
    pile p2 = creatPile();
    file f = newFile() ;
    while(!emptyPile(*p1))
    {
        if (tetePile(*p1) % 2 == 0)
        {
            empiler(&p2, tetePile(*p1));
            depiler(p1);
        }
        else
        {
            emfiler(&f, tetePile(*p1));
            depiler(p1);
        }
    }
    while(!emptyFile(f))
    {
        empiler(p1, teteFile(f));
        defiler(&f);
    }
    while (!emptyPile(*p1))
    {
        emfiler(&f, tetePile(*p1));
        depiler(p1);
    }
    while(!emptyFile(f))
    {
        empiler(p1, teteFile(f));
        defiler(&f);
    }
    while (!emptyPile(p2))
    {
        emfiler(&f, tetePile(p2));
        depiler(&p2);

    }
    while(!emptyFile(f))
    {
        empiler(&p2, teteFile(f));
        defiler(&f);
    }
    return p2 ;
}

int main()
{
	freopen("../in.txt","r+",stdin);
	freopen("../out.txt","w+",stdout);

}
