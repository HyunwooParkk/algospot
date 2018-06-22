#include <stdio.h>
int h[1000];
int n;

/*
http://procdiaru.tistory.com/3
*/
// �ִ� ���ϴ� �Լ�
int max(int a, int b)
{
	if(a<b)
		return b;
	else
		return a;
}

//�ּڰ� ���ϴ� �Լ�
int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int solve(int left, int right)
{
	// left�� right�� ���� ���� ��Ÿ���� �������� �ɰ��� �ɰ��ٺ��� �ᱹ 1�� ���� ��Ȳ�� ���ؼ� �̴�.
	if(left==right)
		return h[left];
	int mid=(left+right)/2;

	//ret�� Ư�� ��Ÿ�� ������ ������ �и��Ͽ� ���� ��Ÿ�� �迭, ���� ��Ÿ�� �迭�� ���� �� 
	//������ ������ �ִ� ���簢���� ũ�⸦ ���� �� �� �� ū ���簢���� �������� ����ϴ� ��.
	int ret=max(solve(left,mid), solve(mid+1,right));
	int lo=mid, hi=mid+1;
	int height=min(h[lo],h[hi]);

	//ret�� ���ϴ� ������ ù��° ���� ����� �ʿ��ϱ� �����̴�, ������ ret�� mid�� mid+1�� ���� �� ���簢�� 2�� ¥���� �����ε�
	// while������ ���� ���簢�� 3���� ���̺��� ���簢�� 2��¥���� ret�� ���̰� ū ��쵵 �����Ƿ� ���ϴ� ���̴�.
	// �Ѹ���� 2��¥�� ����> 3��¥�� ���� �� ��츦 ����ϱ� ���Ͽ� (���̰� �ٸ��⿡)
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
		//printf(" ���������� �� %d \t", ret);
		
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