1037.Magic Coupon (25)

pat-al-1037

2017-02-06

- 要得到最大的和，每次要从两行中各取出一个数，使之乘积为当前能找到的最大，那肯定是正数和正数相乘、负数和负数相乘（取绝对值最大的）。
- 先从小到大排序，把负数相乘；再从大到小排序，把正数相乘。

```c++
/**
 * pat-al-1037
 * 2017-02-06
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp1(int a, int b)
{
  return a < b;
}
bool cmp2(int a, int b)
{
  return a > b;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int nc, np;
  scanf("%d", &nc);
  int coupon[nc];
  for(int i = 0;i < nc;i++)
  {
    scanf("%d", &coupon[i]);
    //printf("%d\n", coupon[i]);
  }
  scanf("%d", &np);
  int product[np];
  for(int i = 0;i < np;i++)
  {
    scanf("%d", &product[i]);
  }
  sort(coupon, coupon+nc, cmp1);
  sort(product, product+np, cmp1);
  int i = 0, sum = 0;
  while(coupon[i] < 0 && product[i] < 0)
  {
    //printf("coupon = %d, product = %d\n", coupon[i], product[i]);
    sum += coupon[i]*product[i];
    i++;
  }
  sort(coupon, coupon+nc, cmp2);
  sort(product, product+np, cmp2);
  i = 0;
  while(coupon[i] > 0 && product[i] > 0)
  {
    sum += coupon[i]*product[i];
    i++;
  }
  printf("%d\n", sum);
}
```
-FIN-
