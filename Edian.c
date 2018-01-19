#include <stdio.h>

int T;
unsigned int reverse_bits(unsigned int x)
{
	int i,k=1;
	return  ( (((x) >> 24) & 0x000000FF) | (((x) >>  8) & 0x0000FF00) | 
   (((x) <<  8) & 0x00FF0000) | (((x) << 24) & 0xFF000000) );

}
int main(void)
{
	unsigned int a,b;


	scanf("%d", &T);
	while(T--)
	{
		scanf("%u",&a);
		
		b=reverse_bits(a);
		printf("%u\n",b);
	}
	return 0;
}
