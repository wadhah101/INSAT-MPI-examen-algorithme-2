#include "../Mylibs/List_lib.h"
#include "../Mylibs/Tree_lib.h"
#include <limits.h>
//EX1

int nbfils(tree t)
{
	if (!t)
		return 0 ;
	if (t->r && !t->l)
		return 1 + nbfils(t->r);
	if (!t->r && t->l)
		return 1 + nbfils(t->l);
	return nbfils(t->r) + nbfils(t->l) ; 
}

//EX2
int perfectTree(tree t)
{
	if (!t)
		return 1 ; 
	if ((!t->r && t->l) || (!t->l && t->r))
		return 0 ; 
	if (treeHeight(t->r) != treeHeight(t->l))
		return 0 ; 
	else 
		return perfectTree(t->r)*perfectTree(t->l);
} 

int isBSTtool(tree t, int min , int max)
{
	if (!t)
		return 1 ; 
	if (t->value <= min || t->value >= max)
		return 0 ; 
	return isBSTtool(t->l,min,t->value)*isBSTtool(t->r,t->value,max);
}
int isBST(tree t)
{
	return isBSTtool(t,INT_MIN,INT_MAX);
}


int main()
{
	freopen("in.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
	tree t ; 
	t = creatLeaf(4);
	t->l = creatLeaf(2);
	t->r = creatLeaf(33);
	t->l->l = creatLeaf(1);
	t->l->r = creatLeaf(3);
	t->r->l = creatLeaf(22);
	t->r->r = creatLeaf(54);
	printTree(t);
	printf("%d\n",isBST(t) );
}
