/**
 * pat-al-1009
 * 2017-02-15
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  double hs1[1001] = {0}, hs2[1001], result[2001] = {0};//坑：要记得给hs1初始化，不然会不知道数组里存的到底是什么鬼
  freopen("in.txt", "r", stdin);
  int k1, k2;
  scanf("%d", &k1);
  for(int i = 0;i < k1;i++)
  {
    int tmpE;
    double tmpC;
    scanf("%d%lf", &tmpE, &tmpC);
    //printf("tmpE = %d, tmpC = %.1lf\n", tmpE, tmpC);
    hs1[tmpE] = tmpC;
  }
  scanf("%d", &k2);
  for(int i = 0;i < k2;i++)
  {
    int tmpE;
    double tmpC;
    scanf("%d%lf", &tmpE, &tmpC);
    //printf("tmpE = %d, tmpC = %.1lf\n", tmpE, tmpC);
    for(int j = 0;j <= 1000;j++)
    {
      if(hs1[j]*tmpC != 0)
      {
        //printf("hs1[%d] = %.1lf, tmpC = %.1lf\n", j, hs1[j], tmpC);
        result[tmpE+j] += hs1[j]*tmpC;
      }
    }
    hs2[tmpE] = tmpC;
  }
  int cnt = 0;
  for(int i = 0;i <= 2000;i++)
  {
    if(result[i] != 0)
      cnt++;
  }
  printf("%d", cnt);
  for(int i = 2000;i >= 0;i--)
  {
    if(result[i] != 0)
      printf(" %d %.1lf", i, result[i]);
  }
  putchar('\n');
}
