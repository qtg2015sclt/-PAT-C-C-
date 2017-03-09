1004.Counting Leaves (30)

pat-al-1004

2017-02-03

- 深搜和广搜都可以

```c++
/**
 * pat-al-1004
 * 2017-02-03
 * Cpp version
 * dfs
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[101];//坑：不是圆括号，是[]
int result[101], maxDepth = -1;
void dfs(int id, int depth)
{
  if(v[id].size() == 0)
  {
    result[depth]++;
    if(depth > maxDepth)
      maxDepth = depth;
    return;
  }
  for(int i = 0;i < v[id].size();i++)
  {
    dfs(v[id][i], depth+1);
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0;i < m;i++)
  {
    int father, k, child;
    scanf("%d%d", &father, &k);
    for(int j = 0;j < k;j++)
    {
      scanf("%d", &child);
      v[father].push_back(child);
    }
  }
  dfs(1, 0);
  printf("%d", result[0]);
  for(int i = 1;i <= maxDepth;i++)
  {
    printf(" %d", result[i]);
  }
  putchar('\n');
  return 0;
}
```
```c++
/**
 * pat-al-1004
 * 2017-02-03
 * Cpp version
 * bfs
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[101];
int result[101], level[101], maxLevel = -1;//level用来记录每个节点对应的层数
void bfs()
{
  queue<int> q;
  q.push(1);
  level[1] = 0;
  while(!q.empty())
  {
    int id = q.front();
    q.pop();
    if(maxLevel < level[id])
      maxLevel = level[id];
    if(v[id].size() == 0)
      result[level[id]]++;
    for(int i = 0;i < v[id].size();i++)
    {
      q.push(v[id][i]);
      level[v[id][i]] = level[id]+1;
    }
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0;i < m;i++)
  {
    int father, k, child;
    scanf("%d%d", &father, &k);
    for(int j = 0;j < k;j++)
    {
      scanf("%d", &child);
      v[father].push_back(child);
    }
  }
  bfs();
  printf("%d", result[0]);
  for(int i = 1;i <= maxLevel;i++)
    printf(" %d", result[i]);
  putchar('\n');
}
```
-FIN-
