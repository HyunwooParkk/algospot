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
   // 기저 사례: 모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료한다.
   if(path.size()==n) {
      //return currentLength + dist[path[0]][path.back()];
      return currentLength;
   }
    
   double ret = INF;   // 매우 큰 값으로 초기화 
   // 다음 방문할 도시를 전부 시도해본다.
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
      // 나머지 경로를 재귀호출을 통해 완성하고 가장 짧은 경로의 길이를 얻는다.
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