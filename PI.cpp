#include<iostream>
#include<vector>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[1000];
char S[100];
int n;

int Comp(int start, int end)
{
	int same=true;
	for(int i=start; i<end-1; i++)
	{
		if(S[i] != S[i+1])
		{
			same=false;
			break;
		}
	}
	if(same)
		return 1;

	int alter=true;
	for(int i=start; i<end-2; i++)
	{
		if(S[i] != S[i+2])
		{
			alter=false;
			break;
		}
	}
	if(alter)
		return 4;
	
	int seq=true;
	for(int i=start; i<end-1; i++)
	{
		if(S[i+1]-S[i]!=S[start+1]-S[start])
		{
			seq=false;
			break;
		}
	}
	if(seq && abs(S[start+1]-S[start])==1)
		return 2;
	
	if(seq )
		return 5;

	return 10;
}

int PI(int idx)

{
	if(idx==n)
		return 0;

	int &ret= cache[idx];
	if(ret != -1)
		return ret;
	
	ret=1000000000;

	/*
	어차피 sequential하게 코드가 돌면서 결론적으로는 return ret이 되므로, 중간에 100000의 값이 나온다.
	*/
	for(int i=3; i<=5; i++)
			if(i+idx <=n)
				ret=min(Comp(idx,idx+i)+PI(idx+i), ret);

	return ret;
}
int main(void)
{
	int c;
	cin >> c;
	int arr[1000];

	for(int i=0; i<c; i++)
	{
		cin>>S;

		n=strlen(S);
		for(int j=0; j<n; j++)
			cache[j]=-1;
		arr[i]=PI(0);

		
	}

	for(int i=0; i<c; i++)
		printf("%d\n", arr[i]);
	return 0;
}