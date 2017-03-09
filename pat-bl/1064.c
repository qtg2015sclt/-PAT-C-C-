/**
 * pat-bl-1064
 * 2017-01-24
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int hs[37] = {0};//数字小于等于9999，朋友证号最大是36
  for(int i = 0;i < n;i++)
  {
    int tmp, sum = 0;
    scanf("%d", &tmp);
    while(tmp)
    {
      sum += tmp % 10;//加上个位数
      tmp /= 10;
    }
    hs[sum] = 1;//将该朋友证号置1
    //printf("sum = %d\n", sum);
  }
  int cnt = 0;
  for(int i = 0;i < 37;i++)
  {
    if(hs[i] == 1)
      cnt++;
  }
  if(cnt != 0)
    printf("%d\n", cnt);
  int flag = 1;
  for(int i = 0;i < 37;i++)
  {
    if(hs[i] == 1)
    {
      if(flag)
      {
        flag = 0;
        printf("%d", i);
      }
      else
        printf(" %d", i);
    }
  }
  putchar('\n');
}
