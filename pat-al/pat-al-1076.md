1076.Forwards on Weibo (30)

pat-al-1076

2017-03-01

- bfs，用queue，对于每个数据要有visited和level的判断，所以开两个数组
- 利用vector来作为每行长短不等的二维数组，用来存放i和i的followers

```c++
/**
 * pat-al-1076
 * 2017-03-01
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#define MAX 1010
using namespace std;
vector<int> v[MAX];
int maxL;
void bfs(int root)
{
  queue<int> q;
  int tmp, level[MAX], cnt = 0, visited[MAX];
  memset(visited, -1, sizeof(visited));
  visited[root] = 1;
  level[root] = 0;
  q.push(root);
  while(!q.empty())
  {
    tmp = q.front();
    if(level[tmp] == maxL)
      break;
    q.pop();
    for(int i = 0;i < v[tmp].size();i++)
    {
      if(visited[v[tmp][i]] == -1)
      {
        visited[v[tmp][i]] = 1;
        level[v[tmp][i]] = level[tmp]+1;
        cnt++;
        q.push(v[tmp][i]);
        //printf("%d: %d\n", v[tmp][i], level[v[tmp][i]]);
      }
    }
  }
  printf("%d\n", cnt);
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m, tmp, k;
  scanf("%d%d", &n, &maxL);
  for(int i = 1;i <= n;i++)
  {
    scanf("%d", &m);
    for(int j = 0;j < m;j++)
    {
      scanf("%d", &tmp);
      v[tmp].push_back(i);
    }
  }
  scanf("%d", &k);
  for(int i = 0;i < k;i++)
  {
    scanf("%d", &tmp);
    bfs(tmp);
  }
  return 0;
}
```
-FIN-
