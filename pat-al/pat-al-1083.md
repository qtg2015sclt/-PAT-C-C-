1083.List Grades (25)

pat-al-1083

2017-02-22

- vector<STU> stu(n);不能用中括号写成：stu[n]
- sort搭配vector使用：sort(stu.begin(), stu.end(), cmp)

```c++
/**
 * pat-al-1083
 * 2017-02-22
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct STU
{
  char name[15];
  char id[15];
  int grade;
};
bool cmp(STU a, STU b)
{
  return a.grade > b.grade;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  vector<STU> stu(n);
  for(int i = 0;i < n;i++)
  {
    scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    //printf("%s %s %d\n", stu[i].name, stu[i].id, stu[i].grade);
  }
  sort(stu.begin(), stu.end(), cmp);
  int low, high, cnt = 0;
  scanf("%d%d", &low, &high);
  for(int i = 0;i < n;i++)
  {
    if(stu[i].grade >= low && stu[i].grade <= high)
    {
      printf("%s %s\n", stu[i].name, stu[i].id);
      cnt++;
    }
  }
  if(cnt == 0)
    printf("NONE\n");
  return 0;
}
```
-FIN-
