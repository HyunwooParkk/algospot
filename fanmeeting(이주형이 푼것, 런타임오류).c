#include <stdio.h>
#include <string.h>

char HYP[100];
char FAN[100];
int num;


int Check(int HYPlen, int len, int len2 )
{
	
	int flag=-1;
	int i;
	

	if(HYPlen==len2-len+1)
		return num;
	
	for(i=0; i<len; i++)
	{
		if(HYP[i]=='M' && FAN[HYPlen+i]=='M')
		{
				
				flag=1;
				break;
		}

	}
	
	

	if(flag==-1)
		num++;

	Check(HYPlen+1, len, len2);

	return num;

}
int main(void)
{
	int C,i;
	int len, len2;
	int ans[100];

	scanf("%d", &C);
	for(i=0; i<C; i++)
	{
		scanf("%s",&HYP[i]);
		scanf("%s",&FAN[i]);
		len=strlen(HYP);
		len2=strlen(FAN);

		num=0;
		ans[i]=Check(0,len,len2);
	}

	for(i=0; i<C; i++)
		printf("%d\n",ans[i]);
}