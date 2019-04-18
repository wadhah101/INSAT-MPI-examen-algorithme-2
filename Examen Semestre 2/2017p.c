#include "../Mylibs/List_lib.h"

//EX1
typedef struct nodeC
{
    int val ;
    int num ;
    struct nodeC *next ;
} nodeC, *listC;

listC createnodeC(int x)
{
    listC l;
    l = (listC)malloc(sizeof(nodeC));
    l->val = x;
    l->num = 1;
    l->next = NULL;
    return l;
}

listC adjtC(listC l, int e)
{
    if (!l)
    {
        l = createnodeC(e);
        return l;
    }
    listC temp = createnodeC(e);
    temp->next = l;
    return temp;
}

void printlistC(listC l)
{
    if (l)
    {
        printf("(%d , %d) ", l->val, l->num);
        printlistC(l->next);
    }
    else
        printf("\n");
}

listC compression(list l)
{
    if (!l)
        return NULL ;
    else
    {
        listC li = compression(l->next);
        if (!li)
        {
            return createnodeC(l->val);
        }
        if (l->val == li->val)
        {
            li->num ++ ;
            return li ;
        }
        else
            return adjtC(li, l->val);
    }
}

list decompression(listC li)
{
    if (!li)
        return NULL ;
    else
    {
        list l = decompression(li->next);
        for (int i = 0 ; i < li->num; i++)
            l = adjt(l, li->val);
        return l ;
    }

}

int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    list l = readList(l, 16);
    printlist(l);
    listC li = compression(l);
    printlistC(li);
    list lk = decompression(li);
    printlist(lk);
}
