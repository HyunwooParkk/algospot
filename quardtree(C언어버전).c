#include <stdio.h>

int count;
char str[100];

void copy(char *dest, char *source)
{
	int i=0;
	while(source[i]!='\0')
	{
		dest[i]=source[i];
		i++;
	}
	dest[i]='\0';
}

void mergeQuad(char *dest, char *dl, char *dr, char *ul, char*ur)
{
	int i=0, j=1;

	dest[0]='x';

	while(dl[i]!='\0')
		dest[j++]=dl[i++];

	i=0;
	while(dr[i]!='\0')
		dest[j++]=dr[i++];

	i=0;
	while(ul[i]!='\0')
		dest[j++]=ul[i++];

	i=0;
	while(ur[i]!='\0')
		dest[j++]=ur[i++];

	dest[j]='\0';
}

char* calc()
{
	static char head;
	char temp[4][100];
	static char rv[100];
	if(str[count]=='w' || str[count]=='b')
	{
		head=str[count++];
		return &head;
	}

	count++;

	copy(temp[0],calc());
	copy(temp[1],calc());
	copy(temp[2],calc());
	copy(temp[3],calc());

	mergeQuad(rv,temp[2],temp[3],temp[0],temp[1]);
	return rv;

}

int main()
{
    int roopcnt;
    scanf("%d", &roopcnt);
    while(roopcnt--)
    {
        count=0;
        scanf("%s",str);
        printf("%s\n", calc());
    }
}