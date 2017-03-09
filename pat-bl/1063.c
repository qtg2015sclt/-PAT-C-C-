/**
 * pat-bl-1063
 * 2017-01-24
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<math.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  double mod, maxMod = 0;
  for(int i = 0;i < n;i++)
  {
    double a, b;
    scanf("%lf %lf", &a, &b);
    //printf("%lf %lf\n", a, b);
    mod = sqrt(a * a + b * b);
    if(maxMod < mod)
      maxMod = mod;
  }
  printf("%.2lf\n", maxMod);
}
