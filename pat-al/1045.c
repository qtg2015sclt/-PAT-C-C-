/**
 * pat-al-1045
 * 2017-02-07
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m, l;
  scanf("%d", &n);
  scanf("%d", &m);
  int hs[201], color[10001], dp[10001];
  memset(hs, 0, sizeof(hs));
  for(int i = 1;i <= m;i++)
  {
    int tmp;
    scanf("%d", &tmp);
    hs[tmp] = i;//i表示出现的位次
  }
  scanf("%d", &l);
  int cnt = 0;
  for(int i = 0;i < l;i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if(hs[tmp] > 0)
      color[cnt++] = tmp;
  }
  int max = 1;
  for(int i = 0;i < cnt;i++)
  {
    dp[i] = 1;//dp[i]表示：以i为下标的颜色来结尾的话，目前符合题意的最大串长度
    for(int j = 0;j < i;j++)
    {
      if(hs[color[j]] <= hs[color[i]])//j在i前，下标为j的color的位次比下标i的color位次前时...
      {
        if(dp[i] < (dp[j] + 1))//...就看能否更新i位的最大串长度
          dp[i] = dp[j] + 1;
      }
      if(dp[i] > max)
        max = dp[i];
    }
  }
  printf("%d\n", max);
}
