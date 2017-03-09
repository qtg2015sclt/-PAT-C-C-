1075.PAT Judge (25)...to be continued...

pat-al-1075

2017-02-21

- 坑见注释
- 对结构体初始化

```c++
/**
 * pat-al-1075
 * 2017-02-21
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
struct STU
{
  int id;
  int totalScore;
  int score[6];
  int numOfPerfectly;
  bool passCompiler;
  int rank;
}stu[10010];
bool cmp(STU a, STU b)
{
  if(a.totalScore != b.totalScore)
    return a.totalScore > b.totalScore;
  else
  {
    if(a.numOfPerfectly != b.numOfPerfectly)
      return a.numOfPerfectly > b.numOfPerfectly;
    else
      return a.id < b.id;
  }
}
int n, k, m;
void init()
{
  for(int i = 1;i <=n;i++)
  {
    stu[i].id = i;
    stu[i].totalScore = 0;
    stu[i].numOfPerfectly = 0;
    stu[i].passCompiler = false;
    stu[i].rank = 0;
    memset(stu[i].score, -1, sizeof(stu[i].score));
  }
}
int main()
{
  int score[6];
  freopen("in.txt", "r", stdin);
  scanf("%d%d%d", &n, &k, &m);
  init();
  for(int i = 1;i <= k;i++)
  {
    scanf("%d", &score[i]);
  }
  for(int i = 0;i < m;i++)
  {
    int tmpId, tmpProblem, tmpScore;
    scanf("%d%d%d", &tmpId, &tmpProblem, &tmpScore);
    if(tmpScore != -1)//坑：四个if的顺序一定要注意
      stu[tmpId].passCompiler = true;
    if(tmpScore == -1 && stu[tmpId].score[tmpProblem] == -1)
      stu[tmpId].score[tmpProblem] = 0;
    if(tmpScore > stu[tmpId].score[tmpProblem] && tmpScore == score[tmpProblem])
      stu[tmpId].numOfPerfectly++;
    if(tmpScore > stu[tmpId].score[tmpProblem])
      stu[tmpId].score[tmpProblem] = tmpScore;
  }
  for(int i = 1;i <= n;i++)
  {
    for(int j = 1;j <= k;j++)
    {
      if(stu[i].score[j] != -1)
        stu[i].totalScore += stu[i].score[j];
      //printf("i = %d, totalScore = %d\n", i, stu[i].totalScore);
    }
    //printf("%d: %d\n", stu[i].id, stu[i].numOfPerfectly);
  }
  sort(stu+1, stu+n+1, cmp);
  for(int i = 1;i <= n;i++)
  {
    if(i != 1 && stu[i].totalScore == stu[i-1].totalScore)
      stu[i].rank = stu[i-1].rank;
    else
      stu[i].rank = i;
    if(stu[i].passCompiler == true)
    {
      printf("%d %05d %d", stu[i].rank, stu[i].id, stu[i].totalScore);
      for(int j = 1;j <= k;j++)
      {
        if(stu[i].score[j] == -1)
          printf(" -");
        else
          printf(" %d", stu[i].score[j]);
      }
      putchar('\n');
    }
  }
  return 0;
}
```
-TBC-
