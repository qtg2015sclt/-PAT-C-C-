/**
 * pat-al-1012
 * 2017-02-16
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
using namespace std;
int hs[1000000];
struct STU
{
  int id;
  int score[4];//avg, c, m, e
  int rank[4];//avg, c, m, e
  int best;
}stu[2002];
int flag;
bool cmp(STU a, STU b)
{
  return a.score[flag] > b.score[flag];
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0;i < n;i++)
  {
    scanf("%d%d%d%d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
    stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3;
  }
  for(flag = 0;flag < 4;flag++)
  {
    sort(stu, stu+n, cmp);
    for(int j = 0;j < n;j++)
    {
      if(j > 0 && stu[j].score[flag] == stu[j-1].score[flag])
        stu[j].rank[flag] = stu[j-1].rank[flag];
      else
        stu[j].rank[flag] = j + 1;
    }
  }
  fill(hs, hs+1000000, -1);
  for(int i = 0;i < n;i++)
  {
    hs[stu[i].id] = i;
    int min = stu[i].rank[0];
    stu[i].best = 0;
    for(int j = 1;j < 4;j++)
    {
      if(stu[i].rank[j] < min)
      {
        min = stu[i].rank[j];
        stu[i].best = j;
      }
    }
  }
  char course[] = "ACME";
  for(int i = 0;i < m;i++)
  {
    int id, tmp;
    scanf("%d", &id);
    tmp = hs[id];
    if(tmp == -1)
    {
      printf("N/A\n");
    }
    else
    {
      int best = stu[tmp].best;
      printf("%d %c\n", stu[tmp].rank[best], course[best]);
    }
  }
  return 0;
}
