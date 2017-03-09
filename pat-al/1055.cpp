/**
 * pat-al-1055
 * 2017-02-08
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct WLTH
{
  char name[10];
  int age;
  int worth;
}wlth[100002];
bool cmp(WLTH a, WLTH b)//按财富非升序排序，财富相同按年龄非降序排序，前两者都相同，按姓名非降序排序
{
  if(a.worth != b.worth)
    return a.worth > b.worth;
  else
  {
    if(a.age != b.age)
      return a.age < b.age;
    else
      return strcmp(a.name, b.name) < 0;
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0;i < n;i++)
  {
    scanf("%s%d%d", wlth[i].name, &wlth[i].age, &wlth[i].worth);
  }
  sort(wlth, wlth+n, cmp);
  // for(int i = 0;i < n;i++)
  // {
  //   printf("%s %d %d\n", wlth[i].name, wlth[i].age, wlth[i].worth);
  // }
  for(int i = 0;i < k;i++)
  {
    int m, amin, amax;
    scanf("%d%d%d", &m, &amin, &amax);
    printf("Case #%d:\n", i+1);
    int cnt = 0;
    for(int j = 0;j < n;j++)
    {
      if(wlth[j].age >= amin && wlth[j].age <= amax)
      {
        printf("%s %d %d\n", wlth[j].name, wlth[j].age, wlth[j].worth);
        cnt++;
      }
      if(cnt == m)
        break;
    }
    if(cnt == 0)
      printf("None\n");
  }
  return 0;
}
