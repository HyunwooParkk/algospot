#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
int cache[100],S[100];

int LIS(int start, int n)
{
	 int& ret=cache[start];
	 if(ret != -1)
		 return ret;
	 ret=1;
	 for(int next=start+1 ; next<n; next++)
		 if(S[start]<S[next])
			 ret=max(ret, LIS(next,n)+1);
	 return ret;
}

int main(void)
{
	int arr[100];
	int c,a;
	cin >> c ;
	for(int i=0; i<c; i++)
	{
		cin >>a;
		for(int j=0; j<a; j++)
			cin >> S[j];

		int maxLen=0;
		for(int k=0; k<a; k++)
			cache[k]=-1;
		for(int begin=0; begin<a; begin++)
			maxLen=max	(maxLen,LIS(begin,a));
		arr[i]=maxLen;
	}

	for(int i=0; i<c; i++)
		printf("%d\n", arr[i]);

	return 0;
}