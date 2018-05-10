#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
vector<pair<int,int>> cctv;
vector<int> cctv_num;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int ans=10000000;
void set(int lab_b[9][9], int lab[9][9])
{
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			lab_b[i][j]=lab[i][j];
}
void set_a(int lab_b[9][9], int lab[9][9])
{
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			lab[i][j]=lab_b[i][j];
}
void CCTV_A(int x, int y ,int direction, int lab[9][9])
{
	if(direction == 0)
	{
		for(int i=x+1; i<N; i++)
		{
			if(lab[x][i]==0)
				lab[x][i]=8;
			else if(lab[x][i]==6)
				break;
			else if(lab[x][i]!=6 && lab[x][i]!=0)
				continue;
		}
	}
	else if(direction == 1)
	{
		for(int i=x+1; i<M;  i++)
		{

			if(lab[i][y]==0)
				lab[i][y]=8;	
			else if(lab[i][y]==6)
				break;
			else if(lab[i][y]!=6 && lab[i][y]!=0)
				continue;
		}
	}
	else if(direction==2)
	{
		for(int i=y-1; i>=0; i--)
		{

			
			if(lab[x][i]==0)
				lab[x][i]=8;
			else if(lab[x][i]==6)
				break;
			else if(lab[x][i]!=6 && lab[x][i]!=0)
				continue;
		}
	}
	else if(direction==3)
	{
		for( int i=y-1; i>=0 ; i--)
		{
			if(lab[i][y]==0)
				lab[i][y]=8;
			else if(lab[i][y]==6)
				break;
			else if(lab[i][y]!=6 && lab[i][y]!=0)
				continue;
		}
	}
}
void search(int cctvIndex, int lab[9][9])
{
	int lab_b[9][9];
	if(cctvIndex== cctv.size())
	{
		int temp=0;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M ;j++)
				{
					if(lab[i][j]==0)
						temp++;

				}
		}
		ans=min(ans,temp);
		return;
	}	
	int x=cctv[cctvIndex].first;
	int y=cctv[cctvIndex].second;
	int num=cctv_num[cctvIndex];

	switch(num){
	case 1:
		{
			for(int i=0; i<4; i++)
			{
				set(lab_b,lab);
				CCTV_A(x,y,i,lab);
				search(cctvIndex+1,lab);
				set_a(lab_b,lab);
				
			}
			
		}
		break;
	case 2:
		{
			for(int i=0; i<2; i++)
			{
				set(lab_b,lab);
				CCTV_A(x,y,i,lab);
				CCTV_A(x,y,(i+2)%4,lab);
				search(cctvIndex+1,lab);
				set_a(lab_b,lab);
			}
		}
		break;
	case 3:
		{
			for(int i=0; i<4; i++)
			{
				set(lab_b,lab);
				CCTV_A(x,y,i,lab);
				CCTV_A(x,y,(i+1)%4,lab);
				search(cctvIndex+1,lab);
				set_a(lab_b,lab);
			
			}
		}
		break;
	case 4:
		{
			for(int i=0; i<4; i++)
			{
				set(lab_b,lab);
				CCTV_A(x,y,i,lab);
				CCTV_A(x,y,(i+1)%4,lab);
				CCTV_A(x,y,(i+2)%4,lab);
				search(cctvIndex+1,lab);
				set_a(lab_b,lab);
			}
		}
		break;
	case 5:
		{
			set(lab_b,lab);
			CCTV_A(x,y,0,lab);
			CCTV_A(x,y,1,lab);
			CCTV_A(x,y,2,lab);
			CCTV_A(x,y,3,lab);
			search(cctvIndex+1,lab);
			set_a(lab_b,lab);
		}
		break;
	}
}
int main(void)
{
	int lab[9][9];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			scanf("%d", &lab[i][j]);
			if(lab[i][j]>=1 && lab[i][j]<=5)
			{
				cctv.push_back(make_pair(i,j));
				cctv_num.push_back(lab[i][j]);
			}
		}

		search(0,lab);
		printf("ans : %d \n",ans);
}