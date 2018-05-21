#include <iostream>
#include <cstring>
#include <string>

using namespace std;


/*
10101111
01111101
11001110
00000010
2
3 -1
1 1
�� : 7

11111111
11111111
11111111
11111111
3
1 1
2 1
3 1
�� : 15


10001011
10000011
01011011
00111101
5
1 1
2 1
3 1
4 1
1 -1
�� : 6


10010011
01010011
11100011
01010101
8
1 1
2 1
3 1
4 1
1 -1
2 -1
3 -1
4 -1
�� : 5
*/
int arr[100][100];
int K;
int check[10];

//�ð� ���� ȸ�� 
void clock(int num)
{
	int temp=arr[num][7];
	for(int i=7; i>0; i--)
		arr[num][i]=arr[num][i-1];
	arr[num][0]=temp;

}
//�ݽð� ���� ȸ��
void dclock(int num)
{
	int temp=arr[num][0];
	for(int i=0; i<7; i++)
		arr[num][i]=arr[num][i+1];
	arr[num][7]=temp;
	
}
void swit(int num, int flag)
{
	if(flag==1)
		clock(num);
	else
		dclock(num);
}
// if�� �Ѵ� �������ϸ� Ż��
// check�� true false �����ָ� ���ѷ����� ���Եȴ�.
void dfs(int num,int flag)
{
	check[num]=true;
	if(num+1 < 4 && !check[num+1])
	{
		if(arr[num][2] != arr[num+1][6])
			dfs(num+1,-1*flag);
	}
	if(num-1 >=0 && !check[num-1])
	{
		if(arr[num-1][2] != arr[num][6])
			dfs(num-1,-1*flag);
	}
	swit(num,flag);


}
int main(void)
{
	int a,b;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<8; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}


	
	cin >> K;

	for(int i=0; i<K; i++)
	{
		cin >> a >> b;
		memset(check,0,sizeof(check));
		dfs(a-1,b);
	}

	int total=0;
	int ret=1;
	
	for(int i=0;i<4; i++)
	{
			if(arr[i][0]==1)
			{
				total+=ret;
			}
		ret*=2;
	}


	

	printf("%d\n", total);
	return 0;


}