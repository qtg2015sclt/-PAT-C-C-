1013.Battle Over Cities (25)

pat-al-1013

2017-02-03

- 相当于求连通分量。遍历一遍，用dfs和bfs都可以，感觉dfs更简单一点

```c
/**
 * pat-al-1013
 * 2017-02-03
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#define MAX 1001
int n, visited[MAX], e[MAX][MAX];
void dfs(int id)
{
  visited[id] = 1;
  for(int i = 1;i <= n;i++)
  {
    if(visited[i] == 0 && e[id][i] == 1)
      dfs(i);
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int m, k, c1, c2;
  scanf("%d%d%d", &n, &m, &k);
  memset(e, 0x3f, sizeof(e));
  for(int i = 0;i < m;i++)
  {
    scanf("%d%d", &c1, &c2);
    e[c1][c2] = e[c2][c1] = 1;
  }
  for(int i = 0;i < k;i++)
  {
    memset(visited, 0, sizeof(visited));
    scanf("%d", &c1);
    visited[c1] = 1;
    int cnt = 0;
    for(int j = 1;j <= n;j++)
    {
      if(visited[j] == 0)
      {
        dfs(j);
        cnt++;
      }
    }
    printf("%d\n", cnt-1);
  }
  return 0;
}
```
-FIN-
