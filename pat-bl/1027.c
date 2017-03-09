/**
 * pat-bl-1027
 * 2017-01-20
 * C version
 */
#include<stdio.h>

int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  char c;
  scanf("%d %c", &n, &c);
  int largestI;
  int tmp = 0;
  int remain;
  int i, j;
  for(i = 1;tmp <= n - 1;i++)//数学问题，找出规律后用公式进行计算和判断
  {
    tmp = (3 + (2 * i + 1)) * i;
    //printf("i = %d, tmp = %d\n", i, tmp);
  }
  largestI = i - 2;
  remain = n - 1 - (3 + (2 * largestI + 1)) * largestI;
  //printf("largestI = %d, remain = %d\n", largestI, remain);
  //output:
  for(i = 0, j = (2 * largestI) + 1;j >= 1;i++, j -= 2)
  {
    for(int k = 0;k < i;k++)
    {
      putchar(' ');
    }
    for(int k = 0;k < j;k++)
    {
      putchar(c);
    }
    putchar('\n');
  }
  for(i -= 2, j = 3;j <= (2 * largestI) + 1;i--, j += 2)
  {
    for(int k = 0;k < i;k++)
    {
      putchar(' ');
    }
    for(int k = 0;k < j;k++)
    {
      putchar(c);
    }
    putchar('\n');
  }
  printf("%d\n", remain);
}
