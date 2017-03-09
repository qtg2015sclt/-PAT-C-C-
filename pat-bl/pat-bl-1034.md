pat-bl-1034

2017-01-21

- 题目不难，就是手工做分数四则运算的方法，写起来有点繁琐
- 求最大公约数用辗转相除法
- 一个大坑：题目说的是整型范围，至少要用long，用int过不了后两个测试点

```c
/**
 * pat-bl-1034
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<stdlib.h>
int gcd(long a, long b)
{
  //printf("a = %d, b = %d\n", a, b);
  return b == 0? a : gcd(b, a % b);
}
void printFraction(long a, long b)
{
  long k = 0;
  if(a < 0)
  {
    if(b == 1)
      printf("(%d)", a);
    else if(-1 * a > b)
    {
      k = a / b;
      a = (-1 * a) % b;
      printf("(%d %d/%d)", k, a, b);
    }
    else
      printf("(%d/%d)", a, b);
  }
  else if(a == 0)
    printf("0");
  else
  {
    if(b == 1)
      printf("%d", a);
    else if(a > b)
    {
      k = a / b;
      a = a % b;
      printf("%d %d/%d", k, a, b);
    }
    else
      printf("%d/%d", a, b);
  }
}
void Print(long a1, long b1, long a2, long b2, char ch)
{
  long c1, c2;
  long d;//最大公约数
  printFraction(a1, b1);
  printf(" %c ", ch);
  printFraction(a2, b2);
  printf(" = ");
  switch (ch) {
    case '+':
      c1 = a1 * b2 + a2 * b1;
      c2 = b1 * b2;
      //printf("c1 = %d, c2 = %d\n", c1, c2);
      d = abs(gcd(c1, c2));
      c1 /= d;
      c2 /= d;
      //printf("c1 = %d, c2 = %d\n", c1, c2);
      printFraction(c1, c2);
      break;
    case '-':
      c1 = a1 *b2 - a2 * b1;
      c2 = b1 * b2;
      d = abs(gcd(c1, c2));
      c1 /= d;
      c2 /= d;
      printFraction(c1, c2);
      break;
    case '*':
      c1 = a1 * a2;
      c2 = b1 * b2;
      d = abs(gcd(c1, c2));
      c1 /= d;
      c2 /= d;
      printFraction(c1, c2);
      break;
    case '/':
      c1 = a1 * b2;
      c2 = b1 * a2;
      d = abs(gcd(c1, c2));
      c1 /= d;
      c2 /= d;
      //printf("c1 = %d, c2 = %d\n", c1, c2);
      if(c2 == 0)
        printf("Inf");
      else if(c2 < 0)
        printFraction(-c1, -c2);
      else
        printFraction(c1, c2);
      break;
  }
  putchar('\n');
}

int main()
{
  freopen("in.txt", "r", stdin);
  long a1, b1, a2, b2;//long long?坑点：整型范围用int不行，后两个测试点过不了
  scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
  long d1 = abs(gcd(a1, b1));//求最大公约数
  long d2 = abs(gcd(a2, b2));
  a1 /= d1;//约分至最简
  b1 /= d1;
  a2 /= d2;
  b2 /= d2;
  //printf("%d/%d %d/%d\n", a1, b1, a2, b2);
  Print(a1, b1, a2, b2, '+');
  Print(a1, b1, a2, b2, '-');
  Print(a1, b1, a2, b2, '*');
  Print(a1, b1, a2, b2, '/');
}
```
-FIN-
