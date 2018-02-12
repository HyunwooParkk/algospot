#include <stdio.h>

int a=0,b=0,c=0;
char paper[100][100];

int check(int i, int j, int side, int num){
   int ii, jj;
   for(ii=0; ii<side; ii++)
   {
      for(jj=0; jj<side; jj++)
      {
         if(paper[i+ii][j+jj] != num)
            return 0;
      }
   }
   return 1;
}


void recur(int i, int j, int side)
{
	int k,l;
	int n;
	int ret=0;
	int flag=-1;

	if(check(i,j,side,1))
	{
		a+=1;
		return;
	}
	else if(check(i,j,side,-1))
	{
		b+=1;
		return;
	}
	else if(check(i,j,side,0)){
		c+=1;
		return;
	}
	
	 recur(i, j, side/3);
    recur(i, j+side/3, side/3);
    recur(i, j+side/3+side/3, side/3);
    recur(i+side/3, j, side/3);
    recur(i+side/3, j+side/3, side/3);
    recur(i+side/3, j+side/3+side/3, side/3);
    recur(i+side/3+side/3, j, side/3);
    recur(i+side/3+side/3, j+side/3, side/3);
    recur(i+side/3+side/3, j+side/3+side/3, side/3);

}
int main(void)
{
	int C,i,j,k;
	scanf("%d", &C);
	
	 for(i=0; i<C; i++)
   {
      for(j=0; j<C; j++)
      {
         scanf("%d",  &paper[i][j]);
      }
   }

	recur(0,0,C);
	printf("a: %d, b: %d , c:%d \n", a,b,c);

	return 0;
} 