/**
 * pat-bl-1039
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>

int main()
{
  freopen("in.txt", "r", stdin);
  char str1[1002], str2[1002];
  scanf("%s %s", str1, str2);
  //printf("str1 = %s, str2 = %s\n", str1, str2);
  int hs1[128] = {0}, hs2[128] = {0};
  for(int i = 0;i < strlen(str1);i++)
    hs1[str1[i]]++;
  for(int i = 0;i < strlen(str2);i++)
    hs2[str2[i]]++;
  int sumless = 0, summore = 0;
  int flag = 1;//默认可以买
  for(int i = 0;i < 128;i++)
  {
    if(hs2[i] != 0 || hs1[i] != 0)//为了计算多出的珠子，也要判断hs1不为零的时候
    {
      if(hs2[i] > hs1[i])
      {
        sumless += (hs2[i] - hs1[i]);
        flag = 0;
      }
      else if(hs2[i] < hs1[i])
        summore += (hs1[i] - hs2[i]);
    }
  }
  if(flag == 1)
  {
    printf("Yes %d\n", summore);
  }
  else
    printf("No %d\n", sumless);
}
