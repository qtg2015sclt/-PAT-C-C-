/**
 * pat-bl-1043
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  freopen("in.txt", "r", stdin);
  char str[10002];
  scanf("%s", str);
  int hs[128] = {0};
  char alp[7] = "PATest";
  for(int i = 0;i < strlen(str);i++)
  {
    hs[str[i]]++;
  }
  for(int i = 0;i < 10002;i++)
  {
    for(int j = 0;j < 6;j++)
      if(hs[alp[j]]-- > 0)
        putchar(alp[j]);
  }
  putchar('\n');
}
