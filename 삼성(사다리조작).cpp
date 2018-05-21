#include <iostream>
using namespace std;

int arr[10][30];
int n,m,l;
int ans;

bool check()
{
	for(int i=1; i<=n; i++)
	{
		int current=i;

		for(int j=1; j<=l; j++)
		{
				if(arr[j][current]==1 )
					current+=1;
				else if(current-1 >0 && arr[j][current-1]==1)
					current-=1;
		}
		if(current==i)
			continue;
		else
			return false;
	}

	return true;
}

void dfs(int row, int cnt,int target)
{

	if(cnt==target)
	{
		if(check())
		{
			ans=cnt;
			return;
		}
	}

	for(int i=row; i<=l; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(arr[i][j]==0)
			{
				if(arr[i][j-1]==0 && arr[i][j+1]==0)
				{
					arr[i][j]=1;
					dfs(i,cnt+1,target);
					arr[i][j]=0;
				}
			}
		}
	}

	return ;
}

int main(void)
{
	

	cin >> n >> m >> l;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=l; j++)
			arr[i][j]=0;
	for(int k=0; k<m; k++)
	{
		int a,b;
		cin >> a >> b;
		arr[a][b]=1;
	}

	 ans = 1000000; // 임의의 값으로 ans를 지정
    for(int i=0; i<4; i++) // 놓은 사다리 개수가 i개 일 경우
    {
        dfs(1,0,i);
        if(ans != 1000000)
            break;
    }

    if(ans == 1000000)
        ans = -1;
    cout << ans << endl;



}