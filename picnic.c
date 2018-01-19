#include <stdio.h>

int c,C ; //케이스 수
int n,m,m_idx; //학생 수, 학생 쌍 
int f[10][10]; //i,j가 친구사이면 f[i][j]==f[j][i]==1
int match[10]; //짝이 지어진 사람은 1, 안지어진 사람은 0

int countPairings(int match[10])
{
	int i;
	int firstFree=-1;
	int pairWith,ret=0;
	for(i=0; i<n; i++)
	{
		if(match[i]!=1){
			firstFree=i;
			break;
		}
	}
	if(firstFree==-1)
		return 1;
	for(pairWith=firstFree+1; pairWith<n; pairWith++)
	{
		if(match[pairWith]!=1 && f[firstFree][pairWith]==1)
		{
			match[firstFree]=match[pairWith]=1;
			ret +=countPairings(match);
			match[firstFree]=match[pairWith]=0;
		}
	}
	return ret;
}
int main(void)
{
	int i,j;
	int a,b;
	int way;
	scanf("%d", &C);
	for(c=0; c<C; c++)
	{
		scanf("%d %d", &n, &m);
		for(i=0; i<n; i++)
			for(j=i+1; j<n; j++)
				f[i][j]=f[j][i]=0;

		for(m_idx=0; m_idx<m; m_idx++)
		{
			scanf("%d %d", &a, &b);
			f[a][b]=f[b][a]=1;
		}

		for(i=0; i<10; i++)
			match[i]=0;
		way=countPairings(match);
		printf("%d\n",way);
	}
	return 0;
}