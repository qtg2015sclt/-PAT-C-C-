1103.Integer Factorization (30)...to be continued...

pat-al-1103

2017-03-02

- dfs
- 要记录的数据有点多，要细心

```c++
/**
 * pat-al-1103
 * 2017-03-02
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> fac, ans, tmp;
int power(int x)
{
  int ans = 1;
  for(int i = 0;i < p;i++)
  {
    ans *= x;
  }
  return ans;
}
void init()
{
  int i = 0, tmp = 0;
  while(tmp <= n)
  {
    fac.push_back(tmp);
    tmp = power(++i);
  }
}
void dfs(int index, int nowK, int sum, int facSum)
{
  if(nowK == k && sum == n)
  {
    if(facSum > maxFacSum)
    {
      ans = tmp;
      maxFacSum = facSum;
    }
    return;
  }
  if(nowK > k || sum > n)
    return;
  if(index > 0)
  {
    tmp.push_back(index);
    dfs(index, nowK+1, sum+fac[index], facSum+index);
    tmp.pop_back();
    dfs(index-1, nowK, sum, facSum);
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  scanf("%d%d%d", &n, &k, &p);
  init();
  dfs(fac.size()-1, 0, 0, 0);
  if(maxFacSum == -1)
    printf("Impossible");
  else
  {
    printf("%d = %d^%d", n, ans[0], p);
    for(int i = 1;i < ans.size();i++)
      printf(" + %d^%d", ans[i], p);
  }
  putchar('\n');
  return 0;
}
```
-TBC-
