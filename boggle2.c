#include <stdio.h>
#include <string.h>

int dx[]={-1,0,1,1,1,0,-1,-1};
int dy[]={-1,-1,-1,0,1,1,1,0};
char map[6][6];
char voca[11];
int T,t,len;

int search(int y, int x,int index)
{
	int i;
	if(map[y][x]!=voca[index])
		return 0;
	if(map[y][x]==voca[len-1] && index==len-1)
		return 1;

	for(i=0; i<8 ; i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<=6 && xx>=1 && yy<=6 && yy>=1)
		{
			if(search(yy,xx,index+1)==1)
				return 1;

		}
	}
	return 0;
}

int main()
{
	int i,j;
	
	scanf("%d",&T);
	getchar();
	while(T--){
		memset(map,0,sizeof(map));
		for(i=1; i<=5; i++)
		{
			for(j=1; j<=5; j++)
			{
				scanf("%c", &map[i][j]);
			}
			getchar();
		}
	}	
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		int flag=0;
		memset(voca,0,sizeof(voca));
		scanf("%s",voca);
		getchar();
		len=strlen(voca);
		for(i=1; i<=5; i++)
		{
			for(j=1; j<=5; j++)
			{
				flag=search(i,j,0);
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("%s YES\n",voca);
		else
			printf("%s No\n", voca);
	}	
	return 0;
}