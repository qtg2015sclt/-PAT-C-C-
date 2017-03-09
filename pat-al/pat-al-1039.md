1039.Course List for Student (25)...to be continued...

pat-al-1036

2017-02-24

- 一道大坑的题，看了题觉得用map和set来写，然而！竟然会超时，因为数据量太大了
- 启发：遇到比较大的数据量，避免cout和cin，以及考虑用vector来写而非数组，也尽量不要用map来写

```c++
/**
 * pat-al-1036
 * 2017-02-24
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#define MAX (26*26*26*10+1)
using namespace std;
vector<int> course[MAX];
int convert2ID(char name[])
{
  int id = 0;
  for(int i = 0;i < 3;i++)
  {
    id = id*26 + name[i] - 'A';
  }
  id = id*10 + name[3] - '0';
  return id;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, k;
  int index, ni;
  char name[5];
  int id;
  scanf("%d%d", &n, &k);
  for(int i = 0;i < k;i++)
  {
    scanf("%d%d", &index, &ni);
    for(int j = 0;j < ni;j++)
    {
      scanf("%s", name);
      id = convert2ID(name);
      course[id].push_back(index);
    }
  }
  for(int i = 0;i < n;i++)
  {
    scanf("%s", name);
    id = convert2ID(name);
    sort(course[id].begin(), course[id].end());
    printf("%s %lu", name, course[id].size());
    for(int j = 0;j < course[id].size();j++)
    {
      printf(" %d", course[id][j]);
    }
    putchar('\n');
  }
  return 0;
}
```
-TBC-
