pat-bl-1040

2017-01-21

- 一开始直接写了三重循环，每遇到一个p就去找后面的a，找到一个a再去找后面有多少t，果然超时
- 因为有重复子问题，所以应该自底向上求解
- 结果太大，需要至少用long
```c
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
  for(long i = strlen(str) - 1;i >= 0;i--)//不能写三重循环，会超时。应该自底向上求解
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
```
-FIN-
