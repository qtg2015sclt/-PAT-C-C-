/**
 * pat-bl-1032
 * 2017-01-21
 * C version
 */
#include<stdio.h>

int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int hs[n+1];//每个学校的编号作为下标，总分作为其存储内容
  for(int i = 0;i <= n;i++)//初始化
    hs[i] = 0;
  int tmpID, tmpScore;
  for(int i = 0;i < n;i++)
  {
    scanf("%d %d", &tmpID, &tmpScore);
    hs[tmpID] += tmpScore;//将分数累加至该学校的总分上
  }
  int maxID = 1, maxScore = hs[1];
  for(int i = 2;i <= n;i++)//遍历获得最高分
  {
    if(maxScore < hs[i])
    {
      maxScore = hs[i];
      maxID = i;
    }
  }
  printf("%d %d\n", maxID, maxScore);
}
