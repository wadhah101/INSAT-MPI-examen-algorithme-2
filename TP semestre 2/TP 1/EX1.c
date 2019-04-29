#include <stdio.h>
#include <stdlib.h>

typedef struct noeud 
{
	int val ;
	struct  noeud* next ; 
}noeud ; 

typedef noeud *list ;

list creer()
{
	return NULL;
}

list readList(list l , int n)
{

	if (n)
		 {
		 	int x ;
			scanf("%d",&x);
		 	l = (list)malloc(sizeof(noeud));
		 	l->val = x ; 
		 	l->next  = readList(l->next,n-1);
		 }
	else 
		return NULL ; 
}

void printList(list l)
{
	while (l)
	{
      printf("%d ",l->val);
      l = l -> next  ;
    }
	
}

list insert(list l , int p,int e)
{
	int i = 1 ;
	if (p==1)
	{
		list temp ; 
		temp = (list)malloc(sizeof(noeud));
		temp -> val = e ;
		temp -> next = l ;
		return temp ; 
	}
	else 
	{
		list temp = l ; 
		while (i<(p-1) && (temp->next))
		{
			i++;
			temp = temp ->next ; 
		}
		if (i < (p-1))
		{
			printf("insertion impossible\n");
			return l ; 
		}
		else 
		{
		list newlist ;
		newlist = (list)malloc(sizeof(noeud));
		newlist->val = e ; 
		newlist->next = temp -> next ; 
		temp->next = newlist ;
		return l ; 
  	 	}
  	 }
	
}
list supp(list l , int p)
{
	int i = 1 ;
	if (p==1)
	{
		list temp = l->next ; 
		free(l);
		return temp ; 
	}
	else 
	{
		list temp = l ; 
		while (i<(p-1) && (temp->next->next))
		{
			i++;
			temp = temp ->next ; 
		}
		if (i < (p-1))
		{
			printf("suppression impossible\n");
			return l ; 
		}
		else 
		{
			list temp2 = temp ->next ; 
			temp ->next = temp -> next -> next ;
			free(temp2); 
		return l ; 
  	 	}

	}
}
int listlength(list l)
{
	int i = 0 ; 
	if (l)
	{
		while(l)
		{
			l = l->next ; 
			i++ ;
		}
	}
		return i ; 
}
int main()
{
	list l ; 
	//lire une liste de n element 
	l = readList(l,4);
	l = insert(l,5,90);
	printList(l);
	printf("\n");
	l = supp(l,5);
	printList(l);
	printf("\n");
	printf("la longueur de la liste est %d\n",listlength(l));
	return 0 ;
}
