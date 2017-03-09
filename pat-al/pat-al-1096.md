1096.Consecutive Factors (20)

pat-al-1096

2017-01-28

- 完全参考了[1096. Consecutive Factors (20)-PAT甲级真题](http://www.liuchuo.net/archives/2110)
- 题意：对一个给定的n，找出其最长的连续因子；如果长度相等时，输出起始值较小的那个序列
- 思想：因为给定数范围的限制（int的范围），最多能允许12位数连乘，那么要求最长连续因子，就从len = 12开始暴力搜索，每一次搜索以初始因子为2开始连乘（因为要求不包括1），直到连乘的个数等于当前的len，就把连乘的结果和给定的n相比较，如果相等就输出答案；如果不等，就把初始因子加一再继续，直到初始因子大于sqrt(n)就跳出，本次搜索失败进行下一次len的搜索。
- 关于为什么初始因子最大也不能超过sqrt(n)：这和求素数的一种限制是一样的——最大不超过sqrt(n)，如果从超过sqrt(n)的数开始，向后进行连乘就超过n了呀，自己可以在草稿纸上算一算。
- 一个测试点：n = 8064时，应该输出2*3*4，而不是6*7*8
- 坑见注释
- 这题我自己以前也写（抄）过，但写的好复杂，也看了一点别人写的，目前觉得上面给出链接这位同学的答案最简洁（一道只要理解了就很好做的题）

```c
/**
 * pat-al-1096
 * 2017-01-27
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<math.h>
int main()
{
  //本题没什么思路（甚至一开始题目都没读懂QAQ），完全参考了别人的，链接见md文件
  //test:
  // long result1 = 1;
  // for(int i = 0;i < 31;i++)
  //   result1 *= 2;
  // long result2 = 1;
  // for(int i = 1;i <= 12;i++)
  //   result2 *= i;
  // long result3 = 1;
  // for(int i = 1;i <= 13;i++)
  //   result3 *= i;
  // printf("result1 = %ld\n", result1);
  // printf("result2 = %ld\n", result2);
  // printf("result3 = %ld\n", result3);
  //test end
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int max = sqrt(n);
  for(int len = 12;len >= 1;len--)//坑：len必须是>=1，等于号必须加上，不然连乘因子数等于1的情况无法输出
  {
    for(int start = 2;start <= max;start++)
    {
      int ans = 1;
      for(int i = start;i - start <= len - 1;i++)
        ans *= i;
      if(n % ans == 0)
      {
        printf("%d\n%d", len, start);
        for(int i = start+1;i - start <= len - 1;i++)
          printf("*%d", i);
        putchar('\n');
        return 0;
      }
    }
  }
  printf("1\n%d\n", n);//坑，不加这句，素数会没有输出
}
```
-FIN-
