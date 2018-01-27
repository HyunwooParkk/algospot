#include <stdio.h>

double arr[10][10];
int n,C,c;
double arr1[15];
int k=0;

double MIN(double a, double b)
{
	if(a>b)
		a=b;
	return a;
}
int swap(int i,int j,int data[])
{
    int temp;
    if(i==j) return 0;
    temp = data[i];
    data[i]=data[j];
    data[j]=temp;
    return 0;
}

int Permutation(int TotalN,int N ,int data[])
{
    int i;	
	double distance=0;
	int ret=0;

    if( N==1 ) {
        for(i=0;i<TotalN-1;i++){
           distance+=arr[data[i]][data[i+1]];
        }		

		arr1[k]=distance;
		k++;
		return 1;
	}
	
    for(i=0;i<N;i++){
        swap(i,N-1,data);
        ret+=Permutation(TotalN,N-1,data);
        swap(i,N-1,data);
    }

	return ret;
}

int main(void)
{
	int i, j, k;
	double way=0;
	int match[10];
	int ret;
	double min;
	double min2[10];

	scanf("%d", &C);
	for(c=0; c<C; c++)
	{
		scanf("%d",&n);
		for(i=0 ; i<n; i++)
			for(j=0; j<n; j++)
				scanf("%lf",&arr[i][j]);
		for(i=0; i<n; i++)
			match[i]=i;
		ret=Permutation(n,n,match);
			
		min=arr1[0];
		for(k=0; k<ret; k++)
		{
			//printf("%lf\n", arr1[k]);
			
				if(min>arr1[k])
					min=arr1[k];
		
		}
		min2[c]=min;	
	}

	for(i=0; i<C; i++)
		printf("%.10lf\n", min2[i]);
	return 0;
}