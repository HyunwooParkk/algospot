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
start�� -1�� ����� �ؿ��� if������ S[start]�� ��� S[next]���� �۱⶧���� 
int maxLen=0;
for(int begin=0; begin<n; ++begin)
maxLen=max(maxLen, lis2(begin)); 
�̷����� ������ġ�� �� ���� �ڵ带 ������ �ʾƵ�
ret=max(ret, lis3(next)+1);���� �� ���� �ȴ�,
cache[start]��� cache[start+1]�� ���� ���� �����غ���, 
cache[]�� ũ�Ⱑ 1 Ŀ���⿡, lis(-1)-1�� ��������� ����Ѵ�
�ֳ��ϸ� S[-1]�� �츮�� �������� �߰� �Է��� ���̱� ������ ������ȯ���� ������Ѵ�.
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
