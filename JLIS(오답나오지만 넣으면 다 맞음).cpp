#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
int cache[100],S[100],S1[100];

int IsFine(int k,int l,int a, int b)
{
	int ret=0;
	for(int i=k; i<a; i++)
	{
		for(int j=l; j<b; j++)
			if(S[i]==S1[j])
			{
				ret++;
			}
	}
	return ret;

}
int JLIS(int start, int n)
{
	 int& ret=cache[start];
	 if(ret!= -1) return ret;

	 ret= 1;
	 for(int next=start+1; next<n ;next++)
		 if(S[start]<S[next])
			 ret=max(ret,JLIS(next,n)+1);

	 return ret;
}

int main(void)
{
	int arr[100];
	int c, a,b;
	cin >> c;
	for(int i=0; i<c; i++)
	{
			cin >> a>>b;

			for(int j=0; j<a; j++)
			{
				cin >> S[j];
				cache[j]=-1;
			}
			int maxLen1[100];
			for(int begin=0; begin<a; begin++)
				maxLen1[begin]=JLIS(begin,a);

			for(int j=0; j<b; j++)
			{
				cin >> S1[j];
				cache[j]=-1;
			}
			int maxLen2[100];
			for(int begin=0; begin<b; begin++)
				maxLen2[begin]=JLIS(begin,b);

			int maxLen=0;
			for(int k=0; k<a; k++)
				for(int l=0; l<b; l++)
				{
					maxLen=max(maxLen,maxLen1[k]+maxLen2[l]-IsFine(k,l,a,b));
				}


			arr[i]=maxLen;

	}

	for(int i=0; i<c; i++)
		printf("%d\n", arr[i]);

	return 0;
}
