/**
 * pat-al-1003
 * 2017-02-01
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#define INF 0x3f3f3f3f
#define MAX 501
int main()
{
  freopen("in.txt", "r", stdin);
  //input & initial:
  int n, m, c1, c2;
  int numOfTeam[MAX];
  int e[MAX][MAX];//边
  int dist[MAX], visited[MAX];
  memset(e, 0x3f, sizeof(e));//为什么是0x3f见相应的md文档
  memset(dist, 0x3f, sizeof(dist));
  memset(visited, 0, sizeof(visited));//0表示没有被访问过
  scanf("%d %d %d %d", &n, &m, &c1, &c2);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &numOfTeam[i]);
  }
  for(int i = 0;i < m;i++)
  {
    int tmpC1, tmpC2, tmpLen;
    scanf("%d %d %d", &tmpC1, &tmpC2, &tmpLen);
    e[tmpC1][tmpC2] = tmpLen;
    e[tmpC2][tmpC1] = tmpLen;
  }
  //dijkstra:
  int pathCnt[n], teams[n];
  teams[c1] = numOfTeam[c1];
  dist[c1] = 0;
  pathCnt[c1] = 1;
  while(1)
  {
    int u, minD = INF;
    for(int i = 0;i < n;i++)
    {
      if(visited[i] == 0 && dist[i] < minD)
      {
        //printf("i = %d, dist = %d\n", i, dist[i]);
        minD = dist[i];
        u = i;
      }
    }
    //printf("u = %d, minD = %d\n", u, minD);
    visited[u] = 1;
    if(u == c2 || minD == INF)
      break;
    for(int v = 0;v < n;v++)
    {
      if(visited[v] == 0 && e[u][v] < INF)
      {
        //printf("v = %d, e[%d][%d] = %d\n", v, u, v, e[u][v]);
        if(dist[u] + e[u][v] < dist[v])
        {
          dist[v] = dist[u] + e[u][v];
          pathCnt[v] = pathCnt[u];
          teams[v] = teams[u] + numOfTeam[v];
        }
        else if(dist[u] + e[u][v] == dist[v])
        {
          pathCnt[v] += pathCnt[u];
          if(teams[u] + numOfTeam[v] > teams[v])
            teams[v] = teams[u] + numOfTeam[v];
        }
      }
    }
  }
  //output:
  printf("%d %d\n", pathCnt[c2], teams[c2]);
}
