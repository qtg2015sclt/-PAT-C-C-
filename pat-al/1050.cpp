/**
 * pat-al-1050
 * 2017-01-26
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  char str1[10002];
  char str2[10002];//坑1：不是每个字符之出现一次，所以并不是128或者256
  int hs[256] = {0};//坑2：不是128哦
  gets(str1);
  gets(str2);
  int len1 = strlen(str1);//坑2：不能放在for循环里，否则会超时
  int len2 = strlen(str2);
  //printf("%d %d\n", len1, len2);
  for(int i = 0;i < len2;i++)
  {
    hs[str2[i]] = 1;
  }
  for(int i = 0;i < len1;i++)
  {
    if(hs[str1[i]] == 0)
      printf("%c", str1[i]);
  }
  putchar('\n');
  return 0;
}
