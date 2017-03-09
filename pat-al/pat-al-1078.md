1078.Hashing (25)

pat-al-1078

2017-03-01

- 要求的素数范围不大，用简单的求法就可以，具体见代码
- 主要是二次探测法，题目只要求i为正数的情况，稍微简单一点，注意i最多为（表的大小-1）/2
- 如果忘记二次探测法，就不写了，也能获得20分，启发：如果不能全做对，也尽量作出更高的分数

```c++
/**
 * pat-al-1078
 * 2017-03-01
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#define MAX 10010
int main()
{
  int prime[MAX] = {1, 1, 0, 0};//0表示是素数，1表示非素数
  for(int i = 2;i * i < MAX;i++)
    for(int j = 2;i * j < MAX;j++)
      prime[i*j] = 1;
  freopen("in.txt", "r", stdin);
  int MSize, n, num, hs[MAX];
  memset(hs, -1, sizeof(hs));
  scanf("%d%d\n", &MSize, &n);
  while(prime[MSize] == 1)
    MSize++;
  int incre, flagFail = 1;
  scanf("%d", &num);
  if(hs[num%MSize] == -1)
  {
    hs[num%MSize] = num;
    printf("%d", num%MSize);
  }
  else
  {
    for(incre = 1;incre < (MSize-1)/2;incre++)
    {
      if(hs[(num+incre*incre)%MSize] == -1)
      {
        hs[(num+incre*incre)%MSize] = num;
        printf("%d", (num+incre*incre)%MSize);
        flagFail = 0;
        break;
      }
    }
    if(flagFail == 1)
      printf("-");
  }
  for(int i = 1;i < n;i++)
  {
    flagFail = 1;
    scanf("%d", &num);
    if(hs[num%MSize] == -1)
    {
      hs[num%MSize] = num;
      printf(" %d", num%MSize);
    }
    else
    {
      for(incre = 1;incre < (MSize-1)/2;incre++)
      {
        if(hs[(num+incre*incre)%MSize] == -1)
        {
          hs[(num+incre*incre)%MSize] = num;
          printf(" %d", (num+incre*incre)%MSize);
          flagFail = 0;
          break;
        }
      }
      if(flagFail == 1)
        printf(" -");
    }
  }
  putchar('\n');
  return 0;
}
```
-FIN-
