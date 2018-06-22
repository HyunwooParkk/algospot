#include <stdio.h>
int h[1000];
int n;

/*
http://procdiaru.tistory.com/3
*/
// 최댓값 구하는 함수
int max(int a, int b)
{
	if(a<b)
		return b;
	else
		return a;
}

//최솟값 구하는 함수
int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int solve(int left, int right)
{
	// left와 right가 같은 경우는 울타리를 절반으로 쪼개고 쪼개다보면 결국 1개 남는 상황을 위해서 이다.
	if(left==right)
		return h[left];
	int mid=(left+right)/2;

	//ret은 특정 울타리 라인을 반으로 분리하여 좌측 울타리 배열, 우측 울타리 배열로 나눈 후 
	//각각의 가능한 최대 직사각형의 크기를 구해 둘 중 더 큰 직사각형이 무엇인지 계산하는 것.
	int ret=max(solve(left,mid), solve(mid+1,right));
	int lo=mid, hi=mid+1;
	int height=min(h[lo],h[hi]);

	//ret을 구하는 이유는 첫번째 비교할 대상이 필요하기 때문이다, 예를들어서 ret이 mid와 mid+1의 넓이 즉 직사각형 2개 짜리의 넓이인데
	// while문으로 들어가서 직사각형 3개의 넓이보다 직사각형 2개짜리인 ret의 넓이가 큰 경우도 있으므로 구하는 것이다.
	// 한마디로 2개짜리 넓이> 3개짜리 넓이 인 경우를 대비하기 위하여 (높이가 다르기에)
	ret=max(ret,height*2);

	
	while(left<lo || hi<right)
	{
		if(hi<right && (lo==left || h[lo-1]<h[hi+1]))
		{
			++hi;
			height=min(h[hi],height);
		}
		else
		{
			--lo;
			height=min(h[lo],height);
		}
		
		ret=max(ret,height*(hi-lo+1));
		//printf(" 구해진넓이 값 %d \t", ret);
		
	}

	return ret;

}
int main(void)
{
	int a[100];
	int r;
	scanf("%d",&r);
	for(int k=0; k<r; k++)
	{
		scanf("%d", &n);
		for(int i=0; i<n ;i++)
			scanf("%d",&h[i]);

		a[k]=solve(0,n-1);
	}

	for(int i=0; i<r; i++)
		printf("%d\n",a[i]);
	return 0;
}