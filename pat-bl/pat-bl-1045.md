pat-bl-1045

2017-01-22

- 这题有点困难
- 暴力搜索肯定超时，所以一开始做了个排序，比较一下，哪个和最终位置一样那就是主元，结果有很多测试点过不了
- 过不了的那些测试点其实是因为思路有问题，比如1 2 5 4 3和排序结果1 2 3 4 5比较，按照我的方法4应该是主元，但其实并不是
- 也就是说位置相同不一定是主元，还要再做判断，我查了一下，有一些就是使用的这种方法，就是排序+判断
- 但我看到了一个无须排序的方法：http://www.jianshu.com/p/fd3e0be745e1
- 这种方法采用的是开一个数组，对每一个读入的当前数，存储它前面的数中最大的那个（也就是说不包括自己），然后从后向前遍历做比较，根据当前数是否比存的最大数还大来判断左边是否有比自己大的数，而之所以从后向前遍历是为了一起和最小值比较来判断右边是否有比自己小的数，且在每次遇到更小数的就更新
- 一个坑：当找不到主元的时候，控制一下输出，只输出0就好。有一个测试点包含这个

```c
/**
 * pat-bl-1045
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
  int num[n], maxArr[n], max = 0;
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &num[i]);
    maxArr[i] = max;//maxArr保存当前数之前的数中最大的那个
    if(num[i] > max)//每个数都不相同，无需考虑等于号
      max = num[i];
  }
  // for(int i = 0;i < n;i++)
  //   printf("%d ", maxArr[i]);
  // putchar('\n');
  int min = 1000000001;//因为每个数不超过10^9
  int result[n], k = 0;
  // for(int i = 0;i < n;i++)
  //   printf("%d ", result[i]);
  // putchar('\n');
  for(int i = n-1;i >= 0;i--)
  {
    if(num[i] < min)//更新当前最小值
    {
      if(num[i] > maxArr[i])//如果比最小值还小，且比之前的所有数都大，说明可能是主元
        result[k++] = num[i];
      min = num[i];
    }
  }
  printf("%d\n", k);
  if(k != 0)//当没有找到可能的划分主元时不输出
    printf("%d", result[--k]);
  for(k = k-1;k >= 0;k--)
  {
    printf(" %d", result[k]);
  }
  putchar('\n');
}
```
-FIN-
