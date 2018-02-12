#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#define INF 10000000000000000.000000
using namespace std;
int n;
double dist[8][8];


double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength, int k){
   // ���� ���: ��� ���ø� �� �湮���� ���� ���� ���÷� ���ư��� �����Ѵ�.
   if(path.size()==n) {
      //return currentLength + dist[path[0]][path.back()];
      return currentLength;
   }
    
   double ret = INF;   // �ſ� ū ������ �ʱ�ȭ 
   // ���� �湮�� ���ø� ���� �õ��غ���.
   for(int next=0; next<n; ++next) {
      if(visited[next]) continue;
      int here;
      if(path.size()==0){
         here = k;
      }
      else{
         here = path.back();
      }
      path.push_back(next);
      visited[next]=true;
      // ������ ��θ� ���ȣ���� ���� �ϼ��ϰ� ���� ª�� ����� ���̸� ��´�.
      double cand = shortestPath(path, visited, currentLength + dist[here][next], k);
      ret = min(ret, cand);
      visited[next] = false;
      path.pop_back();
   }
   return ret;
}

int main(void){
   int C, cnt;
   double ans[10];
   scanf("%d", &C);
   for(cnt=0; cnt<C; cnt++){
      ans[cnt] = INF;
      scanf("%d", &n);
      int i,j;
      for(i=0;i<n;i++){
         for(j=0;j<n;j++){
            scanf("%lf", &dist[i][j]);
         }
      }
      for(int k=0; k<n; k++){
         vector<int> path;
         vector<bool> visited(n, false);
         double tmp = shortestPath(path, visited, 0, k);
         if(ans[cnt]>tmp) ans[cnt] = tmp;
      }
   }
   for(cnt=0; cnt<C; cnt++){
      printf("%.10lf\n",ans[cnt]);
   }
   return 0;
}