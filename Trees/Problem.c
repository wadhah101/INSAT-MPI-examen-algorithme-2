#include "stdio.h"
#include "stdlib.h"
#include "TreesLib.h"

tree OrderedArraytoBST_Tree(int *h,int n)
{
	tree t = NULL ; 
	int a = n/2;
	t = insertIntoBST(t,h[a]) ;
	for (int i = 1 ; a+i <n ;i++)
	{
		t = insertIntoBST(t,h[a-i]) ;
		t = insertIntoBST(t,h[a+i]) ; 
	}
	if (n%2 == 0)
		t = insertIntoBST(t,h[0]) ;
	return t ; 
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
    //levelOrderTraversal(t);
    tree q = NULL ; 
    int a[] = {1,4,5,6,8,20,78,100,200,700,800,5000,10000} ; 
    q = OrderedArraytoBST_Tree(a,13) ; 
    levelOrderTraversal(q);

}
