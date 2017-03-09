1101.Quick Sort (25)

pat-al-1101

2017-03-02

- 思路和1093差不多，都是从前向后和从后向前扫描记录当前最大/最小的数据，和当前数据做比较
- 坑见注释

```c++
/**
 * pat-al-1101
 * 2017-03-02
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#define MAX 100010
int main()
{
  freopen("in.txt", "r", stdin);
  int n, num[MAX], flagPartition[MAX] = {0}, maxNow[MAX];//maxNow其实可以不用数组
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &num[i]);
    if(i > 0 && maxNow[i-1] < num[i])
    {
      maxNow[i] = num[i];
      flagPartition[i] = 1;
    }
    else if(i == 0)
    {
      maxNow[i] = num[i];
      flagPartition[i] = 1;
    }
    else
      maxNow[i] = maxNow[i-1];
  }
  int minNow;
  for(int i = n-1;i >= 0;i--)
  {
    if(i == n-1)
      minNow = num[i];
    else if(i < n-1 && minNow > num[i])
    {
      minNow = num[i];
    }
    else
    {
      flagPartition[i] = 0;
    }
  }
  int cnt = 0;
  for(int i = 0;i < n;i++)
  {
    if(flagPartition[i] == 1)
      cnt++;
  }
  printf("%d\n", cnt);
  int flagFirst = 1;
  for(int i = 0;i < n;i++)
  {

    if(flagPartition[i] == 1)
    {
      if(flagFirst == 1)
        flagFirst = 0;
      else
        printf(" ");
      printf("%d", num[i]);
    }
  }
  putchar('\n');
  return 0;
}
```
-FIN-
