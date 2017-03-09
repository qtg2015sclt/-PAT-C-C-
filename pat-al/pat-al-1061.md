pat-al-1061

2017-01-27

- 读题一定要仔细。前两行找的是大写字母，后两行找的英文字母。
- 坑具体见注释（就是每个判断都要限制一下）

```c
/**
 * pat-al-1061
 * 2017-01-27
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  char Day[8][4] = {"0", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};//0用来占位
  freopen("in.txt", "r", stdin);
  char input[4][70];
  scanf("%s %s %s %s", input[0], input[1], input[2], input[3]);
  int i;
  for(i = 0;i < strlen(input[0]) && i < strlen(input[1]);i++)
  {
    if(input[0][i] == input[1][i] && input[0][i] >= 'A' && input[0][i] <= 'G')//坑：注意是限制A-G，因为最多到G
    {
      printf("%s ", Day[input[0][i] - 'A' + 1]);
      break;
    }
  }
  for(i = i+1;i < strlen(input[0]) && i < strlen(input[1]);i++)
  {
    if(input[0][i] == input[1][i])
    {
      if(input[0][i] >= 'A' && input[0][i] <= 'N')//限制A-N，理由同「坑」
      {
        printf("%d:", input[0][i] - 'A' + 10);
        break;
      }
      else if(input[0][i] >= '0' && input[0][i] <= '9')//0-9要和字母分开判断
      {
        printf("0%c:", input[0][i]);
        break;
      }
    }
  }
  for(i = 0;i < strlen(input[2]) && i < strlen(input[3]);i++)
  {
    if(input[2][i] == input[3][i])
    {
      if((input[2][i] <= 'Z' && input[2][i] >= 'A') || (input[2][i] <= 'z' && input[2][i] >= 'a'))
      {
        printf("%02d\n", i);
      }
    }
  }
}
```
-FIN-
