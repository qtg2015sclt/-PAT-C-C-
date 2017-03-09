1047.Student List for Course (25)...to be continued...

pat-al-1047

2017-02-24

- 用字符数组来映射name和下标，然后在课程的容器里保存每个人的下标就好了
- 注意此处cmp的写法，因为实际比较的是name的字典顺序，而需要用到的是下标

```c++
/**
 * pat-al-1047
 * 2017-02-24
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#define MAXN 40010
#define MAXK 2510
using namespace std;
char name[MAXN][5];
vector<int> course[MAXK];
bool cmp(int a, int b)//比较的是int
{
  return strcmp(name[a], name[b]) < 0;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, k, c, index;
  scanf("%d%d", &n, &k);
  for(int i = 0;i < n;i++)
  {
    scanf("%s %d", name[i], &c);
    for(int j = 0;j < c;j++)
    {
      scanf("%d", &index);
      course[index].push_back(i);
    }
  }
  for(int i = 1;i <= k;i++)
  {
    printf("%d %lu\n", i, course[i].size());
    sort(course[i].begin(), course[i].end(), cmp);
    for(int j = 0;j < course[i].size();j++)
    {
      printf("%s\n", name[course[i][j]]);
    }
  }
}
```
-TBC-
