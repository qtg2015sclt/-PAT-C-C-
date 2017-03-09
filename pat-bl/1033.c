/**
 * pat-bl-1033
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>

int main()
{
  //test:
  // char tmp = '_';
  // printf("%c: %d\n", tmp, tmp);
  // tmp = ',';
  // printf("%c: %d\n", tmp, tmp);
  // tmp = '.';
  // printf("%c: %d\n", tmp, tmp);
  // tmp = '-';
  // printf("%c: %d\n", tmp, tmp);
  // tmp = '+';
  // printf("%c: %d\n", tmp, tmp);
  //test end
  freopen("in.txt", "r", stdin);
  int hs[128] = {0};//键位坏掉的标志，默认没坏
  char str1[128], ch;
  fgets(str1, sizeof(str1), stdin);//坑点：第一个串可能为空，不能用scanf读。有一个测试点测的就是这个。
  str1[strlen(str1) - 1] = '\0';
  //printf("strlen(str1) = %lu\n", strlen(str1));
  //scanf("%s", str2);
  //printf("%s %s\n", str1, str2);
  for(int i = 0;i < strlen(str1);i++)
  {
    hs[str1[i]] = 1;//将坏掉的键标志置1
    if(str1[i] >= 'A' && str1[i] <= 'Z')
      hs[str1[i] + 32] = 1;//注意：如果这个字母是坏键，要将小写字母也置1
  }
  while(scanf("%c", &ch) != EOF)//一个还没搞清楚的问题：虽然说第二个串不是空串，..
  {//..但如果不写成判断文件结束（之前用的是跟在第一个串后一次读入），就过不了最后一个测试点
    if(hs[ch] == 0)
    {
      if(ch >= 'A' && ch <= 'Z' && hs['+'] == 1)//大写字母要额外判断'+'键
        continue;
      putchar(ch);
    }
  }
}
