/**
 * pat-al-1011
 * 2017-01-26
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  double odd[3][3];
  double maxOdd[3];
  double factor = 1;
  for(int i = 0;i < 3;i++)
  {
    scanf("%lf %lf %lf", &odd[i][0], &odd[i][1], &odd[i][2]);
    if(odd[i][0] > odd[i][1])
    {
      if(odd[i][0] > odd[i][2])
      {
        printf("W ");
        factor *= odd[i][0];
      }
      else
      {
        printf("L ");
        factor *= odd[i][2];
      }
    }
    else
    {
      if(odd[i][1] > odd[i][2])
      {
        printf("T ");
        factor *= odd[i][1];
      }
      else
      {
        printf("L ");
        factor *= odd[i][2];
      }
    }
  }
  printf("%.2lf\n", (factor*0.65 - 1) * 2);//不需要加0.005来四舍五入
}
