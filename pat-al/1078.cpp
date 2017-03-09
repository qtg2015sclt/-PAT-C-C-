/**
 * pat-al-1078
 * 2017-03-01
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#define MAX 10010
int main()
{
  int prime[MAX] = {1, 1, 0, 0};//0表示是素数，1表示非素数
  for(int i = 2;i * i < MAX;i++)
    for(int j = 2;i * j < MAX;j++)
      prime[i*j] = 1;
  freopen("in.txt", "r", stdin);
  int MSize, n, num, hs[MAX];
  memset(hs, -1, sizeof(hs));
  scanf("%d%d\n", &MSize, &n);
  while(prime[MSize] == 1)
    MSize++;
  int incre, flagFail = 1;
  scanf("%d", &num);
  if(hs[num%MSize] == -1)
  {
    hs[num%MSize] = num;
    printf("%d", num%MSize);
  }
  else
  {
    for(incre = 1;incre < (MSize-1)/2;incre++)
    {
      if(hs[(num+incre*incre)%MSize] == -1)
      {
        hs[(num+incre*incre)%MSize] = num;
        printf("%d", (num+incre*incre)%MSize);
        flagFail = 0;
        break;
      }
    }
    if(flagFail == 1)
      printf("-");
  }
  for(int i = 1;i < n;i++)
  {
    flagFail = 1;
    scanf("%d", &num);
    if(hs[num%MSize] == -1)
    {
      hs[num%MSize] = num;
      printf(" %d", num%MSize);
    }
    else
    {
      for(incre = 1;incre < (MSize-1)/2;incre++)
      {
        if(hs[(num+incre*incre)%MSize] == -1)
        {
          hs[(num+incre*incre)%MSize] = num;
          printf(" %d", (num+incre*incre)%MSize);
          flagFail = 0;
          break;
        }
      }
      if(flagFail == 1)
        printf(" -");
    }
  }
  putchar('\n');
  return 0;
}
