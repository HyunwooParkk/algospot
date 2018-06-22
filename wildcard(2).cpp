#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

char wildcard[101],fileName[101];
int fileNum;
int cache[101][101];

int wild(int a, int b, int w, int f)
{
	int &ret= cache[w][f];

	if( ret != -1)
		return ret;

	

	if(w < a && f <b && (wildcard[w]=='?' || wildcard[w]==fileName[f]))
		return ret=wild(a,b,w+1,f+1);

	if(w==a && f==b)
		return ret=1;

	if(wildcard[w]=='*')
	{
		if(( wild(a,b,w+1,f)) || (f<b && wild(a,b,w,f+1)))
			return ret=1;
	}
	return ret=0;
}
int main(void)
{
	int C;
	cin >> C;
	vector<string> q;
	for(int i=0; i<C; i++)
	{
		cin >> wildcard;
		cin >> fileNum;
		int a=strlen(wildcard);
		for(int j=0; j<fileNum; j++)
		{
			memset(cache,-1,sizeof(cache));
			cin >> fileName;
			int b=strlen(fileName);
			if(wild(a,b,0,0)==1)
				q.push_back(fileName);


		}
	}
	sort(q.begin(), q.end());
	for(int i=0; i<q.size(); i++)
		cout << q[i]  << endl;
	return 0;

}