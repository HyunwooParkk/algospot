#include <iostream>
#include <string>
#include <cstring>

/*
1
URLPM
XPRET
GIAET
XTNZY
XOQRS
6
PRETTY
GIRL
REPEAT
KARA
PANDORA
GIAZAPX
*/
using namespace std;

char arr1[5][5];
string arr[11];
int cache[5][5][11];


int dx[8]={-1,0,1,1,1,0,-1,-1};
int dy[8]={-1,-1,-1,0,1,1,1,0};


bool Boogle(int x, int y, int a, int cnt)
{
	if(x>4 || x<0 || y<0 || y>4)
		return false;

	
	if(arr[a].size()==cnt)
	{
		return true;
	}
	int &ret = cache[x][y][cnt];

	if(ret != -1)
		return ret;

	if(arr[a][cnt]==arr1[x][y])
	{
		for(int i=0; i<8; i++)
			if(x+dx[i] <5 && y+dy[i] <5 && x+dx[i]>=0 && y+dy[i]>=0)
				{
					printf(" cnt : %d \n", cnt);
					for(int i=0; i<5; i++)
					{
						for(int j=0; j<5; j++)
						{
							printf("%d ", cache[i][j][cnt]);
						}
					printf("\n");
					}
					printf("==================================\n");
					if(Boogle(x+dx[i],y+dy[i],a,cnt+1))
						ret=true;
				}
	}

	return ret;

}
int main(void)
{
	int C,N;
	int temp;
	int ret[10];

	cin >> C;

	for(int i=0; i<C; i++)
	{
		memset(ret,0,sizeof(ret));
		for(int j=0; j<5 ;j++)
			for(int k=0; k<5; k++)
				cin >> arr1[j][k];
		cin >> N;
		for(int j=0; j<N; j++)
		{
			cin >> arr[j];
			memset(cache,-1,sizeof(cache));
			
			temp=0;
			for(int k=0; k<5; k++)
				{
					for(int l=0; l<5; l++)
						{
								if(arr1[k][l]==arr[j][0])
								{
									//printf(" %c %c \n", arr1[k][l], arr[j][0]);
									ret[j]=Boogle(k,l,j,0);
									if(ret[j])
										break;
								}
						
							
						}
					if(ret[j])
						break;
				}
		}	
	

		for(int i=0; i<N; i++)
			{
			if(ret[i])
				cout << arr[i] << " YES"<<endl;
			else
				cout << arr[i] << " NO"<<endl;
			}
	}
	
}