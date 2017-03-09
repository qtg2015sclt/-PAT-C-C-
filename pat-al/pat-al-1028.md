1028.List Sorting (25)

pat-al-1028

2017-02-05

- 有测试点运行超时但觉得没什么问题的时候可以尝试把cin和cout换成scanf和printf
- char字符串数组比较必须用strcmp函数，而不能像string类型可以直接比较
- 坑见注释

```c++
/**
 * pat-al-1028
 * 2017-02-05
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>//坑：strcmp在<string.h>中，不是在<string>中
#define MAX 100001
using namespace std;
int c;
struct STU
{
  int id;
  char name[10];
  int score;
}stu[MAX];
bool cmp(STU a, STU b)
{
  if(c == 1)
    return a.id < b.id;
  else if(c == 2)
  {
    if(strcmp(a.name, b.name) != 0)
      return strcmp(a.name, b.name) < 0;//因为不能用string类型，只能用char字符数组，所以只能用strcmp来比较
    else
      return a.id < b.id;
  }
  else
  {
    if(a.score != b.score)
      return a.score < b.score;
    else
      return a.id < b.id;
  }
}
int main()
{
  int n;
  cin >> n >> c;
  for(int i = 0;i < n;i++)
  {
    scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].score);//不能用下面注释掉的那行，会运行超时
    //cin >> stu[i].id >> stu[i].name >> stu[i].score;
    //cout << stu[i].id << stu[i].name << stu[i].score << endl;
  }
  sort(stu, stu+n, cmp);
  for(int i = 0;i < n;i++)
  {
    printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
  }
  return 0;
}
```
-FIN-
