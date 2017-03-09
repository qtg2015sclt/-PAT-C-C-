pat-al-1065

2017-01-27

- 本来想用字符串处理的，后来想想觉得太麻烦，一条20分的题，应该有别的做法
- 然后发现范围正好是卡在long long上的，只要不是边界问题（相加后溢出）就都能直接得出答案
- 那么就是怎么处理溢出时候的问题，参考[PAT 解题报告 1065. A+B and C (64bit) (20)](http://www.sigmainfy.com/blog/pat-1065-ab-and-c-64bit.html)中链接到的另一篇文章讲到了溢出判断
- 坑：两种溢出判断的方法，一开始我使用了第一种，结果第三个测试点没过去，就换成了第二种
- 注意：要用LLONG_MAX，要记得include头文件limits.h（climits）

```c
/**
 * pat-al-1065
 * 2017-01-27
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<limits.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int t;
  scanf("%d", &t);
  for(int i = 1;i <= t;i++)
  {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    long long sum = a + b;
    if(a > 0 && b > 0 && a > LLONG_MAX - b)//正溢出，大于范围内可输入的任何数
      printf("Case #%d: true\n", i);
    else if(a < 0 && b < 0 && a < LLONG_MIN - b)//负溢出，小于范围内可输入的任何数
      printf("Case #%d: false\n", i);
    else
    {
      if(sum > c)
        printf("Case #%d: true\n", i);
      else
        printf("Case #%d: false\n", i);
    }
  }
}
```
-FIN-
