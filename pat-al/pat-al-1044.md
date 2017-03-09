1044.Shopping in Mars (25)...to be continued...

pat-al-1044

2017-02-26

- 二分法找距离x最近且不小于x的数upper_bound函数的写法

```c++
/**
 * pat-al-1044
 * 2017-02-26
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#define MAX 100010
int sum[MAX];
int upper_bound(int l, int r, int x)
{
  int left = l, right = r, mid;
  while(left < right)
  {
    mid = (left + right) / 2;
    if(sum[mid] > x)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m;
  int nearS = 100000010;
  scanf("%d%d", &n, &m);
  sum[0] = 0;
  for(int i = 1;i <= n;i++)
  {
    scanf("%d", &sum[i]);
    sum[i] += sum[i-1];
  }
  for(int i = 1;i <= n;i++)
  {
    int j = upper_bound(i, n+1, sum[i-1]+m);
    if(sum[j-1] - sum[i-1] == m)
    {
      nearS = m;
      break;
    }
    else if(j <= n && sum[j] - sum[i-1] < nearS)
    {
      nearS = sum[j]- sum[i-1];
      //printf("%d-%d, %d\n", i-1, j, nearS);
    }
  }
  for(int i = 1;i <= n;i++)
  {
    int j = upper_bound(i, n+1, sum[i-1]+nearS);
    if(sum[j-1] - sum[i-1] == nearS)
    {
      printf("%d-%d\n", i, j-1);
    }
  }
  return 0;
}
```
-TBC-
