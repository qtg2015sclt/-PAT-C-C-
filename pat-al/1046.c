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
