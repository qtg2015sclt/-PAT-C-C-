/**
 * pat-bl-1040
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>

int main()
{
  freopen("in.txt", "r", stdin);
  char str[100002];
  scanf("%s", str);
  long cntPAT = 0, cntT = 0, cntAT = 0;//因为结果太大，用int会答案错误
  for(long i = strlen(str) - 1;i >= 0;i--)//不能写三重循环，会超时，使用动态规划的思想，自底向上求解
  {
    if(str[i] == 'T')
      cntT++;
    if(str[i] == 'A')
      cntAT  += cntT;
    if(str[i] == 'P')
      cntPAT += cntAT;
  }
  printf("%ld\n", cntPAT % 1000000007);
}
