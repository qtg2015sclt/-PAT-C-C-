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
