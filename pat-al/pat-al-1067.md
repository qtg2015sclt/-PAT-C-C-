1067.Sort with Swap(0,*) (25)...to be continued...

pat-al-1067

2017-03-01

- pos[i]的内容表示的是：数字i所在的位置；这样来简化操作。
- 一个注意的地方，如果0换到最终位置上要把它跟不在自己最终位置上的数（此处选的是最小的那个）交换；而且本次交换也要记录
- 搞不懂的话先手工模拟一下

```c++
/**
 * pat-al-1067
 * 2017-03-01
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#define MAX 100010
using namespace std;
int main()
{
  freopen("in.txt", "r", stdin);
  int n, pos[MAX], num, diffrent, min = 1, tmp, cnt = 0;
  scanf("%d", &n);
  diffrent = n-1;
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &num);
    pos[num] = i;
    if(num == i)
      diffrent--;
  }
  while(diffrent > 0)
  {
    if(pos[0] == 0)
    {
      while(min < n)
      {
        if(pos[min] != min)
        {
          swap(pos[0], pos[min]);
          cnt++;
          break;
        }
        min++;
      }
    }
    while(pos[0] != 0)
    {
      swap(pos[0], pos[pos[0]]);
      diffrent--;
      cnt++;
      // for(int i = 0;i < n;i++)
      // {
      //   for(int j = 0;j < n;j++)
      //   {
      //     if(pos[j] == i)
      //       printf("%d ", j);
      //   }
      // }
      // putchar('\n');
    }
    //printf("diffrent = %d\n", diffrent);
  }
  printf("%d\n", cnt);
  return 0;
}
```
-TBC-
