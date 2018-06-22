#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;


int arr[10][16]=
{
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};
int clock[17];

int check(int num)
{
	int ret=0;
	int max=1000000;
	int flag=-1;
	for(int i=0; i<16; i++)
		if(clock[i] != 12)
		{
			flag=1;
			break;
		}

	/*
	쭉 다 찾다가 되는걸 찾는순간 돌면서 check값을 리턴하면서 return max값을 다더한다
	따라서 만약에 return 0 이 아닌 다른 수로 하면 return a로 하면 a+이전의 i들의 합이 나온다.
	*/
	if(flag==-1)
	{
		printf("dsafa\n");
		return 0;
	}
	if(num==10)
		return 100000;

	/*
	i가 0일 때에는 아무것도 스위치를 누르지 않은 상태이므로,
	for문을 max문 뒤에 놔둬야 된다. 왜냐하면 i가 0부터 시작하므로
	처음에는 시계를 변경하지 않고 그대로 있어야된다.
	*/
	for(int i=0; i<4; i++)
	{
		max=min(check(num+1)+i,max);
		
		for(int j=0; j<16; j++)
		{
			clock[j]+=arr[num][j]*3;

			if(clock[j] ==15)
				clock[j] =3;
		}
	
	}
	return max;

}

int main(void)
{
	int C;
	cin >> C;
	for(int i=0; i<C; i++)
	{
		for(int j=0; j<16; j++)
			cin >> clock[j];

		cout << check(0)<<endl;
	}
}