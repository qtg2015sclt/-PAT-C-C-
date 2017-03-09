/**
 * pat-bl-1051
 * 2017-01-22
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<math.h>
int main()
{
  freopen("in.txt", "r", stdin);
  double r1, p1, r2, p2;
  scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
  double resultA, resultB;
  resultA = r1 * r2 * cos(p1 + p2);
  resultB = r1 * r2 * sin(p1 + p2);
  //test:
  //resultB = 0.005;
  if(fabs(resultA) < 0.01)//坑：精确度的问题
    resultA = 0;
  if(fabs(resultB) < 0.01)
    resultB = 0;
  if(resultB < 0)
    printf("%.2lf%.2lfi\n", resultA, resultB);
  else
    printf("%.2lf+%.2lfi\n", resultA, resultB);
}
