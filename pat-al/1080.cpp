/**
 * pat-al-1080
 * 2017-02-22
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m, k;
struct STU
{
  int id;
  double ge;
  double gi;
  double finalGrade;
  int rank;
  int choice[5];
}stu[40010];
struct SCH
{
  int quota;
  int stuNum;//实际已招人数
  set<int> result;//存放已招收的学生id
  int lastRank;
}sch[105];
bool cmp(STU a, STU b)
{
  if(a.finalGrade != b.finalGrade)
    return a.finalGrade > b.finalGrade;
  else if(a.ge != b.ge)
    return a.ge > b.ge;
  else
    return a.id < b.id;
}
int main()
{
  freopen("in.txt", "r", stdin);
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0;i < m;i++)
  {
    scanf("%d", &sch[i].quota);
  }
  for(int i = 0;i < n;i++)
  {
    stu[i].id = i;
    scanf("%lf%lf", &stu[i].ge, &stu[i].gi);
    stu[i].finalGrade = (stu[i].ge + stu[i].gi) / 2;
    for(int j = 0;j < k;j++)
    {
      scanf("%d", &stu[i].choice[j]);
    }
  }
  sort(stu, stu+n, cmp);
  for(int i = 0;i < n;i++)
  {
    if(i > 0 && stu[i].finalGrade == stu[i-1].finalGrade && stu[i].ge == stu[i-1].ge)
      stu[i].rank = stu[i-1].rank;
    else
      stu[i].rank = i;
    //printf("id = %d, rank = %d, finalGrade = %lf, ge = %lf\n", stu[i].id, stu[i].rank, stu[i].finalGrade, stu[i].ge);
  }
  for(int i = 0;i < n;i++)
  {
    for(int j = 0;j < k;j++)
    {
      int choice = stu[i].choice[j];
      if(sch[choice].quota > sch[choice].stuNum)
      {
        sch[choice].stuNum++;
        sch[choice].lastRank = stu[i].rank;
        sch[choice].result.insert(stu[i].id);
        break;
      }
      if(sch[choice].quota <= sch[choice].stuNum && sch[choice].lastRank == stu[i].rank)
      {
        sch[choice].stuNum++;
        sch[choice].result.insert(stu[i].id);
        break;
      }
    }
  }
  for(int i = 0;i < m;i++)
  {
    if(sch[i].result.size() != 0)
    {
      set<int>::iterator it = sch[i].result.begin();
      cout << *it;
      for(it++;it != sch[i].result.end();it++)
        cout << " " << *it;
    }
    putchar('\n');
  }
  return 0;
}
