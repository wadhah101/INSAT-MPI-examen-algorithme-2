#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val, rang ;
    struct node *next ;
} node, *list;

list newList()
{
    return NULL ;
}

list empiler_nd(list l, int x)
{
    list temp ;
    temp = (list)malloc(sizeof(node));
    temp->val = x ;
    temp->rang = 0 ;
    temp->next = l ;
    return temp ;
}


list Rech_max(list l)
{
	list nav = l ,max = l ;
	while (nav)
	{
		if (nav->rang == 0)
		{
			max = nav ;
			break ;
		}
		nav  = nav->next ;
	}
	while (nav)
	{
		if ((nav->val > max->val) && (nav->rang == 0))
			max = nav ;
		nav = nav->next;
	}


	return max;

}

typedef struct node2
{
    list point ;
    struct node2 *next ;
} node2, *list2;


list2 empiler_pnt(list2 l2, list x)
{
    list2 temp ;
    temp = (list2)malloc(sizeof(node2));
    temp->point = x ;
    temp->next = l2 ;
    return temp ;
}

void Affiche_ntrier_trier(list l, int n)
{
	list2  l2 = NULL  ;
    int rang = 1 ;
    for (int i = 0 ; i < n ; i++)
    {
    	list temp;
    	temp = Rech_max(l) ;
        temp->rang = rang ;
        rang ++ ;
        l2 = empiler_pnt(l2,temp);
    }
    for (int i = 0 ; i <n ; i++)
    {
    	printf("%d :  %d\n",l->val,l->rang);
    	l = l->next;
    }
    for (int i = 0 ; i<n ; i++)
    {
    	printf("%d  ",l2->point->val);
    	l2 = l2->next ; 
    }
}




int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    int n, x;
    list l  = newList();
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++)
    {
        scanf("%d", &x);
        l = empiler_nd(l, x);
    }
    Affiche_ntrier_trier(l,n);
}