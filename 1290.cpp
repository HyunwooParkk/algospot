#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

vector<vector<int>> p;
vector<bool> visited;
int N, M , L;

void dfs(int v)
{
	stack<int> s;
	s.push(v);

	while(!s.empty())
	{
		int top=s.top();
		s.pop();
		if(visited[top])
			continue;

		visited[top]=true;
		printf("%d ",top);

		sort(p[top].begin(), p[top].end(),greater<int>());
		for(int i=0; i<p[top].size(); i++)
			if(!visited[p[top][i]])
				s.push(p[top][i]);
	}
	printf("\n");
}
void bfs(int v)
{
	queue<int> s;
	s.push(v);
	while(!s.empty())
	{
		int front=s.front();
		s.pop();
		if(visited[front])
			continue;

		visited[front]=true;
		printf("%d ", front);

		sort(p[front].begin(),p[front].end());
		for(int i=0; i<p[front].size(); i++)
			s.push(p[front][i]);
	}
	printf("\n");
}
int main(void)
{
	cin >> N >> M >> L;
	p.resize(N+1);
	visited.resize(N+1);
	for(int i=0; i<M; i++)
	{
		int a,b;
		cin >> a >> b;
		p[a].push_back(b);
		p[b].push_back(a);
	}

	dfs(L);
	fill_n(visited.begin(),N+1, false);
	bfs(L);

}