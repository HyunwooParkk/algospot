#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int c,n,p,l;
vector<string> ret;
string temp;

void idx(int n, string r)
{
	if(n==0)
	{
		temp+=r;
		return ;
	}

	if(r.size() <= l+r)
	{
		for(int i=0; i<r.size(); i++)
			{
				if(r[i]=='X')
				{
					idx(n-1,"X+YF");
				}
				else if(r[i]=='Y')
				{
					idx(n-1,"FX-Y");
				}
				else
				{
					temp+=r[i];
				}
			}
	}

}

int main(void)
{
	scanf("%d", &c);
	for(int i=0; i<c; i++)
	{
		scanf("%d %d %d", &n,&p,&l);
	
		temp.clear();

		idx(n,"FX");
		cout << temp.size() <<endl;
		//cout << temp<<endl;
		//string mem=temp.substr(p-1,l);
		//cout << mem;
		cout <<endl;

	}
}