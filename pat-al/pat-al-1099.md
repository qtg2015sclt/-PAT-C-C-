1099.Build A Binary Search Tree (30)...to be continued...

pat-al-1099

2017-02-14

- 参考：[1099. Build A Binary Search Tree (30)-PAT甲级真题](http://www.liuchuo.net/archives/2173)

```c++
/**
 * pat-al-1099
 * 2017-02-14
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct NODE
{
  int key;
  int left;
  int right;
};
vector<NODE> node;
vector<int> input;
int order = 0;
void inOrder(int root)
{
  if(node[root].left == -1 && node[root].right == -1)
  {
    node[root].key = input[order++];
    return;
  }
  if(node[root].left != -1)
    inOrder(node[root].left);
  node[root].key = input[order++];
  if(node[root].right != -1)
    inOrder(node[root].right);
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  node.resize(n);
  input.resize(n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d%d", &node[i].left, &node[i].right);
  }
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &input[i]);
  }
  sort(input.begin(), input.end());
  inOrder(0);
  queue <int> q;
  q.push(0);
  printf("%d", node[0].key);
  while(!q.empty())
  {
    int tmp = q.front();
    q.pop();
    if(tmp != 0)
      printf(" %d", node[tmp].key);
    if(node[tmp].left != -1)
      q.push(node[tmp].left);
    if(node[tmp].right != -1)
      q.push(node[tmp].right);
  }
  putchar('\n');
  return 0;
}
```
-TBC-
