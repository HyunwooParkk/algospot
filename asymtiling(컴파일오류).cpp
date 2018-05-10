#include <iostream>
using namespace std;
#include <cstring>

#define MOD 1000000007
int cache[101];
int c,C;
int Asy(int width)
{
	if(width<=1)
		return 1;
	int& ret=cache[width];
	if( ret != -1)
		return ret;
	
	ret=(Asy(width-1)+Asy(width-2))%MOD;

	return ret;

}
int asymmetric(int width)
{
	if(width %2 ==1)
		return (Asy(width) - Asy(width/2)+MOD)%MOD;

	int result=Asy(width);

	result=(result-Asy(width/2)+MOD)%MOD;
	result=(result-Asy(width/2-1)+MOD)%MOD;
	return result;
}
int main(void)
{
	scanf("%d",&C);
	int result[10];
	for(int i=0; i<C ; i++)
	{
		scanf("%d", &c);
		memset(cache,-1,sizeof(cache));
	    result[i]=asymmetric(c);
	}

	for(int i=0; i<C; i++)
		printf("%d\n",result[i]);
	return 0;
}