pat-bl-1056

2017-01-24

- 一道数学题，找到套路就好做
- 套路：每个数字在十位和各位出现的次数都是n-1

```c
/**
 * pat-bl-1056
 * 2017-01-24
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  int sum = 0;
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
  {
    int tmp;
    scanf("%d", &tmp);
    //printf("tmp = %d\n", tmp);
    sum += ((tmp * 10 + tmp) * (n-1));
  }
  printf("%d\n", sum);
}
```
-FIN-
