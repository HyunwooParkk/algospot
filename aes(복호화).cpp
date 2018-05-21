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

int N; // �ܾ��� �� 
char word[11];
char map[5][6];
int cache[5][5][10]; // map y,x,idx
int length;

// ���� �ִ� ����
int dx[8] = {-1,0,1,-1,1,-1,0,1}; 
int dy[8] = {-1,-1,-1,0,0,1,1,1};

// �������� ������� 
int isGetOut(int y, int x){
   if(y<0 || y>4 || x<0 || x>4) return 1;
   else return 0;
}

// ���ڿ� ������ üũ ������ return 1
// 8���� üũ �ߴµ� ������ return 0 
// cache �� �ش� i,j �ش� idx üũ ������ ������ �ȵ�����
// PRETTY �̸� PR ���� �Ϸ��ߴٰ� �����ϸ�
// PR �� ��� i,j ���� ������ ����ߴٴ°��� ���Ծ���.
// ���� ���°��� �ƴ϶� ������ �ڵ��ε� ? 
// ���� ������ cache�� �������Ѿ� �ҵ� 
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
               ans[i] = dpRecur(I, J); // y,x, ���� idx 
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


