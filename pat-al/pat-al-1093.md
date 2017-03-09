1093.Count PAT's (25)...to be continued...

pat-al-1093

2017-03-02

- 乙级好像有这题
- 暴力会超时，对于每个A，只要知道它前面多少个P和后面有多少T

```c++
/**
 * pat-al-1093
 * 2017-03-02
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#define MAX 100010
int main()
{
  freopen("in.txt", "r", stdin);
  char str[MAX];
  scanf("%s", str);
  int numOfP[MAX] = {0};
  int len = strlen(str);
  for(int i = 0;i < len;i++)
  {
    if(i > 0 && str[i] == 'P')
    {
      numOfP[i] = numOfP[i-1]+1;
    }
    else if(i == 0 && str[i] == 'P')
    {
      numOfP[i] = 1;
    }
    else
      numOfP[i] = numOfP[i-1];
    //printf("i: %d\n", numOfP[i]);
  }
  int numOfT = 0;
  int ans = 0;
  for(int i = len-1;i >= 0;i--)
  {
    if(i == len-1 && str[i] == 'T')
      numOfT = 1;
    else if(i < len-1 && str[i] == 'T')
      numOfT++;
    else if(str[i] == 'A')
    {
      ans += (numOfT * numOfP[i]);
      ans %= 1000000007;
    }
  }
  printf("%d\n", ans);
  return 0;
}
```
-TBC-
