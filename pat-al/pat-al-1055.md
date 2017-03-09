1055.The World's Richest (25)

pat-al-1055

2017-02-08

- 一开始思路是这样的：先按年龄排序，然后对每一查询，找到起始和结束的下标，将这一段按题意排序，依次输出，其中有些对于None情况的特殊判断，然后进行一次排序将数组还原。有一个测试点超时。
- 查了查，发现有些说暴力排序会超时，要换方法，但是查到这个：[solution Of 1055. The World's Richest (25)](http://blog.csdn.net/qq_30490125/article/details/51731291)所以说直接查询就好了，是我（们）想复杂了。

```c++
/**
 * pat-al-1055
 * 2017-2-08
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct WLTH
{
  char name[10];
  int age;
  int worth;
}wlth[100002];
bool cmp(WLTH a, WLTH b)//按财富非升序排序，财富相同按年龄非降序排序，前两者都相同，按姓名非降序排序
{
  if(a.worth != b.worth)
    return a.worth > b.worth;
  else
  {
    if(a.age != b.age)
      return a.age < b.age;
    else
      return strcmp(a.name, b.name) < 0;
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0;i < n;i++)
  {
    scanf("%s%d%d", wlth[i].name, &wlth[i].age, &wlth[i].worth);
  }
  sort(wlth, wlth+n, cmp);
  // for(int i = 0;i < n;i++)
  // {
  //   printf("%s %d %d\n", wlth[i].name, wlth[i].age, wlth[i].worth);
  // }
  for(int i = 0;i < k;i++)
  {
    int m, amin, amax;
    scanf("%d%d%d", &m, &amin, &amax);
    printf("Case #%d:\n", i+1);
    int cnt = 0;
    for(int j = 0;j < n;j++)
    {
      if(wlth[j].age >= amin && wlth[j].age <= amax)
      {
        printf("%s %d %d\n", wlth[j].name, wlth[j].age, wlth[j].worth);
        cnt++;
      }
      if(cnt == m)
        break;
    }
    if(cnt == 0)
      printf("None\n");
  }
  return 0;
}
```
-FIN-
