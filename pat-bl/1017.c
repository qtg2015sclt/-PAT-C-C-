/**
 *pat-bl-1017
 *2016-11-16
 *C version 1.0
 *方法：采用了手工做除法时的步骤
 *注意点：商的第一位如果为零的情况，以及对a小于b时的特殊处理
 */
#include<stdio.h>

int main()
{
  char a[1001], q[1001];
  int b;
  int i, j, r;
  //freopen("in.txt", "r", stdin);
  scanf("%s %d", a, &b);
  i = 0;
  j = 0;
  r = 0;
  while(a[i] != '\0')
  {
    r = r * 10 + a[i] - '0';
    if(r >= b)
    {
      q[j] = r / b + '0';
      //printf("c[%d] = %c\n", j, c[j]);
      r -= (q[j] - '0') * b;
      j++;
    }
    else if(i)//商的第一位为零时跳过，其他时候赋零
    {
      q[j] = '0';
      //printf("c[%d] = %c\n", j, c[j]);
      j++;
    }
    i++;
  }
  if(i == 1 && (a[0] - '0') < b)//a<b时的特殊处理，比如5除以7的情况
  {
    q[j++] = '0';
    r = a[0] - '0';//5 = 7 * 0 + 5
  }
  q[j] = '\0';
  printf("%s %d\n", q, r);
}
