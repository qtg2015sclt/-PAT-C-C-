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
