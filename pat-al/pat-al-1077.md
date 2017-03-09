pat-al-1077

2017-01-27

- 本题无坑
- 方法：把字符串一个一个读进来，每个都逆序一下，并且在这个过程中记录一下最短的字符串的长度；然后开始对每个字符串的每个对应位置进行比较（这就是逆序的意义，为了方便比较），当遇到不相同的就置失败标志位为1并跳出；最后输出的时候注意判断一下后缀到底存不存在，如果存在就逆序输出答案。

```c
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
```
-FIN-
