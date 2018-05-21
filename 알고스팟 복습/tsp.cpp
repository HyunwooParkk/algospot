#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N;
double arr[10][10];


double tsp(vector <int> &path , vector <bool> &visited, double currentLength)
{
	if(path.size() == N)
	{
		return currentLength;
	}

	double set= 10000000;

	for(int i=0; i<N; i++)
	{
		if(visited[i])
			continue;
		int here=path.back();
		path.push_back(i);
		visited[i]=true;
		double ret=tsp(path,visited,currentLength+arr[here][i]);
		set=min(ret,set);
		visited[i]=false;
		path.pop_back();
	}
	return set;

}
int main(void)
{
	int C;
	cin >> C;

	for(int i=0; i<C; i++)
	{
		cin >> N;
		for(int j=0; j<N; j++)
			for(int k=0; k<N; k++)
				cin >> arr[j][k];

		double answer=1000000;
		for(int j=0; j<N; j++)
		{
			vector<int> path(1,j);
			vector<bool> visited(N,false);
			visited[j]=true;
			double result=tsp(path,visited,0.00000000);
			if(answer> result)
				answer=result;
		}
		printf("%.10f\n", answer);



	}
	return 0;
}