pat-al-1058

2017-01-27

- 无坑，注意进位

```c
/**
 * pat-al-1058
 * 2017-01-27
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int aG, aS, aK, bG, bS, bK;
  scanf("%d.%d.%d %d.%d.%d", &aG, &aS, &aK, &bG, &bS, &bK);
  int cG, cS, cK;
  cK = aK + bK;
  if(cK >= 29)
  {
    cS = cK / 29;
    cK = cK % 29;
  }
  cS += aS + bS;
  if(cS >= 17)
  {
    cG = cS / 17;
    cS = cS % 17;
  }
  cG += aG + bG;
  printf("%d.%d.%d\n", cG, cS, cK);
}
```
-FIN-
