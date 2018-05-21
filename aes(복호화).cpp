#include <stdio.h>
#include <string.h>

/*
1
URLPM
XPRET
GIAET
XTNZY
XOQRS
6
PRETTY
GIRL
REPEAT
KARA
PANDORA
GIAZAPX
--------------------
PRETTY YES
GIRL YES
REPEAT YES
KARA NO
PANDORA NO
GIAZAPX YES
*/

int N; // 단어의 수 
char word[11];
char map[5][6];
int cache[5][5][10]; // map y,x,idx
int length;

// 갈수 있는 방향
int dx[8] = {-1,0,1,-1,1,-1,0,1}; 
int dy[8] = {-1,-1,-1,0,0,1,1,1};

// 범위에서 벗어났는지 
int isGetOut(int y, int x){
   if(y<0 || y>4 || x<0 || x>4) return 1;
   else return 0;
}

// 문자열 끝까지 체크 했으면 return 1
// 8방향 체크 했는데 없으면 return 0 
// cache 는 해당 i,j 해당 idx 체크 했으면 다음에 안돌도록
// PRETTY 이면 PR 까지 완료했다고 가정하면
// PR 이 어느 i,j 에서 오던지 통과했다는것은 변함없다.
// 개수 세는것이 아니라서 가능한 코드인듯 ? 
// 개수 셀려면 cache에 누적시켜야 할듯 
int dpRecur(int y, int x){
   if(idx==length) return 1;
   if(isGetOut(y,x)) return 0;
   int *ret  = &cache[y][x];
   if(*ret!=-1) return *ret;
   *ret = 0;
   int k;
   if(word[idx]==map[y][x])
   {
      for(k=0; k<8; k++)
      {   
         *ret += dpRecur(y+dy[k], x+dx[k]);               
      }
   }
   return *ret;
}

int main(void){
   int C, cnt, ans[10];
   char ansWord[10][11];
   memset(ansWord, 0, sizeof(ansWord));
   scanf("%d", &C);
   for(cnt=0; cnt<C; cnt++)
   {
      int i;
      for(i=0; i<5; i++) scanf("%s", map[i]);
      scanf("%d", &N);
      for(i=0; i<N; i++)
      {
         memset(cache, -1, sizeof(cache));
         scanf("%s", word);
         strcpy(ansWord[i], word);   
         length = strlen(word);
         int I,J;
         for(I=0; I<5; I++)
         {
            for(J=0; J<5; J++)
            {
               ans[i] = dpRecur(I, J); // y,x, 현재 idx 
               if(ans[i]) break;
            }
            if(ans[i]) break;
         }
      }
      for(i=0; i<N; i++)
      {
         if(ans[i]) printf("%s YES\n", ansWord[i]);
         else printf("%s NO\n", ansWord[i]);
      }
   }
   return 0;
}


