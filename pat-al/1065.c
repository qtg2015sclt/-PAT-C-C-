/**
 * pat-al-1065
 * 2017-01-27
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<limits.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int t;
  scanf("%d", &t);
  for(int i = 1;i <= t;i++)
  {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    long long sum = a + b;
    if(a > 0 && b > 0 && a > LLONG_MAX - b)//正溢出，大于范围内可输入的任何数
      printf("Case #%d: true\n", i);
    else if(a < 0 && b < 0 && a < LLONG_MIN - b)//负溢出，小于范围内可输入的任何数
      printf("Case #%d: false\n", i);
    else
    {
      if(sum > c)
        printf("Case #%d: true\n", i);
      else
        printf("Case #%d: false\n", i);
    }
  }
}
