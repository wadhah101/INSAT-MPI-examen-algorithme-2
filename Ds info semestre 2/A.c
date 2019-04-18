#include <stdio.h>
#include <stdlib.h>

int mypow(int x , int n)
{
	if (n == 0)
		return(1);
	else 
	{
		if (n%2)
			return(mypow(x,n/2)*mypow(x,n/2)*x);
		else 
			return(mypow(x,n/2)*mypow(x,n/2));

			
	}
}

int fib (int n)
{
	int A = 0 ,  B = 1 ,C ;
	if (!n)
		return 0 ; 
	else 
	{
	//	n-- ; 
		while(--n)
			{
			C = B ;
			B = B + A ; 
			A = C ;
		}
	}
	return B ; 
}

int main()
{
	freopen("in.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
	printf("%d",fib(14));
  return 0;
}
