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
	// skip�ϴ°� ���࿡ length���� ũ���� X�� Y�� ���ؼ� Ȯ��� ���� �̸� �����س��� ����̴�.
	// ������� 1���뿡�� FX+YF���� X�� ������ �� �ǳʶپ���� ������ ���� 6�̸� �����ϸ� ����� ���ڿ��� ���� 4���� ��Ƿ�
	// �������� �ʰ� �׳� �ǳʶٴ°Ŵ�, ���븦 ������������� �ϴٰ� ������� length[����]�� skip���� Ŀ���� �� ���밪�� ����Ͽ� skip���� ã���� �ȴ�.
	// skip�� �� ū ���� �������ְ� ���� ���� 
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

