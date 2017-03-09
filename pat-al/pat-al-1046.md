pat-al-1046

2017-01-27

- 作为一道20分的题，一开始想的有点复杂了，在发现直接暴力搜索是会超时之后，开了一个二维数组去从左到右从上到下求得每个节点之间正向和反向的距离，然后得到了段错误
- 在网上搜了一下：参考了这个[PAT 解题报告 1046. Shortest Distance (20)](http://www.sigmainfy.com/blog/pat-1046-shortest-distance.html)的思想，自己写了一下（实现不一样），然后就AC了
- 有点难理解的话还是在草稿纸上手工做一遍

```c
/**
 * pat-al-1046
 * 2017-01-27
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int dist[n+1];//dist[i]是节点i到1的距离
  dist[1] = 0;//1到自己的距离是0
  for(int i = 1;i < n;i++)
  {
    int tmp;
    scanf("%d", &tmp);
    dist[i+1] = dist[i] + tmp;
  }
  int sum;
  scanf("%d", &sum);//读入最后一个节点到1的距离
  sum += dist[n];//得到总和
  int m;
  scanf("%d", &m);
  for(int i = 0;i < m;i++)
  {
    int tmp1, tmp2;
    scanf("%d %d", &tmp1, &tmp2);
    if(tmp1 > tmp2)//让tmp1始终保持为较小的那一个数
    {
      int tmp = tmp1;
      tmp1 = tmp2;
      tmp2 = tmp;
    }
    int distance1 = dist[tmp2] - dist[tmp1];
    int distance2 = sum - distance1;
    if(distance1 < distance2)
      printf("%d\n", distance1);
    else
      printf("%d\n", distance2);
  }
}
```
-FIN-
