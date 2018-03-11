#include <iostream>
using namespace std;

int board[100][100];
int cache[100][100];
#define TRUE 1;
#define FALSE 0;


int jump(int c, int a, int b){

	if(a>= c || b>= c)
		return 0;
	if(a==(c-1) && b==(c-1))
		return 1;
	int& ret = cache[a][b];

	if(ret != -1)
		return ret;
	
	int jumpsize=board[a][b];
	return ret=jump(c,a+jumpsize,b) || jump(c,a,b+jumpsize);

}

int main(void)
{
	int C,c;
	int i,j,k;
	int temp[100];
	scanf("%d", &C);
	for(i=0 ;i<C; i++)
	{
		scanf("%d",&c);


			for(j=0; j<c; j++)
				for(k=0; k<c; k++)
				{
				scanf("%d",&board[j][k]);
				cache[j][k]=-1;
				}



		temp[i]=jump(c,0,0);
	}

	for(int i=0; i<C; i++)
	{
		if(temp[i]==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}