#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int C,c,H,W;
char arr[20][20];
int coverType[4][3][2]={
{{0,0},{1,0},{0,1}},
{{0,0},{0,1},{1,1}},
{{0,0},{1,0},{1,1}},
{{0.0},{1,0},{1,-1}}
};



int func()
{ 
	int i_now=-1, j_now=-1, i, j,ret=0;// 아직 채우지 못한 첫줄 찾는다.

	for(i=0; i<H; i++)
	{
		for(j=0; j<W; j++)
			if(arr[i][j]=='.')
			{
				i_now=i;
				j_now=j;
				break;
			}
			if(i_now!=-1)
				break;
	}
	if(i_now==-1)
		return 1;

	for(i=0; i<4; i++)
	{
			if(i_now>=0 && j_now>=0 && i_now<H && j_now<W && arr[i_now+coverType[i][0][0]][j_now+coverType[i][0][1]]=='.' 
				&&arr[i_now+coverType[i][1][0]][j_now+coverType[i][1][1]]=='.' && arr[i_now+coverType[i][2][0]][j_now+coverType[i][2][1]]=='.')
			{
				arr[i_now][j_now]=arr[i_now+coverType[i][0][0]][j_now+coverType[i][0][1]]=arr[i_now+coverType[i][1][0]][j_now+coverType[i][1][1]]=
					arr[i_now+coverType[i][2][0]][j_now+coverType[i][2][1]]='#';
				ret+=func();
				arr[i_now][j_now]=arr[i_now+coverType[i][0][0]][j_now+coverType[i][0][1]]=arr[i_now+coverType[i][1][0]][j_now+coverType[i][1][1]]=
					arr[i_now+coverType[i][2][0]][j_now+coverType[i][2][1]]='.';
			}
	}
	return ret;
		
}
int main(void)
{
	int i;
	int k[10];
	scanf("%d",&C);
	for(c=0; c<C; c++)
	{	
		scanf("%d %d", &H, &W);
		for(i=0; i<H; i++)
			scanf("%s",arr[i]);
		
		k[c]=func();
	 }

	for(i=0; i<C; i++)
		printf("%d\n", k[i]);
	return 0;
}


