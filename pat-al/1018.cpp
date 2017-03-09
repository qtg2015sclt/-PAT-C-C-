/**
 * pat-al-1018
 * 2017-02-01
 * Cpp version
 * Author: fengLian_s
 */
#include<cstdio>
#include<vector>
#include<cstring>
#define MAX 501
#define INF 0x3f3f3f3f
using namespace std;
vector<int> pre[MAX];
vector<int> path, tmpPath;
int D_valueOfBike[MAX];
int minSend = INF, minBack = INF;
void dfs(int s)
{
  if(s == 0)
  {
    tmpPath.push_back(s);
    int send = 0, back = 0;
    for(int i = tmpPath.size()-1;i >= 0;i--)
    {
      int id = tmpPath[i];
      if(D_valueOfBike[id] > 0)
        back += D_valueOfBike[id];
      else
      {
        if(back > (0 - D_valueOfBike[id]))
          back += D_valueOfBike[id];
        else
        {
          send += (0 - D_valueOfBike[id] - back);
          back = 0;
        }
      }
    }
    if(send < minSend)
    {
      minSend = send;
      minBack = back;
      path = tmpPath;
    }
    else if(send == minSend && back < minBack)
    {
      minBack = back;
      path = tmpPath;
    }
    tmpPath.pop_back();
    return;
  }
  else//回溯法
  {
    tmpPath.push_back(s);
    for(int i = 0;i < pre[s].size();i++)
      dfs(pre[s][i]);
    tmpPath.pop_back();
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int maxC, n, s, m;
  int e[MAX][MAX], dist[MAX], visited[MAX];
  scanf("%d %d %d %d", &maxC, &n, &s, &m);
  for(int i = 1;i <= n;i++)
  {
    scanf("%d", &D_valueOfBike[i]);
    D_valueOfBike[i] -= maxC/2;
  }
  memset(e, 0x3f, sizeof(e));
  memset(dist, 0x3f, sizeof(dist));
  memset(visited, 0, sizeof(visited));
  for(int i = 0;i < m;i++)
  {
    int tmpS1, tmpS2, tmpTime;
    scanf("%d %d %d", &tmpS1, &tmpS2, &tmpTime);
    e[tmpS1][tmpS2] = tmpTime;
    e[tmpS2][tmpS1] = tmpTime;
  }
  //dijkstra:
  //printf("hello, dijkstra\n");
  dist[0] = 0;
  while(1)
  {
    int u, minD = INF;
    for(int i = 0;i <= n;i++)
    {
      if(visited[i] == 0 && dist[i] < minD)
      {
        minD = dist[i];
        u = i;
      }
    }
    visited[u] = 1;//别忘记写了
    if(minD == INF)
      break;
    for(int v = 0;v <= n;v++)
    {
      if(visited[v] == 0 && e[u][v] < INF)
      {
        //printf("e[%d][%d] = %d\n", u, v, e[u][v]);
        if(dist[v] > dist[u] + e[u][v])
        {
          dist[v] = dist[u] + e[u][v];
          pre[v].clear();
          pre[v].push_back(u);
        }
        else if(dist[v] == dist[u] + e[u][v])
        {
          pre[v].push_back(u);
        }
      }
    }
  }
  //dfs:
  dfs(s);
  //output:
  //test:
  // for(int i = 0;i < pre[s].size();i++)
  // {
  //   printf("%d\n", pre[s][i]);
  // }
  //test end
  printf("%d 0", minSend);
  for(int i = path.size()-2;i >= 0;i--)
  {
    printf("->%d", path[i]);
  }
  printf(" %d\n", minBack);
}
