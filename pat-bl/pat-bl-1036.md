pat-bl-1036

2017-01-21

- 很简单，注意一下四舍五入取整就好

```c
/**
 * pat-bl-1036
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>

int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  char ch;
  scanf("%d %c", &n, &ch);
  int col = (n + 1) / 2;//四舍五入取整
  for(int i = 0;i < n;i++)
    putchar(ch);
  putchar('\n');
  for(int i = 0;i < col - 2;i++)
  {
    putchar(ch);
    for(int j = 0;j < n - 2;j++)
      putchar(' ');
    putchar(ch);
    putchar('\n');
  }
  for(int i = 0;i < n;i++)
    putchar(ch);
  putchar('\n');
}
```
-FIN-
