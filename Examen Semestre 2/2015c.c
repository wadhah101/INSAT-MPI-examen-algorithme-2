#include <stdio.h>
#include <stdlib.h>


int main()
{
	freopen("in.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
	for (int i = 8 ; i>=1 ;i--)
	{
		for (int j = i ; j>=1 ; j--)
			printf("1 ");
		printf("\n");
	}
}
