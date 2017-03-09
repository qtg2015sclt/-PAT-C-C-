pat-bl-1049

2017-01-22

- 一个数学问题，在草稿纸上写写，找出规律就可以了
- 坑：计算中要强制转换一下，否则会出错，应该是int的大小不够存放了

```c
/**
 * pat-bl-1049
 * 2017-01-22
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  double tmp, sum = 0;
  for(int i = 0;i < n;i++)
  {
    scanf("%lf", &tmp);
    sum += (double)(i + 1) * (n - i) * tmp;//不加double会出错
  }
  printf("%.2lf\n", sum);
}
```
-FIN-
