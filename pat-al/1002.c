/**
 * pat-al-1002
 * 2017-01-30
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  double hs1[1001] = {0}, hs2[1001] = {0};
  int k1, k2;
  scanf("%d", &k1);
  for(int i = 0;i < k1;i++)
  {
    int tmpE;
    double tmpC;
    scanf("%d %lf", &tmpE, &tmpC);
    hs1[tmpE] = tmpC;
    //printf("hs1[%d] = %.1lf\n", tmpE, tmpC);
  }
  scanf("%d", &k2);
  for(int i = 0;i < k2;i++)
  {
    int tmpE;
    double tmpC;
    scanf("%d %lf", &tmpE, &tmpC);
    hs2[tmpE] = tmpC;
    //printf("hs2[%d] = %.1lf\n", tmpE, tmpC);
  }
  double result[1001];
  int i, cnt = 0;
  for(i = 0;i < 1001;i++)
  {
    result[i] = hs1[i] + hs2[i];
    if(result[i] != 0)
      cnt++;
  }
  printf("%d", cnt);
  for(i = i-1;i >= 0;i--)
  {
    if(result[i] != 0)
      printf(" %d %.1lf", i, result[i]);
  }
  putchar('\n');
}
