/**
 * pat-al-1008
 * 2017-01-26
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int sum = 0;
  int last = 0;
  for(int i = 0;i < n;i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if(tmp > last)
    {
      sum += ((tmp - last) * 6 + 5);
    }
    else
    {
      sum += ((last - tmp) * 4 + 5);
    }
    last = tmp;
  }
  printf("%d\n", sum);
}
