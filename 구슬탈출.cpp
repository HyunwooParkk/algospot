#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N, M;


// 왼, 오, 위, 아래
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = INF;

void dfs(pair<int, int> Red, pair<int, int> Blue, int dir, int result, char arr[12][12])
{
	//printf("%d\n" , result);

	if (++result>10)
	{
		return;
	}

	char copy[12][12];
	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
			copy[i][j] = arr[i][j];



	bool red = false;
	bool blue = false;
	int flag = 0;
	// 빨강이 파란색보다 앞에 있으면 flag=0

	switch (dir)
	{
	case 0:
		if (Red.first > Blue.first)
			flag = 1;
		break;
	case 1:
		if (Red.first < Blue.first)
			flag = 1;
		break;
	case 2:
		if (Blue.second< Red.second)
			flag = 1;
		break;
	case 3:
		if (Blue.second> Red.second)
			flag = 1;
		break;
	}

	//flag=0이면 빨간색이 앞쪽에 있다는것임.
	if (flag == 0)
	{
		while (1)
		{
			int nx = Red.first + dx[dir];
			int ny = Red.second + dy[dir];

			if (copy[nx][ny] == '#')
				break;

			if (copy[nx][ny] == 'O')
			{
				copy[Red.first][Red.second] = '.';
				Red.first = Red.second = -1;
				red = true;
				break;
			}
			copy[Red.first][Red.second] = '.';
			copy[nx][ny] = 'R';
			Red.first = nx;
			Red.second = ny;
		}
		while (1)
		{
			int nx = Blue.first + dx[dir];
			int ny = Blue.second + dy[dir];

			if (copy[nx][ny] == '#' || copy[nx][ny] == 'R')
				break;
			if (copy[nx][ny] == 'O')
			{
				copy[Blue.first][Blue.second] = '.';
				Blue.first = Blue.second = -1;
				blue = true;
				break;
			}
			copy[Blue.first][Blue.second] = '.';
			copy[nx][ny] = 'B';
			Blue.first = nx;
			Blue.second = ny;

		}
	}
	else
	{
		while (1)
		{
			int nx = Blue.first + dx[dir];
			int ny = Blue.second + dy[dir];

			if (copy[nx][ny] == '#')
				break;

			if (copy[nx][ny] == 'O')
			{
				copy[Blue.first][Blue.second] = '.';
				Blue.first = Blue.second = -1;
				blue = true;
				break;
			}
			copy[Blue.first][Blue.second] = '.';
			copy[nx][ny] = 'B';
			Blue.first = nx;
			Blue.second = ny;
		}

		while (1)
		{
			int nx = Red.first + dx[dir];
			int ny = Red.second + dy[dir];

			if (copy[nx][ny] == '#' || copy[nx][ny] == 'B')
				break;
			if (copy[nx][ny] == 'O')
			{
				copy[Red.first][Red.second] = '.';
				Red.first = Red.second = -1;
				red = true;
				break;
			}
			copy[Red.first][Red.second] = '.';
			copy[nx][ny] = 'R';
			Red.first = nx;
			Red.second = ny;
		}

	}
	/*printf("\n");
	for(int i=0; i<N; i++)
	{
	for(int j=0; j<M; j++)
	printf("%c", copy[i][j]);
	printf("\n");
	}*/



	if (blue)
		return;
	else if (red)
	{
		//printf("%d\n", result);

		ans = min(ans, result);
		return;
	}


	for (int i = 0; i<4; i++)
	{
		if (i != dir || i != (3 - dir))
		{
			dfs(Red, Blue, i, result, copy);
		}
	}


}
int main(void)
{
	pair<int, int> Red;
	pair<int, int> Blue;
	char arr[12][12];
	cin >> N >> M;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'B')
			{
				Blue.first = i;
				Blue.second = j;
			}
			if (arr[i][j] == 'R')
			{
				Red.first = i;
				Red.second = j;
			}
		}
	}

	for (int i = 0; i<4; i++)
		dfs(Red, Blue, i, 0, arr);

	if (ans == INF)
		printf("-1\n");
	else
		printf("%d\n", ans);



}