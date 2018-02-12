#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

//num[]�� �ڸ��� �ø��� ó���Ѵ�.
void normalize(vector<int> &num){
	num.push_back(0);
	//�ڸ��� �ø��� ó���Ѵ�.

	for (int i=0; i<num.size()-1; i++) //num-size()-1�� �߿�
	{
		/*if(num[i]<0){
			int borrow=(abs(num[i])+9)/10;
			num[i+1]-=borrow;
			num[i]+=borrow*10;
		}*/ 
		//else
		//{
			num[i+1]+=num[i]/10;
			num[i]%=10;
	//	}
	}
	while(num.size()>1 && num.back()==0)
		num.pop_back();
}
//�� �� �ڿ����� ���� ��ȯ�Ѵ�.
//�� �迭���� �� ���� �ڸ����� 1�� �ڸ��������� ������ ����Ǿ� �ִ�.
//�� : mutilply[3,2,1],[6,5,4]=123*456=56088=[8,8,0,6,5]
vector<int> multiply(const vector<int>&a, const vector<int>&b){
	vector<int> c(a.size() + b.size() +1, 0);
	for(int i=0; i<a.size(); i++)
		for(int j=0; j<b.size(); j++)
			c[i+j]+=a[i]*b[j];
	normalize(c);
	return c;
}
//a+=b*(10^k)�� �����Ѵ�.
void addTo(vector<int> &a, const vector<int>&b, int k){
	a.resize(max(a.size(), b.size()+k));
	for(int i=0; i<b.size() ;i++)
		a[i+k] += b[i];
}
//a-=b;�� �����Ѵ�. �� a>=b�� �����Ѵ�.
void subFrom(vector<int> &a, const vector<int> &b){
	a.resize(max(a.size(),b.size()+1));
	for(int i=0; i<b.size() ; i++)
		a[i]-=b[i];
}
//�� �� ������ ���� ��ȯ�Ѵ�.
// (a0+a1)*(b0+b1)=(a0*b0)(=z0)+(a1*b0+a0*b1)(=z1)+(a1*b1)(=z2)�� ����
vector<int> karatsuba(const vector<int> &a, const vector<int> &b)
{
	int an=a.size(), bn=b.size();
	//a�� b���� ª�� ��� �ѷ� �ٲ۴�.
	if(an<bn)
		return karatsuba(b,a);
	//���� ��� : a�� b�� ����ִ� ���
	if(an==0 || bn==0)
		return vector<int>();
	//���� ��� : a�� ���� ª�� ��� 0(n^2) �������� �����Ѵ�.
	if(an<=50)
		return multiply(a,b);

	int half=an/2;
	//a�� b�� ������ half�ڸ��� �������� �и��Ѵ�.
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

int main()
{
	vector<int> a,b, result;
	string number;

	cout<<"ù��° ���� �Է� : ";
	cin>>number;
	for(int i=number.size()-1; i>=0; i--)
		a.push_back(number[i]-'0');
	cout<< "�ι�° ���� �Է�: ";
	cin>>number;
	for(int i=number.size()-1; i>=0; i--)
		b.push_back(number[i]-'0');

	result=karatsuba(a,b);
	for(int i=result.size()-1; i>=0; i--)
		cout<<result[i];

	cout<<endl;
	return 0;

}



	