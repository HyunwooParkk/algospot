#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int arr[101][101];

int N;
vector<int> v;
int ans = 0;

//╩С го аб ©Л

void check()
{
	int copy[101][101];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			copy[i][j] = arr[i][j];
	//v.push_back(2);
	//v.push_back(0);
	//v.push_back(3);
	v.push_back(1);
	//v.push_back(2);

	for (int i = 0; i <v.size(); i++)
	{
		
		// 0: ╩С 1: го 2 : аб 3: ©Л
		if (v[i]==0)
		{
			for (int i = 0; i <N; i++)
				{
					{
						int R=0;
						int num = 1;
						while (1)
						{
							if (num == N)
								break;



							int L = num;

							while (1)
							{
								if (L == R)
									break;
								if (copy[L -1][i] == 0)
								{
									copy[L - 1][i] = copy[L][i];
									copy[L][i] = 0;
								}
								else
								{
									if (copy[L - 1][i] == copy[L][i])
									{
										copy[L - 1][i] = copy[L][i] * 2;
										copy[L][i] = 0;
										R++;
									}
									break;
								}
								L--;
							}

											
							num++;
						}
					}
				}
			printf("\n\n");

			printf("\n");
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
					printf("%d ", copy[i][j]);
				printf("\n");
			}
		}
		else if (v[i]==1)
		{
			for (int i = 0; i <N; i++)
				{
				int R = N -1;
				int num = N -1;
					while (1)
					{
						if (num == -1)
							break;


						for (int j = num; j < R ;j++)
						{
							if (copy[j + 1][i] == 0)
							{
								copy[j + 1][i] = copy[j][i];
								copy[j][i] = 0;
							}
							if (copy[j + 1][i] == copy[j][i])
							{
								copy[j + 1][i] = copy[j][i] * 2;
								copy[j][i] = 0;
							}
							if (copy[R][i] != 0)
							{
								printf("%d\n", R);
								R--;
							}
						}
						num--;
					}
			}
			printf("\n\n");

			printf("\n");
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
					printf("%d ", copy[i][j]);
				printf("\n");
			}
		}
		else if (v[i]==2)
		{
			for (int i = 0; i < N; i++)
				{
					int num =1;
					int R = 0;
					while (1)
					{
						if (num == N)
							break;
						int L = num;

						while (1)
						{
							if (L == R)
								break;
							if (copy[i][L-1] == 0)
							{
								copy[i][L-1] = copy[i][L];
								copy[i][L] = 0;
							}
							else if(copy[i][L - 1] == copy[i][L])
							{
								copy[i][L - 1] = copy[i][L] * 2;
								copy[i][L] = 0;
								R++;
								break;
							}
							L--;
						}

						
						num++;
					}
			}
			printf("\n\n");

			printf("\n");
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
					printf("%d ", copy[i][j]);
				printf("\n");
			}
		}
		else if (v[i]==3)
		{
			
			for (int i = 0; i < N; i++)
				{
					int num = N - 1;
					int R = N - 1;
					while (1)
					{
						if (num == -1)
							break;


						int L = num;

						while (1)
						{
							if (L == R)
								break;
							if (copy[i][L+1] == 0)
							{
								copy[i][L+1] = copy[i][L];
								copy[i][L] = 0;
							}
							else if(copy[i][L + 1] == copy[i][L])
							{
								copy[i][L + 1] = copy[i][L] * 2;
								copy[i][L] = 0;
								R--;
								break;
							}
							L++;
						}

						num--;
					}
				}
			printf("\n\n");

			printf("\n");
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
					printf("%d ", copy[i][j]);
				printf("\n");
			}
		}
		
	}

	/*printf("\n\n");

	printf("\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", copy[i][j]);
		printf("\n");
	}*/

	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			ans = max(ans, copy[i][j]);
		}

}
void run(int num)
{
	if (num == 5)
	{

		check();

		return;
	}
	for (int i = 0; i < 4; i++)
	{
		v.push_back(i);
		run(num + 1);
		v.pop_back();

	}
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	//run(0);
	check();
	printf("%d\n", ans);

}