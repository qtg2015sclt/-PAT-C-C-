1007.Maximum Subsequence Sum (25)

pat-al-1007

2017-02-04

- 最大子段和，动态规划典型题
- 为什么maxSum必须设置为-1，不然有个测试点过不了，想不通，好气哦_(:з」∠)_ 如果有知道的请告诉我谢谢⁄(⁄ ⁄•⁄ω⁄•⁄ ⁄)⁄

```c
/**
 * pat-al-1007
 * 2017-02-04
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int k;
  scanf("%d", &k);
  int num[k];
  int sum = 0, maxSum = -1;//坑：maxSum必须设置为-1，不然一个测试点过不了，原因不明
  int start = 0, maxEnd = 0, maxStart = 0;
  int flag = 0;
  for(int i = 0;i < k;i++)
  {
    scanf("%d", &num[i]);
    //printf("num = %d\n", num[i]);
    if(num[i] >= 0)//注意：要特殊判断一下是否全是负数
      flag = 1;
    sum += num[i];
    if(sum > maxSum)
    {
      maxSum = sum;
      maxStart = start;
      maxEnd = i;
    }
    if(sum < 0)
    {
      sum = 0;
      start = i+1;
    }
  }
  if(flag == 1)
    printf("%d %d %d\n", maxSum, num[maxStart], num[maxEnd]);
  else
    printf("0 %d %d\n", num[0], num[k-1]);
  return 0;
}
```
-FIN-
