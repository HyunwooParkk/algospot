#include <stdio.h>

/*
2
4 7 2 3
##.##..
#......
#....##
#..####
###
#..
5 10 3 3
..........
..........
..........
..........
..........
.#.
###
..#


3
8
*/
int H, W;
char board[21][21];
int spaceCount; //.의 갯수

// 4가지 조각의 상대적 위치
// block[조각번호][점번호][y,x]
const int block[4][3][2] = {
   { { 0,0 },{ 0,1 },{ 1,1 } },
{ { 0,0 },{ 0,1 },{ 1,0 } },
{ { 0,0 },{ 1,0 },{ 1,1 } },
{ { 0,0 },{ 1,0 },{ 1,-1 } }
};

int inBoard(int y, int x)
{
	if(y<0 || y>=H || x<0 ||x>=W)
		return 0;
	else
		return 1;
}
int blockCheck(int y, int x, int blockCase)
{
	int blockNum;
	for(blockNum=0; blockNum<3; blockNum++)
	{
		int newY=y+block[blockCase][blockNum][0];
		int newX=x+block[blockCase][blockNum][1];
		if(inBoard(newY, newX)!=1 || board[newY][newX]!='.')
			return 0;
	}

	return 1;
}

void fillBlock(int y, int x,int blockCase, char shape)
{
	int blockNum;
	for(blockNum=0; blockNum<3; blockNum++)
	{
		int newY=y+block[blockCase][blockNum][0];
		int newX=x+block[blockCase][blockNum][1];

		board[newY][newX]=shape;
	}
}


int countCover(int y, int x)
{
	int ret=0;
	int blockCase;
	if(y==H)
		return 1;
	if(x==W)
		return countCover(y+1,0);

	if(board[y][x]!='.')
		return countCover(y,x+1);

	for(blockCase=0; blockCase<4; blockCase++)
	{
		if(blockCheck(y,x,blockCase)==1)
		{
			fillBlock(y,x,blockCase,'#');
			spaceCount-=3;
			ret+=countCover(y,x+1);
			spaceCount+=3;
			fillBlock(y,x,blockCase,'.');
		}

	}
	return ret;
}


int main()
{
	int C,i,j,k;
	int way[10];
	scanf("%d", &C);
	for(k=0; k<C; k++)
	{
		scanf("%d %d", &H, &W);
		spaceCount=0;

		for(i=0; i<H; i++)
		{
			for(j=0; j<W; j++)
			{
				scanf(" %c", &board[i][j]);
				if(board[i][j]=='.')
					spaceCount++;
			}
		}
		printf("%d\n",countCover(0,0));
	}
	//for(i=0; i<C; i++)
		//printf("%d\n", way[i]);

	return 0;
}
		

