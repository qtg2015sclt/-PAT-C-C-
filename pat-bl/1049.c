/**
 * pat-bl-1049
 * 2017-01-22
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  double tmp, sum = 0;
  for(int i = 0;i < n;i++)
  {
    scanf("%lf", &tmp);
    sum += (double)(i + 1) * (n - i) * tmp;//不加double会出错
  }
  printf("%.2lf\n", sum);
}
