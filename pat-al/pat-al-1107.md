1107.Social Clusters (30)...to be continued...

pat-al-1107

2017-03-03

- 并查集
- 重点是findFather和Union两个函数，findFather中的路径压缩要不要写视情况

```c++
/**
 * pat-al-1107
 * 2017-03-02
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#define N 1010
using namespace std;
int father[N];
int isRoot[N];
int course[N] = {0};
int findFather(int a)
{
  int x = a;
  while(x != father[x])
    x = father[x];
  //路径压缩
  while(a != father[a])
  {
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}
void Union(int a, int b)
{
  int faA = findFather(a);
  int faB = findFather(b);
  if(faA != faB)
    father[faA] = faB;
}
void init(int n)
{
  for(int i = 1;i <= n;i++)
  {
    father[i] = i;
    isRoot[i] = false;
  }
}
bool cmp(int a, int b)
{
  return a > b;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, k, h;
  scanf("%d", &n);
  init(n);
  for(int i = 1;i <= n;i++)
  {
    scanf("%d:", &k);
    for(int j = 0;j < k;j++)
    {
      scanf("%d", &h);
      if(course[h] == 0)
        course[h] = i;
      Union(i, findFather(course[h]));
    }
  }
  for(int i = 1;i <= n;i++)
  {
    isRoot[findFather(i)]++;
  }
  int cnt = 0;
  for(int i = 1;i <= n;i++)
  {
    if(isRoot[i] != 0)
      cnt++;
  }
  sort(isRoot+1, isRoot+n+1, cmp);
  printf("%d\n%d", cnt, isRoot[1]);
  for(int i = 2;i <= cnt;i++)
  {
    printf(" %d", isRoot[i]);
  }
  putchar('\n');
  return 0;
}
```
-TBC-
