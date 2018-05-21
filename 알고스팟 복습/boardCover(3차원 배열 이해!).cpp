#include <iostream>
#include <cstring>

using namespace std;

/*
3���� �迭�� ���� �����ϴ°� �������,
����� ���� �� ���� ���� �� ����� �������� �����ǥ�� �����ϴ°� �򰥷ȴ�.
���� ���� �������� (0,0) ���� ���ư��� �������� �����ؾ��Ѵ�. 
*/
int C, H, W;
char arr[21][21];
int dx[4][2][3]=
{
	{{0,0,1},{1,0,0}},
	{{0,0,1},{0,1,1}},
	{{0,1,1},{0,0,1}},
	{{0,1,1},{0,0,-1}}
};

int boardcover()
{
	int temp_x=-1,temp_y=-1;
	int ret=0;

	for(int i=0; i<H; i++)
	{
		for(int j=0; j<W; j++)
		{
			if(arr[i][j]=='.')
			{
				temp_x=i;
				temp_y=j;
				break;
			}
		}
		if(temp_x != -1)
			break;
	}

	if(temp_x==-1 && temp_y ==-1)
	{
		//printf("dasfaf\n");
		return 1;
	}


	for(int i=0; i<4; i++)
	{
		if(temp_x >=0 && temp_x <H && temp_y>=0 && temp_y<W &&
			arr[temp_x+dx[i][0][0]][temp_y+dx[i][1][0]] =='.' && 
			arr[temp_x+dx[i][0][1]][temp_y+dx[i][1][1]]=='.'&&
			arr[temp_x+dx[i][0][2]][temp_y+dx[i][1][2]]=='.')
		{
			//printf("sdaff\n");
			arr[temp_x+dx[i][0][0]][temp_y+dx[i][1][0]] =
			arr[temp_x+dx[i][0][1]][temp_y+dx[i][1][1]] =
			arr[temp_x+dx[i][0][2]][temp_y+dx[i][1][2]] ='#';
			ret+=boardcover();
			arr[temp_x+dx[i][0][0]][temp_y+dx[i][1][0]] = 
			arr[temp_x+dx[i][0][1]][temp_y+dx[i][1][1]] = 
			arr[temp_x+dx[i][0][2]][temp_y+dx[i][1][2]] ='.';
		}

	}

	return ret;
}


int main(void)
{
	cin >> C;

	for(int i=0; i<C; i++)
	{
		cin >> H >> W;
		for(int j=0; j<H; j++)
			for(int k=0; k<W; k++)
				cin >> arr[j][k];

		
	
		printf("%d\n", boardcover());


	}
}
