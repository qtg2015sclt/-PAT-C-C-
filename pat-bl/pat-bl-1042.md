pat-bl-1042

2017-01-21

- 用数组保存出现次数

```c
/**
 * pat-bl-1042
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>

int main()
{
  //freopen("in.txt", "r", stdin);
  char str[1002];
  fgets(str, sizeof(str), stdin);
  int hs[128] = {0};//用大小为26的数组也可以
  for(int i = 0;i < strlen(str);i++)
  {
    if(str[i] <= 'Z' && str[i] >= 'A')//遇到字母就自加
      hs[str[i] + 32]++;
    else if(str[i] <= 'z' && str[i] >= 'a')
      hs[str[i]]++;
  }
  int maxCnt = 0;
  char maxLetter;
  for(int i = 'a';i <= 'z';i++)//用char也行
  {
    if(maxCnt < hs[i])
    {
      maxCnt = hs[i];
      maxLetter = i;
    }
  }
  printf("%c %d\n", maxLetter, maxCnt);
}
```
-FIN-
