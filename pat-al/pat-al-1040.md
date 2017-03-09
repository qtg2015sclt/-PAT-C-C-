1040.Longest Symmetric String (25)

pat-al-1040

2017-02-05

- 动态规划题，想清楚了就特别好做，不然……
- 参考：[1040. Longest Symmetric String (25)-PAT甲级真题](http://www.liuchuo.net/archives/2104)
- 是在求解一个上三角矩阵（右上），从求解对角线开始，斜向上求解，在草稿纸上画一画就理解了
- 坑见注释

```c
/**
 * pat-al-1040
 * 2017-02-05
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  char str[1002];
  gets(str);
  int dp[1002][1002], result = 1;//坑：注意result最低不是0，而是1
  memset(dp, 0, sizeof(dp));
  int len = strlen(str);
  for(int i = 0;i < len;i++)
  {
    dp[i][i] = 1;
    if(i < len-1 && str[i] == str[i+1])
    {
      dp[i][i+1] = 1;
      result = 2;
    }
  }
  for(int tmpResult = 3;tmpResult <= len;tmpResult++)
  {
    for(int i = 0;i+tmpResult-1 < len;i++)
    {
      int j = i+tmpResult-1;
      if(str[i] == str[j] && dp[i+1][j-1] == 1)
      {
        dp[i][j] = 1;
        result = tmpResult;
      }
    }
  }
  printf("%d\n", result);
}
```
-FIN-
