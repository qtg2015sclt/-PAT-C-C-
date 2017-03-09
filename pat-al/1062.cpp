/**
 * pat-al-1062
 * 2017-03-01
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#include<vector>
#define MAX 100010
using namespace std;
struct STU
{
  int id;
  int virtue;
  int talent;
  int total;
  int state;//1是sage，2是nobleman，3是foolman，4是其他
}newStu;
bool cmp(STU a, STU b)
{
  if(a.state != b.state)
    return a.state < b.state;
  else
  {
    if(a.total != b.total)
      return a.total > b.total;
    else
    {
      if(a.virtue != b. virtue)
        return a.virtue > b.virtue;
      else
        return a.id < b.id;
    }
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, l, h;
  scanf("%d%d%d", &n, &l, &h);
  int id, virtue, talent, cnt = 0;
  vector<STU> stu;
  for(int i = 0;i < n;i++)
  {
    scanf("%d%d%d", &id, &virtue, & talent);
    if(virtue >= l && talent >= l)
    {
      cnt++;
      newStu.id = id;
      newStu.virtue = virtue;
      newStu.talent = talent;
      newStu.total = virtue + talent;
    }
    else
      continue;
    if(virtue >= h && talent >= h)
      newStu.state = 1;
    else if(virtue >=h && talent < h)
      newStu.state = 2;
    else if(virtue < h && talent < h && virtue >= talent)
      newStu.state = 3;
    else
      newStu.state = 4;
    stu.push_back(newStu);
    //printf("%08d %d\n", newStu.id, newStu.state);
  }
  sort(stu.begin(), stu.end(), cmp);
  // printf("%08d %d %d %d\n", stu[0].id, stu[0].virtue, stu[0].talent, stu[0].state);
  // for(int i = 1;i < cnt;i++)
  // {
  //   printf("%08d %d %d %d\n", stu[i].id, stu[i].virtue, stu[i].talent, stu[i].state);
  // }
  if(cnt != 0)
    printf("%d\n", cnt);
  else
  {
    printf("0\n");
    return 0;
  }
  printf("%08d %d %d\n", stu[0].id, stu[0].virtue, stu[0].talent);
  for(int i = 1;i < cnt;i++)
  {
    printf("%08d %d %d\n", stu[i].id, stu[i].virtue, stu[i].talent);
  }
  return 0;
}
