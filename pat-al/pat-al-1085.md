1085.Perfect Sequence (25)...to be contined...

pat-al-1085

2017-02-23

- 参考：《算法笔记：上机训练实战指南》机械工业出版社
- 坑见注释

```c++
/**
 * pat-al-1085
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
  int n, p;
  scanf("%d%d", &n, &p);
  int num[n];
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &num[i]);
  }
  sort(num, num+n);
  int i = 0, j = 0, cnt = 0;
  while(i < n && j < n)
  {
    while(j < n && num[j] <= (long long)num[i]*p)//坑，必须加上(long long)，不然有个测试点会答案错误
    {
      cnt = max(cnt, j - i + 1);
      j++;
    }
    i++;
  }
  printf("%d\n", cnt);
  return 0;
}
```
-TBC-
