#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

char arr1[100],arr2[100];
int arr3[100][100];

int wildcard(int c,int d,  int x, int y)
{
	if(x==c && y==d)
		return 1;

	int& ret=arr3[x][y];


	if(ret != -1)
		return ret;

	if(arr1[x]=='*')
	{
		for(int j=y; j<=d; j++)
			if(wildcard(c,d,x+1,j)==1)
			{
				printf("%d \n", x);
				return ret=1;
			}
	}

	if(x<c && y<d && (arr1[x]==arr2[y] || arr1[x]=='?'))
		return ret= wildcard(c,d,x+1,y+1);


	printf(" %d %d \n", x, y);
	return ret=0;
}

int main(void)
{
	int C,c;
	scanf("%d " ,&C);
	vector <string> ret;

	for(int i=0; i<C; i++)
	{
		scanf("%s" , arr1);
		scanf("%d", &c);
		int a=strlen(arr1); 
		vector<string> temp;

		for (int j=0; j<c; j++)
		{
			memset(arr3,-1,sizeof(arr3));
			scanf("%s",arr2);
			int f=strlen(arr2);
			if(wildcard(a,f,0,0)==1)
				temp.push_back(arr2);
		}
		sort(temp.begin(),temp.end());
		for(int j=0;  j<temp.size(); j++)
			ret.push_back(temp[j]);
	}
	for(int i=0; i<ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}
