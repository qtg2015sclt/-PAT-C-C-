/**
 * pat-al-1077
 * 2017-01-27
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d\n", &n);//注意：必须加\n，gets会读这个回车符
  char str[n][260];
  int minLen = 260;
  for(int i = 0;i < n;i++)
  {
    gets(str[i]);
    int len = strlen(str[i]);
    if(minLen > len)
      minLen = len;
    for(int j = 0;j < len/2;j++)//将字符串逆序
    {
      char tmp = str[i][j];
      str[i][j] = str[i][len-1-j];
      str[i][len-1-j] = tmp;
    }
  }
  int i, j, flagFail = 0;
  for(i = 0;i < minLen;i++)
  {
    char ch = str[0][i];
    for(j = 1;j < n;j++)
    {
      if(ch != str[j][i])
      {
        flagFail = 1;
        break;
      }
    }
    if(flagFail)
      break;
  }
  if(i == 0)
    printf("nai");
  else
  {
    for(i--;i >= 0;i--)
      putchar(str[0][i]);
  }
  putchar('\n');
}
