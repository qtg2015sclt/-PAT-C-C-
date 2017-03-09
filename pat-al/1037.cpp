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
