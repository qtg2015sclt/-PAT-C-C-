1048.Find Coins (25)

pat-al-1048

2017-02-23

- 排个序，指针从两边开始找

```c++
/**
 * pat-al-1048
 * 2017-02-23
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m;
  scanf("%d%d", &n, &m);
  int num[n];
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &num[i]);
  }
  sort(num, num+n);
  // for(int i = 0;i < n;i++)
  // {
  //   printf("%d ", num[i]);
  // }
  int i = 0, j = n-1;
  while(i < j)
  {
    //printf("%d %d\n", num[i], num[j]);
    if(num[i] + num[j] > m)
      j--;
    else if(num[i] + num[j] < m)
      i++;
    else
    {
      printf("%d %d\n", num[i], num[j]);
      return 0;
    }
  }
  printf("No Solution\n");
  return 0;
}
```
-FIN-
