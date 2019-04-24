#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct leaf
{
    struct leaf *a[26] ;
    int statue ;
} leaf, *tree ;


//EX3
tree newLeaf(int statue)
{
    tree t = (tree)malloc(sizeof(leaf));
    t->statue = statue ;
    for (int i = 0 ; i < 26 ; i++)
        t->a[i] = NULL;
    return t ;
}


tree buildTree(tree t, char *s)
{
    if (strlen(s) != 1)
    {
        if (!t->a[s[0] - 'a'])
            t->a[s[0] - 'a'] = newLeaf(0);
        t->a[s[0] - 'a'] = buildTree(t->a[s[0] - 'a'], s + 1);
    }
    else
    {
        if (!(t->a[s[0] - 'a']))
            t->a[s[0] - 'a'] = newLeaf(1);
        else
            t->a[s[0] - 'a']->statue = 1 ;
    }
    return t;
}

int nbtool(tree t, int l)
{
    int k = 0;
    if (!t)
        return 0;
    if (l == 1)
    {
        for (int i = 0; i < 26; i++)
            if (t->a[i])
            {
                if(t->a[i]->statue == 1)
                    k++ ;
            }
        return k ;
    }
    for (int i = 0 ; i < 26 ; i++)
        if (t->a[i])
            k += nbtool(t->a[i], l - 1);
    return k ;
}

int find(tree t ,char *s)
{
    if (!t)
        return 0 ; 
    if (t->a[s[0]-'a'])
    {
        if (strlen(s) == 1)
            return t->a[s[0]-'a']->statue ; 
        return find(t->a[s[0]-'a'],s+1);
    }
    return 0 ; 
}

int nbTotal(tree t)
{
    int k = 0 ; 
    if (!t)
        return 0 ; 
    if (t->statue == 1)
        k++ ; 
    for (int i = 0 ; i<26;i++)
        k += nbTotal(t->a[i]);
    return k ; 
}

int nbmot(tree t, int l)
{
    int k = nbtool(t, l);
    if (k)
        return k ;
    return nbTotal(t);
}
int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    char s[500];
    tree t = newLeaf(0);
    for (int i = 0 ; i < 4 ; i++)
    {
        scanf("%s", s);
        t = buildTree(t, s);
    }
    printf("%d\n",find(t,"abb"));
}