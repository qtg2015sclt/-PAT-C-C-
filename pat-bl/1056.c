/**
 * pat-bl-1056
 * 2017-01-24
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  int sum = 0;
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
  {
    int tmp;
    scanf("%d", &tmp);
    //printf("tmp = %d\n", tmp);
    sum += ((tmp * 10 + tmp) * (n-1));
  }
  printf("%d\n", sum);
}
