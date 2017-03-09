/**
 * pat-al-1104
 * 2017-02-26
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  double sum = 0, num;
  for(int i = 1;i <= n;i++)
  {
    scanf("%lf", &num);
    sum += (num * (n-i+1) * i);
  }
  printf("%.2lf\n", sum);
  return 0 ;
}
