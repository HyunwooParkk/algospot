#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int volume[100],need[100];
string name[100]; 
int cache[1001][1001];

int m,n;
// m: 가져가고 싶은 물건의 수 , w: 캐리어의 용량

int Packing(int capacity,int item)
{
	if(item==m)
		return 0;
	int &result=cache[capacity][item];
	if(result != -1)
		return result;

	result=Packing(capacity, item+1);

	if(capacity >=volume[item])
		result=max(result,Packing(capacity-volume[item],item+1)+need[item]);

	return result;
}

void reconstruct( int CarVol, int num, vector<string> &picked)
{
	if(num==m)
		return;
	if(Packing(CarVol, num) == Packing(CarVol,num+1))
		reconstruct(CarVol,num+1, picked);
	else
	{
		picked.push_back(name[num]);
		reconstruct(CarVol-volume[num],num+1, picked);

	}
}
int main(void)
{
	int C;
	scanf("%d", &C);
	for(int i=0; i<C; i++)
	{
		vector<string> picked;
		scanf("%d %d", &m, &n);
		for(int j=0 ; j<m; j++)
		{
			cin >> name[j] >> volume[j] >> need[j];
		}


		memset(cache,-1,sizeof(cache));
		reconstruct(n,0,picked);
		cout << Packing(n,0) << " " << picked.size() << endl;
		for(int j=0; j<picked.size(); j++)
			cout << picked[j] << endl;
	}
	return 0;
}

