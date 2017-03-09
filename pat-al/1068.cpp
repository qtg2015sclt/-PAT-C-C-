/**
 * pat-al-1068
 * 2017-02-08
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
  return a > b;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m;
  scanf("%d%d", &n, &m);
  int coin[10002] = {0}, dp[10002][102] = {0}, select[10002][102] = {0};
  for(int i = 1;i <= n;i++)
  {
    scanf("%d", &coin[i]);
  }
  sort(coin+1, coin+n+1, cmp);
  // for(int i = 1;i <= n;i++)//初始化第一列
  // {
  //   if(coin[i] == 1)
  //   {
  //     dp[i][1] = 1;
  //     select[i][1] = 1;
  //   }
  // }
  // for(int j = 1;j <= m;j++)//初始化第一行
  // {
  //   if(j >= coin[1])
  //   {
  //     dp[1][j] = coin[1];
  //     select[1][j] = 1;
  //   }
  // }
  for(int i = 1;i <= n;i++)
  {
    for(int j = 1;j <= m;j++)
    {
      if(dp[i-1][j] <= (dp[i-1][j-coin[i]]+coin[i]) && (dp[i-1][j-coin[i]]+coin[i]) <= j)
      {
        dp[i][j] = dp[i-1][j-coin[i]]+coin[i];
        select[i][j] = 1;
      }
      else
      {
        dp[i][j] = dp[i-1][j];
        select[i][j] = 0;
      }
    }
  }
  // for(int i = 1;i <= n;i++)
  // {
  //   for(int j = 1;j <= m;j++)
  //   {
  //     printf("%d ", dp[i][j]);
  //   }
  //   putchar('\n');
  // }
  // for(int i = 1;i <= n;i++)
  // {
  //   for(int j = 1;j <= m;j++)
  //   {
  //     printf("%d ", select[i][j]);
  //   }
  //   putchar('\n');
  // }
  if(dp[n][m] != m)
    printf("No Solution\n");
  else
  {
    int i = n, j = m;
    while(select[i][j] == 0)
      i--;
    printf("%d", coin[i]);
    j -= coin[i];
    i--;
    while(j != 0)
    {
      if(select[i][j] == 1)
      {
        //printf("i = %d, j = %d\n", i, j);
        printf(" %d", coin[i]);
        j -= coin[i];
        i--;
        //printf("i = %d, j = %d\n", i, j);
      }
      else
      {
        i--;
      }
    }
    putchar('\n');
  }
  return 0;
}
