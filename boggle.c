#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int dx[]={-1,0,1,1,1,0,-1,-1};
int dy[]={-1,-1,-1,0,1,1,1,0};

char *substr(char*word){
	int len=strlen(word);
	char*tmp=(char*)malloc(sizeof(char)*len);
	strcpy(tmp,word+1);
	return tmp;
}

int inRange(int y, int x){
	if(x<0 || x>4 || y<0 ||y>4 )
		return 0;
	else
		return 1;
}

int hasWord(int y, int x, char* word, char board[5][6]){
	int d;
	if(!inRange(y,x))
		return 0;
	if(board[y][x]!=word[0])
		return 0;
	if(strlen(word)==1)
		return 1;
	for(d=0; d<8; d++)
	{
		int nextY=y+dy[d];
		int nextX=x+dx[d];

		if(hasWord(nextY,nextX,substr(word),board))
			return 1;
	}
	return 0;
}
int main(void)
{
	int c,n,i,q,qq,k,x,y,j;
	char**word;
	scanf("%d", &c);
	if(c>50)
		return -1;
	for(i=0; i<c; i++)
	{
		char board[5][6];
		for(j=0 ;j<5 ;j++)
		{
			scanf("%s",board[j]);
		}
		scanf("%d",&n);
		if(n>10 || n<1)
			return -1;
		word=(char**)malloc(sizeof(char*)*n);
		for(q=0 ; q<n; q++)
			word[q]=(char*)malloc(sizeof(char)*11);
		for(qq=0; qq<n; qq++)
		{
			scanf("%s",word[qq]);
		}
		for(k=0; k<n; k++)
		{
			int chk=0;
			for(x=0; x<5; x++)
			{
				for(y=0; y<5; y++)
				{
					chk=hasWord(y,x,word[k],board);
					if(chk)
						break;
				}
				if(chk)
					break;
			}
			printf("%s ",word[k]);
			if(chk)
				printf("YES\n");
			else
				printf("NO\n");
			free(word[k]);
		}
	}
	return 0;
}