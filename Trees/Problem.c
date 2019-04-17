#include "stdio.h"
#include "stdlib.h"
#include "TreesLib.h"


void LevT(list l)
{
	list l2 = NULL ; 
	if (l)
	{
		//traitement sur l
		printlist(l);
		printf("\n");
		while (l)
		{
			if (l->val->r)
				l2 = adjq(l2,l->val->r);
			if (l->val->l)
				l2 = adjq(l2,l->val->l)	;	
			l = l->next ; 		
		}
		LevT(l2);
	}
	else 
		return ; 
}

void levelOrderTraversal(tree t)
{
    list l = createnode(t);
    LevT(l);
}


int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    tree t = createLeaf(8);
    t->l = createLeaf(3);
    t->r = createLeaf(10);
    t->r->r = createLeaf(14);
    t->r->r->l = createLeaf(13);
    t->l->l = createLeaf(1);
    t->l->r = createLeaf(6);
    t->l->r->l = createLeaf(4);
    t->l->r->r = createLeaf(8);
     levelOrderTraversal(t);
 //   tree q = NULL ; 
  //  int a[] = {1,4,5,6,8,20,78,100,200,700,800,5000,10000} ; 
   // levelOrderTraversal(q);

}
