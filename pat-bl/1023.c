/**
*pat-bl-1023
*2017-01-19
*C version
*/
#include<stdio.h>

int main()
{
  freopen("in.txt", "r", stdin);
  int tmp;
  int hs[10] = {0};
  for(int i = 0;i < 10;i++)
  {
    scanf("%d", &tmp);
    hs[i] = tmp;
  }
  for(int i = 1;i < 10;i++)//输出那个最小的不为零的数
  {
    if(hs[i] != 0)
    {
      printf("%d", i);
      hs[i]--;
      break;
    }
  }
  for(int i = 0;i < 10;i++)
  {
    while(hs[i] != 0)
    {
      printf("%d", i);
      hs[i]--;
    }
  }
  putchar('\n');
}
