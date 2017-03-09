1053.Path of Equal Weight (30)...to be continued...

pat-al-1053

2017-02-27

- 主要是复习一下dfs

```c++
/**
 * pat-al-1053
 * 2017-02-27
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 110
using namespace std;
struct NODE
{
  int weight;
  vector<int> child;
}node[MAX];
bool cmp(int a, int b)
{
  return node[a].weight > node[b].weight;
}
int n, m, s;
int path[MAX];
void dfs(int index, int numNode, int sum)
{
  if(sum > s)
    return;
  if(sum == s)
  {
    if(node[index].child.size() != 0)
      return;
    printf("%d", node[path[0]].weight);
    for(int i = 1;i < numNode;i++)
    {
      printf(" %d", node[path[i]].weight);
    }
    putchar('\n');
    return;
  }
  for(int i = 0;i < node[index].child.size();i++)
  {
    int child = node[index].child[i];
    path[numNode] = child;
    dfs(child, numNode+1, sum+node[child].weight);
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  scanf("%d%d%d", &n, &m, &s);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &node[i].weight);
  }
  int id, k, child;
  for(int i = 0;i < m;i++)
  {
    scanf("%d%d", &id, &k);
    for(int j = 0;j < k;j++)
    {
      scanf("%d", &child);
      node[id].child.push_back(child);
    }
    sort(node[id].child.begin(), node[id].child.end(), cmp);
  }
  path[0] = 0;
  dfs(0, 1, node[0].weight);
  return 0;
}
```
-TBC-
