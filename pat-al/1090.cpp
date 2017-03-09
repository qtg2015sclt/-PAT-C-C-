/**
 * pat-al-1090
 * 2017-03-03
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#define MAX 100010
using namespace std;
vector<int> v[MAX];
int maxDepth = -1, cnt;
void dfs(int root, int depth)
{
  if(depth > maxDepth)
  {
    maxDepth = depth;
    cnt = 1;
  }
  else if(depth == maxDepth)
    cnt++;
  for(int i = 0;i < v[root].size();i++)
  {
    dfs(v[root][i], depth+1);
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  double p, r;
  scanf("%d%lf%lf", &n, &p, &r);
  int root;
  for(int i = 0;i < n;i++)
  {
    int father;
    scanf("%d", &father);
    if(father != -1)
      v[father].push_back(i);
    else
      root = i;
  }
  dfs(root, 0);
  for(int i = 0;i < maxDepth;i++)
  {
    p *= (1+r/100);
  }
  printf("%.2lf %d\n", p, cnt);
  return 0;
}
