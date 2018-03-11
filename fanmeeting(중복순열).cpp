#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;


//두 긴 자연수의 곱을 반환한다.
//각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다.
//예 : mutilply[3,2,1],[6,5,4]=123*456=56088=[8,8,0,6,5]
vector<int> multiply(const vector<int>&a, const vector<int>&b){
	vector<int> c(a.size() + b.size() +1, 0);
	for(int i=0; i<a.size(); i++)
		for(int j=0; j<b.size(); j++)
			c[i+j]+=a[i]*b[j];
	//normalize(c);
	return c;
}
//a+=b*(10^k)를 구현한다.
void addTo(vector<int> &a, const vector<int>&b, int k){
	a.resize(max(a.size(), b.size()+k));
	for(int i=0; i<b.size() ;i++)
		a[i+k] += b[i];
}
//a-=b;를 구현한다. 단 a>=b를 가정한다.
void subFrom(vector<int> &a, const vector<int> &b){
	a.resize(max(a.size(),b.size()+1));
	for(int i=0; i<b.size() ; i++)
		a[i]-=b[i];
}
//두 긴 정수의 곱을 반환한다.
// (a0+a1)*(b0+b1)=(a0*b0)(=z0)+(a1*b0+a0*b1)(=z1)+(a1*b1)(=z2)의 원리
vector<int> karatsuba(const vector<int> &a, const vector<int> &b)
{
	int an=a.size(), bn=b.size();
	//a가 b보다 짧을 경우 둘로 바꾼다.
	if(an<bn)
		return karatsuba(b,a);
	//기저 사례 : a나 b가 비어있는 경우
	if(an==0 || bn==0)
		return vector<int>();
	//기저 사례 : a가 비교적 짧은 경우 0(n^2) 곱셈으로 변경한다.
	if(an<=50)
		return multiply(a,b);

	int half=an/2;
	//a와 b를 밑으로 half자리와 나머지를 분리한다.
	vector<int> a0(a.begin(), a.begin()+half);
	vector<int> a1(a.begin()+half, a.end());
	vector<int> b0(b.begin(), b.begin()+min<int>(b.size(), half));
	vector<int> b1(b.begin()+min<int>(b.size(),half), b.end());
	//z2=a1*b1
	vector<int> z2=karatsuba(a1,b1);
	//z0=a0*b0
	vector<int> z0=karatsuba(a0,b0);
	//a0=a0+a1; b0=b0+b1
	addTo(a0,a1,0);
	addTo(b0,b1,0);
	//z1=(a0*b0)-z0-z2;
	vector<int> z1=karatsuba(a0,b0);
	subFrom(z1,z0);
	subFrom(z1,z2);
	//ret=z0+z1*10^half+z2*10^(half*2)
	vector<int> ret;
	addTo(ret,z0,0);
	addTo(ret,z1,half);
	addTo(ret,z2,half+half);
	return ret;
}

int hugs(const string &members, const string &fans)
{
	int N=members.size(), M=fans.size();
	vector<int> A(N), B(M);
	for(int i=0; i<N ; ++i)
	{
		if(members[i]=='M')
			A[i]=1;
		else
			A[i]=0;
	}
	//저장을 거꾸로 하는 이유는 예를 들어서 FFFMMM이고 팬은 MMMFFF이면 FFFMMM에 순서대로 M, M, F, F, F순서대로 구해야 한다. 따라서 순서를 바꾸는것이다.
	for(int i=0; i<M; ++i)
	{
		if(fans[i]=='M')
			B[M-i-1]=1;
		else
			B[M-i-1]=0;
	}


	vector<int> C=karatsuba(A,B);
	int allHugs=0;
	for(int i=N-1; i<M ; i++)
		if(C[i]==0)
			allHugs++;

	return allHugs;

}

int main(void)
{
	int test_case;
	string members , fans;


	cin >> test_case;
	if(test_case <0 || test_case >20)
		exit(-1);

	for(int i=0; i<test_case; i++)
	{
		cin >> members >> fans;
		if(members.size() <1 || fans.size() <1 || members.size()>200000 || fans.size() >200000)
			exit(-1);
		cout<<hugs(members,fans) << endl;
	}

	return 0;
}



	