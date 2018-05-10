#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int c, generation, skip, range;
const int MAX=1000000000+1;
int length[51];

void check()
{
	length[0]=1;
	for(int i=1; i<=50; i++)
	{
		length[i]=min(MAX,length[i-1]*2+2);
		printf("%d\n", length[i]);
	}

}
char idx(const string &dragonCurve,int generation, int skip)
{
	if(generation==0)
	{
		if(skip > dragonCurve.size())
			exit(-1);

		return dragonCurve[skip];
	} 
	// skip하는게 만약에 length보다 크면은 X나 Y에 대해서 확장될 것을 미리 생략해놓는 방식이다.
	// 예를들면 1세대에서 FX+YF에서 X를 만났을 때 건너뛰어야할 문자의 수가 6이면 전개하면 생기는 문자열의 길이 4보다 길므로
	// 전개하지 않고 그냥 건너뛰는거다, 세대를 마지막세대부터 하다가 어느순간 length[세대]가 skip보다 커지면 그 세대값을 출력하여 skip값을 찾으면 된다.
	// skip이 더 큰 경우는 생략해주고 작은 경우는 
	for(int i=0; i<dragonCurve.size(); i++)
	{
		if(dragonCurve[i] == 'X' || dragonCurve[i]=='Y')
		{
			if(skip >= length[generation])
			{
				printf("\nsdaff\n\n");
				skip-=length[generation];
			}
			else if(dragonCurve[i]=='X')
				return idx("X+YF",generation-1,skip);
			else
				return idx("FX-Y",generation-1,skip);
		}
		else if(skip>0)
		{
			skip--;
		}
		else if(skip==0)
		{
			return dragonCurve[i];
		}
	}
}
int main(void)
{
	scanf("%d", &c);
	check();
	for(int i=0; i<c; i++)
	{
		scanf("%d %d %d", &generation, &skip, &range);

		for(int i=0; i<range; i++)
			cout << idx("FX", generation,skip+i-1);
		cout<<endl;

	}
}

