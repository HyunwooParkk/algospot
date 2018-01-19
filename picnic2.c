#include <stdio.h>

int c,C ; //���̽� ��
int n,m,m_idx; //�л� ��, �л� �� 
int f[10][10]; //i,j�� ģ�����̸� f[i][j]==f[j][i]==1
int match[10]; //¦�� ������ ����� 1, �������� ����� 0

int countPairings(int match[10])
{
	int i,j;
	int finish=1,ret=0;

	for(i=0; i<n ;i++)
		if(match[i]!=1)
			finish=-1;

	if(finish==1)
		return 1;
	for(i=0; i<n ; i++)
		for(j=0; j<n; j++)
		{
			if(match[i]!=1 && match[j]!=1 && f[i][j]==1){
				match[i]=match[j]=1;
				ret+=countPairings(match);
				match[i]=match[j]=0;
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