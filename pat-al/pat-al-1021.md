1021.Deepest Root (25)

pat-al-1021

2017-02-04

- 考点：深搜dfs
- 关于连通分量的计算：从任一点出发开始深搜，结束一次搜索后如果还有点没被访问到（即，可以进行多次搜索）说明连通分量不止一个，能进行几次搜索就有几个连通分量
- 关于题目要求的找最长的路径的起始点，参考了：[1021. Deepest Root (25)-PAT甲级真题](http://www.liuchuo.net/archives/2348)。个人理解：第一次出发开始搜索（不管起始点是哪个节点）所找到的「当前」最长路径的终点（们），一定是「整个图」最长路径的的起始点，所以再以此为起始点去深搜，找到的「当前」最长路径的终点，也一定是要找的「整个图」最长路径的起始点（因为这是无向图嘛，起点亦是终点，终点亦是起点）。把这些点保存下来，就是要求的节点。还不能理解就自己在草稿纸上画一画。
- 不能用数组来存储边了，会内存超限，要改用vector
- 关于vector作为二维数组使用：要么声明时就声明为vector< vector< int> > e，搭配e.resize(n)来使用；要么声明时就给定大小vector< int> e[101]，也可作为二维数组用。如果声明时是一维的，又没给定大小，就不能作为二维数组用。
- 使用set是因为set能按从小到大的顺序去保存放进去的数，不用自己排序了
- 练习了一下迭代器iterator的使用

```c++
/**
 * pat-al-1021
 * 2017-02-03
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#define MAX 10001
#define INF 0x3f3f3f3f
using namespace std;
int n, visited[MAX];
vector<vector<int> > e;
int maxDepth = -1;
vector<int> v;
set<int> s;
void dfs(int id, int depth)
{
  visited[id] = 1;
  if(depth > maxDepth)
  {
    maxDepth = depth;
    v.clear();
    v.push_back(id);
  }
  else if(depth == maxDepth)
  {
    v.push_back(id);
  }
  for(int i = 0;i < e[id].size();i++)
  {
    if(visited[e[id][i]] == 0)
      dfs(e[id][i], depth+1);
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  e.resize(n+1);
  for(int i = 1;i < n;i++)
  {
    int node1, node2;
    scanf("%d%d", &node1, &node2);
    e[node1].push_back(node2);
    e[node2].push_back(node1);
  }
  int cnt = 0, s1;
  fill(visited, visited+MAX, 0);
  for(int i = 1;i <= n;i++)
  {
    if(visited[i] == 0)
    {
      dfs(i, 0);
      //printf("i = %d\n", i);
      cnt++;
      if(i == 1)
      {
        for(int j = 0;j < v.size();j++)
        {
          s.insert(v[j]);
          if(j == 0)
            s1 = v[j];
        }
      }
    }
  }
  if(cnt > 1)
    printf("Error: %d components\n", cnt);
  else
  {
    v.clear();
    fill(visited, visited+MAX, 0);
    dfs(s1, 0);
    for(int i = 0;i < v.size();i++)
      s.insert(v[i]);
    for(set<int>::iterator it = s.begin();it != s.end();it++)
      printf("%d\n", *it);
  }
  return 0;
}
```
-FIN-
