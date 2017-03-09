pat-bl-1053

2017-01-22

- 坑：空置和可能空置是互斥的
- 计算一半以上那个用double类型比较方便

```c
/**
 * pat-bl-1053
 * 2017-01-22
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  double n, e, d;
  scanf("%lf %lf %lf", &n, &e, &d);
  double cntNil = 0, cntMaybeNil = 0;
  for(int i = 0;i < n;i++)
  {
    double k, tmp, tmpCnt = 0;//都用double是比较方便的
    scanf("%lf", &k);
    for(int j = 0;j < k;j++)//观察k天
    {
      scanf("%lf", &tmp);
      //printf("tmp = %.1lf\n", tmp);
      if(tmp < e)
        tmpCnt++;
    }
    //printf("tmpCnt = %.0lf\n", tmpCnt);
    if(tmpCnt > k/2)//出错：第一次写错了……
    {
      if(k > d)
      {
        //printf("nil: %d\n", i);
        cntNil++;
      }
      else
      {
        //printf("maybenil: %d\n", i);
        cntMaybeNil++;//坑：如果是空置，那么就不被包含在可能空置中了
      }
    }
  }
  printf("%.1lf%% %.1lf%%\n", cntMaybeNil/n*100, cntNil/n*100);
}
```
-FIN-
