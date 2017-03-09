1068.Find More Coins (30)

pat-al-1068

2017-02-08

- 啊全是自己写的竟然一次AC了，好开心啊
- 写的有点麻烦，如果以后再写一次的话，会优化一下，参考：[1068. Find More Coins (30)-PAT甲级真题](http://www.liuchuo.net/archives/2323)
- 有点像0-1背包。说起来惭愧，虽然去年学了动态规划，却没有用dp写过0-1背包……所以完全不会，只好临时找了一篇文章看：[
动态规划之01背包问题（最易理解的讲解）](http://blog.csdn.net/mu399/article/details/7722810)。
- 看懂了0-1背包问题怎么用dp解决，就会做这题了。

```c++
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
```
-FIN-
