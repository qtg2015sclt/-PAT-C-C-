pat-bl-1038

2017-01-21

- 开一个数组，下标作为分数，每读入一个数，就把以该分数为下标的数组内容加一；输出的时候直接以下标查找然后输出
```c
/**
 * pat-bl-1038
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>

int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int tmp, hs[101] = {0};
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &tmp);
    hs[tmp]++;
  }
  int k;
  scanf("%d", &k);
  for(int i = 0;i < k-1;i++)
  {
    scanf("%d", &tmp);
    printf("%d ", hs[tmp]);
  }
  scanf("%d", &tmp);
  printf("%d\n", hs[tmp]);
}
```
-FIN-
