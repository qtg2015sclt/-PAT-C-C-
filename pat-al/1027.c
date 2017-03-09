/**
 * pat-al-1027
 * 2017-01-26
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int r, g, b;
  scanf("%d %d %d", &r, &g, &b);
  char num[13] = "0123456789ABC";
  printf("#%c%c%c%c%c%c\n", num[r/13], num[r%13], num[g/13], num[g%13], num[b/13], num[b%13]);
}
