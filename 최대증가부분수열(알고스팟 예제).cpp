#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
int cache[100],S[100];
int n;

/*int lis(const vector<int>& A){
	if(A.empty()) 
		return 0;

	int ret=0;
	for(int i=0; i<A.size(); i++)
	{
		vector<int> B;
		for(int j=i+1; j<A.size(); j++)
			if(A[i] < A[j])
				B.push_back(A[j]);
		ret=max(ret,1+lis(B));
	}
	
	return ret;
}*/

int lis2(int start)
{
	int& ret=cache[start];
	if(ret != -1)
		return ret;

	ret= 1;
	for(int next=start+1; next< n ; ++next)
	{
		if(S[start]<S[next])
			ret=max(ret,lis2(next)+1);
	}

	return ret;
}

/*
start를 -1로 만들면 밑에서 if문에서 S[start]가 모든 S[next]보다 작기때문에 
int maxLen=0;
for(int begin=0; begin<n; ++begin)
maxLen=max(maxLen, lis2(begin)); 
이런식의 시작위치를 다 도는 코드를 만들지 않아도
ret=max(ret, lis3(next)+1);에서 다 돌게 된다,
cache[start]대신 cache[start+1]을 쓰는 것을 유의해보고, 
cache[]의 크기가 1 커졌기에, lis(-1)-1을 결과값으로 써야한다
왜냐하면 S[-1]은 우리가 가상으로 추가 입력한 값이기 때문에 최종변환에서 빼줘야한다.
*/
int lis3(int start){
	int& ret=cache[start+1];
	if(ret != -1)
		return ret;
	ret =1 ;
	for(int next=start+1 ; next < n ; next++)
		if(start==-1 || S[start] <S[next])
			ret=max(ret,lis3(next)+1);
	return ret;
}
