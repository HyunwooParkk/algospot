#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void printPicked(vector<int>& picked)
{
	for(int i=0; i<picked.size(); i++)
		cout << picked[i] ;

}
void pick(int n, vector<int>& picked, int toPick)
{
	if(toPick==0)
	{
		printPicked(picked);
		cout << endl;
		return;
	}

	int smallest=picked.empty() ? 0 : picked.back()+1;
	for(int i=smallest; i<n; i++)
	{
		picked.push_back(i);
		pick(n,picked,toPick-1);
		picked.pop_back();

	}
}
int main(void)
{
	int n=10;

	vector<int> v;
	pick(n,v,4);
	getchar();

	return 0;
}