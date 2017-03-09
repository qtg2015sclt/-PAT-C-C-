/**
 * pat-bl-1026
 * 2017-01-20
 * C version
 */
#include<stdio.h>
#include<time.h>
#define CLK_TCK 100

int main()
{
  freopen("in.txt", "r", stdin);
  double c1, c2, result;
  scanf("%lf %lf", &c1, &c2);
  result = (c2 - c1 + CLK_TCK / 2) / CLK_TCK;//出错点2：加上CLK_TCK的一半来处理四舍五入
  int hh = result / 3600;
  result -= hh * 3600;
  int mm = result / 60;
  result -= mm * 60;
  int ss = result;
  if(ss == 60)//出错点1：因为要四舍五入，所以要注意进位问题
  {
    ss = 0;
    mm++;
  }
  if(mm == 60)
  {
    mm = 0;
    hh++;
  }
  //printf("ss = %lf\n", result);
  printf("%02d:%02d:%02d\n", hh, mm, ss);
}
