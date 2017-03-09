1072.Gas Station (30)

pat-al-1072

2017-02-02

- 本质是dijkstra算法，只是调用了多次，然后比较每次的结果，选出能给所有住宅区提供服务中距离住宅区最短距离最长的、平均距离最短的、序号最小的（有一个规则有点绕，要仔细读题）
- 坑：注意，计算平均距离和最短距离时只对住宅区进行计算，不算和其他备选站的距离；但是在算单源最短路径时要包含计算备选站，因为可以经过备选站来到住宅区
- 一个坑：我自己这是3.2，但是提交之后是「答案正确」，也就是说是3.3，所以不要去特意搞成四舍五入什么的

```c
/**
 * pat-al-1072
 * 2017-02-01
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 0x3f3f3f3f
#define MAX 1012
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m, k, d;
  int dist[MAX], e[MAX][MAX], visited[1012];
  scanf("%d%d%d%d", &n, &m, &k, &d);
  memset(e, 0x3f, sizeof(e));
  for(int i = 0;i < k;i++)
  {
    char tmpP1[6], tmpP2[6];
    int a, b, tmpDist;
    scanf("%s %s %d", tmpP1, tmpP2, &tmpDist);
    //printf("%s %s %d\n", tmpP1, tmpP2, tmpDist);
    if(tmpP1[0] == 'G')
      a = n + (int)atof(tmpP1+1);
    else
      a = (int)atof(tmpP1);
    if(tmpP2[0] == 'G')
      b = n + (int)atof(tmpP2+1);
    else
      b = (int)atof(tmpP2);
    e[a][b] = e[b][a] = tmpDist;
    //printf("a = %d, b = %d\n", a, b);
  }
  //solve:
  int resultID;
  double resultMaxDist = -1, resultAver;
  for(int i = n+1;i <= n+m;i++)
  {
    double minDist = INF, aver = 0;
    memset(dist, 0x3f, sizeof(dist));
    memset(visited, 0, sizeof(visited));
    dist[i] = 0;
    while(1)
    {
      int u, minD = INF;
      for(int j = 1;j <= n+m;j++)
      {
        if(visited[j] == 0 && dist[j] < minD)
        {
          minD = dist[j];
          u = j;
        }
      }
      visited[u] = 1;
      if(minD == INF)
        break;
      for(int j = 1;j <= n+m;j++)
      {
        if(visited[j] == 0 && dist[j] > dist[u] + e[u][j])
          dist[j] = dist[u] + e[u][j];
      }
    }
    for(int j = 1;j <= n;j++)//注意j的范围，因为是到每个住宅区的距离，所以最大是n
    {
      if(dist[j] > d)//超过了能服务的范围
      {
        minDist = -1;
        break;
      }
      if(dist[j] < minDist)
        minDist = dist[j];
      aver += dist[j] * 1.0;
    }
    if(minDist == -1)
      continue;
    aver = aver / n;
    //printf("aver = %.1lf\n", aver);
    if(minDist > resultMaxDist)//因为从序号小的先开始计算和保存结果，所以保证了最后留下来的一定是序号小的，因此不必特殊判断一下了
    {
      //printf("minDist = %.1lf, resultMaxDist = %.1lf\n", minDist, resultMaxDist);
      resultMaxDist = minDist;
      resultID = i;
      resultAver = aver;
    }
    else if(minDist == resultMaxDist && aver < resultAver)
    {
      resultID = i;
      resultAver = aver;
    }
  }
  if(resultMaxDist == -1)
    printf("No Solution\n");
  else
    printf("G%d\n%.1lf %.1lf\n", resultID-n, resultMaxDist, resultAver);
}
```
-FIN-
