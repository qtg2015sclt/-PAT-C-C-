/**
 *pat-bl-1022
 *2017-01-19
 *C version
 *
 */
#include<stdio.h>

int main()
{
  freopen("in.txt", "r", stdin);
  int a, b, c, d;
  int theRemainder[100];
  int flag = 1;
  scanf("%d %d %d", &a, &b, &d);
  c = a + b;
  int i = 0;
  if(c == 0)//出错：判断一下和是否为零，为零则直接输出0
  {
    printf("0\n");
  }
  else
  {
    while(c != 0)
    {
      theRemainder[i++] = c % d;
      c /= d;
    }
    for(i = i - 1;i >= 0;i--)
    {
      if(flag)//如果答案的第一位是0就不要输出了（不知道需不需要判断这个）
      {
        if(theRemainder[i])
        {
          printf("%d", theRemainder[i]);
        }
        flag = 0;
      }
      else
      {
        printf("%d", theRemainder[i]);
      }
    }
    putchar('\n');
  }
}
