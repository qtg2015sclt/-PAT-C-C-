pat-bl-1057

2017-01-23

- 本题无坑

```c
/**
 * pat-bl-1057
 * 2017-01-23
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>

int main()
{
  freopen("in.txt", "r", stdin);
  char ch;
  int sum = 0;
  while((ch = getchar()) != '\n')
  {
    if(ch <= 'Z' && ch >= 'A')
    {
      sum += ch - 'A' + 1;
    }
    else if(ch <= 'z' && ch >= 'a')
    {
      sum += ch - 'a' + 1;
    }
  }
  int cntZero = 0, cntOne = 0;
  while(sum)
  {
    if(sum % 2 == 1)
      cntOne++;
    else
      cntZero++;
    sum /= 2;
  }
  printf("%d %d\n", cntZero, cntOne);
}
```
-FIN-
