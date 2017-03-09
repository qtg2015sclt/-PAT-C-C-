pat-bl-1021

2016-12-18

- 哈希表的入门小应用，很简单的一题

```c
/**
 *pat-bl-1021
 *2016-12-18
 *C version
 *
 */
#include<stdio.h>

int main()
{
  char tmp;
  int hs[10] = {0};
  freopen("in.txt", "r", stdin);
  while (scanf("%c", &tmp) != EOF)
  {
    hs[tmp - '0']++;
  }
  for(int i = 0;i < 10;i++)
  {
    if(hs[i] != 0)
    {
      printf("%d:%d\n", i, hs[i]);
    }
  }
}
```
-FIN-
