1063.Set Similarity (25)

pat-al-1063

2017-03-01

- 用set做比较简单
- 题目不难，不过一开始是想着使用公式：（len1 + len2 - len3）/len3，但这样需要将待查询的两个set合并，最后一个测试点超时
- 然后换了比较的方式，就AC了。要注意的是set中的find函数，是通过其返回值是否等于s.end()来判断的，返回值并不是布尔类型（true和false）

```c++
/**
 * pat-al-1063
 * 2017-03-01
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
set<int> s[51];
void solve(int x, int y)
{
  int share = 0, total = s[y].size();
  for(set<int>::iterator it = s[x].begin();it != s[x].end();it++)
  {
    if(s[y].find(*it) != s[y].end())
      share++;
    else
      total++;
  }
  printf("%0.1lf%%\n", 100.0*share/total);
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m, tmpNum, k, q1, q2;
  scanf("%d", &n);
  for(int i = 1;i <= n;i++)
  {
    scanf("%d", &m);
    for(int j = 0;j < m;j++)
    {
      scanf("%d", &tmpNum);
      s[i].insert(tmpNum);
    }
  }
  scanf("%d", &k);
  for(int i = 0;i < k;i++)
  {
    scanf("%d%d", &q1, &q2);
    solve(q1, q2);
  }
  return 0;
}
```
-FIN-
