pat-bl-1062

2017-01-23

- 一开始想的不对，写出来都超时了
- 然后改的还是不对，写的太复杂
- 坑：是在两个数之间，不能包括等于的情况，有个测试点测这个

```c
/**
 * pat-bl-1062
 * 2017-01-23
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int gcd(int a, int b)//求最大公约数
{
  return b == 0 ? a : gcd(b, a%b);
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n1, m1, n2, m2, k;
  int flag = 1;//是输出的第一个数
  scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
  //printf("k = %d\n", k);
  if(n1 * m2 > n2 * m1)//如果前一个数比后一个数大，就交换一下
  {
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
    tmp = m1;
    m1 = m2;
    m2 = tmp;
  }
  for(int i = 1;i < k;i++)//找分子
  {
    if(gcd(i, k) != 1)//i和k不互质的话直接下一个
      continue;
    //和第一个分数比较
    if(i * m1 <= n1 * k)//坑：要加上等号
      continue;
    //和第二个分数比较
    if(i * m2 >= n2 * k)
      continue;
    if(flag)
    {
      flag = 0;
      printf("%d/%d", i, k);
    }
    else
      printf(" %d/%d", i, k);
  }
  putchar('\n');
}
```
-FIN-
