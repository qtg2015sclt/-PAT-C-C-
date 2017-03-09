1003.Emergency (25)

pat-al-1003

2017-02-01

- 本题使用的是dijkstra算法，应该还可以用dfs，等练习dfs的时候再用dfs做一遍
- 一句话解释dijkstra：每次找到距离「当前扩展点」最近的一个点，使用它来更新其他点的距离（其实就是更新它的邻接点）。
- 为什么INF取0x3f3f3f3f见：[为什么无穷大总是0x3f3f3f3f?](http://blog.csdn.net/hurmishine/article/details/51946015)
- 一个坑：如果使用e[n][n]+memset，就会出错，估计是内存分配问题

- 更新：原来是我对题目理解错了，题意是要找出一条路，（注意是“一”条路），此路最短且能召集最多的救援队。————————————————为什么是to be continue呢，因为虽然测试点都过了，但我还有一点困惑，代码中对总共能来多少救援队的更新是不是有问题？具体见附录。希望有人看到这能帮我解惑,那就太感谢啦。（已解决，并且删除了附录）
- 一点题外：dijkstra算法是属于动态规划还是贪心还是dfs。目前认为是动态规划而不是贪心（其实贪心我还不是太明白QAQ），（感觉有点像多段图呢），最优子结构：最终解包含了其子问题的求解，而且子问题确实是重复的。已经排除了dfs的可能（上面也写了这会是两种做法），因为每次用来扩展的点是找一个距离「当前扩展点」最近的那个，而不是每次走完一条路线。

```c
/**
 * pat-al-1003
 * 2017-01-30
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
```
-FIN-
