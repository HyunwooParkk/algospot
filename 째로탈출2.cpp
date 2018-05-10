/*
5 5
#####
#..B#
#.#.#
#RO.#
#####

1

7 7
#######
#...RB#
#.#####
#.....#
#####.#
#O....#
#######

5

7 7
#######
#..R#B#
#.#####
#.....#
#####.#
#O....#
#######

5


10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.#.#..#
#...#.O#.#
##########

-1
3 7
#######
#R.O.B#
#######

1


10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.##...#
#O..#....#
##########

7


3 10
##########
#.O....RB#
##########

-1
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int INF=98765431;
const int MAX=10;
	
int row, col;
int minCnt=INF;
int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};

typedef struct
{
	int y, x;
}Coord;

void tilt(string board[MAX], int dir, int cnt, Coord R, Coord B)
{
	if(cnt>10)
		return;

	string copy[MAX];
	for(int i=0; i<col ; i++)
		copy[i]=board[i];

	bool red= false, blue =false;
	int order=0;
	switch(dir)
	{
	case 0:
		if(B.y<R.y)
			order=1;
		break;
	case 1:
		if(B.x<R.x)
			order=1;
		break;
	case 2:
		if(R.x<B.x)
			order=1;
		break;
	case 3:
		if(R.y<B.y)
			order=1;
		break;
	}
	if(order==0)
	{
		while(1)
		{
			int nextY=R.y+dy[dir];
			int nextX=R.x+dx[dir];
			if(copy[nextY][nextX]=='#')
				break;
			if(copy[nextY][nextX]=='0')
			{
				copy[R.y][R.x]='.';
				R.y=R.x=-1;
				red=true;
				break;
			}
			copy[R.y][R.x]='.';
			copy[nextY][nextX]='R';
			R.y=nextY;
			R.x=nextX;

		}
		while(1)
		{
			int nextY=B.y+dy[dir];
			int nextX=B.x+dx[dir];
			if(copy[nextY][nextX]=='#' || copy[nextY][nextX]=='R')
				break;
			if(copy[nextY][nextX]=='0')
			{
				copy[B.y][B.x]='.';
				B.y=B.x=-1;
				blue=true;
				break;
			}
			copy[B.y][B.x]='.';
			copy[nextY][nextX]='B';
			B.y=nextY;
			B.x=nextX;	
		}
	}
	else
	{
		while(1)
		{
			int nextY=B.y+dy[dir];
			int nextX=B.x+dx[dir];
			if(copy[nextY][nextX]=='#')
				break;
			if(copy[nextY][nextX]=='0')
			{
				copy[B.y][B.x]='.';
				B.y=B.x=-1;
				blue=true;
				break;
			}
			copy[B.y][B.x]='.';
			copy[nextY][nextX]='B';
			B.y=nextY;
			B.x=nextX;
		}
		while(1)
		{
			int nextY=R.y+dy[dir];
			int nextX=R.x+dx[dir];
			if(copy[nextY][nextX]=='#' || copy[nextY][nextX]=='B')
				break;
			if(copy[nextY][nextX]=='0')
			{
				copy[R.y][R.x]='.';
				R.y=R.x=-1;
				red=true;
				break;
			}
			copy[R.y][R.x]='.';
			copy[nextY][nextX]='R';
			R.y=nextY;
			R.x=nextX;
		}
	}
	if(blue)
		return;
	else if(red)
	{
		minCnt=min(cnt,minCnt);
		return;
	}
	for(int i=0; i<4 ;i++)
		if(i != dir || i != (3-dir))
			tilt(copy,i,cnt+1,R,B);
}
int main(void)
{
	Coord R, B;
	string board[MAX];
	cin >> col >> row;
	if(col <3 || col > 10 || row < 3 || row > 10)
		exit(-1);

	for(int i=0; i<col ;i++)
	{
		cin >> board[i];
		for(int j=0; j<row; j++)
			if(board[i][j] == 'R')
				R.y=i, R.x=j;
			else if(board[i][j]=='B')
				B.y=i, B.x=j;
	}
	printf("dsafadsf\n");
	for(int i=0 ; i<4 ;i++)
		tilt(board, i, 0, R, B);

	
	if(minCnt==INF)
		cout << -1 << endl;
	else
		cout << minCnt << endl;
	return 0;

}