1079.Total Sales of Supply Chain (25)

pat-al-1079

2017-03-01

- bfs
- 二维数组vector加队列和level数组实现

```c++
/**
 * pat-al-1079
 * 2017-03-01
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#include<queue>
#define MAX 100010
using namespace std;
vector<int> v[MAX];
double p, r;
int flagRetailer[MAX] = {0};
double interest[MAX] = {1};//每次都乘一遍来得到「原价的几倍」会导致一个测试点超时，所以用interest数组存储一下
void bfs(int root)
{
  int level[MAX], tmp;
  double price, sum = 0;
  queue<int> q;
  q.push(root);
  level[root] = 0;
  while(!q.empty())
  {
    tmp = q.front();
    q.pop();
    if(flagRetailer[tmp] == 1)
    {
      price = p * interest[level[tmp]];
      sum += (v[tmp][0]*price);
    }
    else
    {
      for(int i = 0;i < v[tmp].size();i++)
      {
        q.push(v[tmp][i]);
        level[v[tmp][i]] = level[tmp]+1;
        interest[level[v[tmp][i]]] = interest[level[tmp]]*(1+r/100);//每到新一层就求该层的「原价的倍数」，其实还能优化，你知道怎么改吗OwO
      }
    }
  }
  printf("%.1lf\n", sum);
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  int k, num;
  scanf("%d%lf%lf", &n, &p, &r);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &k);
    if(k == 0)
    {
      flagRetailer[i] = 1;
      scanf("%d", &num);
      v[i].push_back(num);
    }
    else
    {
      for(int j = 0;j < k;j++)
      {
        scanf("%d", &num);
        v[i].push_back(num);
      }
    }
  }
  bfs(0);
  return 0;
}
```
-FIN-
