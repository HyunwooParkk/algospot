/*
노트북 컴퓨터 4 7
카메라		  2 10
XBOX		  6 6
커피그라인더  4 7
아령		  2 5
백과사전	  10 4

2
6 10
laptop 4 7
camera 2 10
xbox 6 6
grinder 4 7
dumbell 2 5
encyclopedia 10 4
6 17
laptop 4 7
camera 2 10
xbox 6 6
grinder 4 7
dumbell 2 5
encyclopedia 10 4

-----------------------------
24 3
laptop
camera
grinder
30 4
laptop
camera
xbox
grinder
*/

#include <iostream>
#include <cstring>
#include <algorithm>

typedef struct{
	char* name[50];
	int x;
	int y;
}Name;

Name arr[100];
int a,b;

int PACK(int c)
{
	int ret=0;
	int set=0;

	if(set==b)
		return arr[c].x;
	
	
	for(int i=0; i<a; i++)
	{
		ret+=PACK(i);
		set+=arr[i].y;
		printf("%s %d\n", arr[i].name, arr[i].x);

	}

	return ret;


}
int main(void)
{
	int C;
	

	scanf("%d", &C);
	for(int i=0; i<C; i++)
	{
		scanf("%d %d", &a, &b);
		for(int j=0; j<a; j++)
		{
			scanf("%s %d %d",arr[j].name, &arr[j].x, &arr[j].y);
			
		}

	
		//printf("%d\n",PACK(0));

	}
}
