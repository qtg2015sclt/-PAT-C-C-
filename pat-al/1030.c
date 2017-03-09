/**
 * pat-al-1030
 * 2017-02-02
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#define MAX 501
#define INF 0x3f3f3f3f
int pre[MAX];
void printPath(int d)
{
  if(pre[d] != -1)
    printPath(pre[d]);
  printf("%d ", d);
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m, s, d;
  int e1[MAX][MAX], e2[MAX][MAX];
  int dist[MAX], cost[MAX], visited[MAX];
  memset(e1, 0x3f, sizeof(e1));
  memset(e2, 0x3f, sizeof(e2));
  memset(dist, 0x3f, sizeof(dist));
  memset(cost, 0x3f, sizeof(cost));
  memset(visited, 0, sizeof(visited));
  scanf("%d%d%d%d", &n, &m, &s, &d);
  for(int i = 0;i < m;i++)
  {
    int tmpC1, tmpC2, tmpDist, tmpCost;
    scanf("%d%d%d%d", &tmpC1, &tmpC2, &tmpDist, &tmpCost);
    e1[tmpC1][tmpC2] = e1[tmpC2][tmpC1] = tmpDist;
    e2[tmpC1][tmpC2] = e2[tmpC2][tmpC1] = tmpCost;
  }
  //dijkstra:
  dist[s] = 0, cost[s] = 0, pre[s] = -1;//起始点的前驱置为-1
  while(1)
  {
    int u, minD = INF;
    for(int i = 0;i < n;i++)
    {
      if(visited[i] == 0 && dist[i] < minD)
      {
        u = i;
        minD = dist[i];
      }
    }
    if(minD == INF)
      break;
    visited[u] = 1;
    for(int v = 0;v < n;v++)
    {
      if(visited[v] == 0 && e1[u][v] < INF)
      {
        if(dist[v] > dist[u] + e1[u][v])
        {
          dist[v] = dist[u] + e1[u][v];
          cost[v] = cost[u] + e2[u][v];
          pre[v] = u;
        }
        else if(dist[v] == dist[u] + e1[u][v] && cost[v] > cost[u] + e2[u][v])//注意，别忘了更新cost需要判断
        {
          cost[v] = cost[u] + e2[u][v];
          pre[v] = u;
        }
      }
    }
  }
  printPath(d);
  printf("%d %d\n", dist[d], cost[d]);
  return 0;
}
