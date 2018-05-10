#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int c,generation,skip,range;
const string EXPAND_X="X+YF";
const string EXPAND_Y="FX-Y";

int length[51];
const int MAX=1000000000+1;
void check()
{
	length[0]=1;
	for(int i=1; i<=50; i++)
	{
		length[i]=min(MAX,length[i-1]*2+2);
	}

}
char idx(const string &dragonCurve, int generation, int skip)
{
	if(generation==0)
	{
		if(skip>dragonCurve.size())
			 exit(-1);
		return dragonCurve[skip];
	}

	for(int i=0; i<dragonCurve.size(); i++)
		if(dragonCurve[i]=='X' || dragonCurve[i]=='Y')
		{

			if(skip >= length[generation])
				skip-=length[generation];
			else if(dragonCurve[i]=='X')
				return idx("X+YF",generation-1,skip);
			else
				return idx("FX-Y", generation-1, skip);
		}
		else if(skip>0)
			--skip;
		else
			return dragonCurve[i];

	
		return '#';

}


int main(void)
{
	check();
	scanf("%d", &c);
	for(int i=0; i<c; i++)
	{
		scanf("%d %d %d", &generation,&skip,&range);
	
		
		//for(int j=0; j<range; j++)
			cout << idx("FX",generation,skip-1);
		cout<<endl;

	}
}