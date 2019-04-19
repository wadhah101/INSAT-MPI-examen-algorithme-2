#include <bits/stdc++.h>
#define bint int64_t  ; 

using namespace std ; 

void cinArray(int *a,int n)
{
	for (int i = 0 ; i<n ; ++i)
		cin >> a[i] ; 
}

void coutArray (int *a,int n)
{
	for (int i = 0 ; i<n ; ++i)
		cout << a[i] ; 
}

int main()
{
	freopen("in.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0) ; 
}
