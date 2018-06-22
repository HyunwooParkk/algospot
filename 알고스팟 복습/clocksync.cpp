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
	�� �� ã�ٰ� �Ǵ°� ã�¼��� ���鼭 check���� �����ϸ鼭 return max���� �ٴ��Ѵ�
	���� ���࿡ return 0 �� �ƴ� �ٸ� ���� �ϸ� return a�� �ϸ� a+������ i���� ���� ���´�.
	*/
	if(flag==-1)
	{
		printf("dsafa\n");
		return 0;
	}
	if(num==10)
		return 100000;

	/*
	i�� 0�� ������ �ƹ��͵� ����ġ�� ������ ���� �����̹Ƿ�,
	for���� max�� �ڿ� ���־� �ȴ�. �ֳ��ϸ� i�� 0���� �����ϹǷ�
	ó������ �ð踦 �������� �ʰ� �״�� �־�ߵȴ�.
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