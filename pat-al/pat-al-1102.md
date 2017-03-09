1102.Invert a Binary Tree (25)

pat-al-1102

2017-03-03

- 因为数据量就在10以内，所以读入可以用：scanf("%*c%c %c", &ch1, &ch2);
- 不用先翻转，直接把左右孩子调用顺序反过来就可以了

```c++
/**
 * pat-al-1102
 * 2017-03-03
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<queue>
using namespace std;
struct NODE
{
  int id;
  int lchild;
  int rchild;
}node[15];
int notRoot[15] = {0};
int getChild(char ch)
{
  if(ch == '-')
    return -1;
  else
  {
    notRoot[ch-'0'] = true;
    return ch - '0';
  }
}
void getLevelOrder(int root)
{
  queue<int> q;
  q.push(root);
  int flagFirst = 1;
  while(!q.empty())
  {
    if(flagFirst == 1)
      flagFirst = 0;
    else
      printf(" ");
    int tmp = q.front();
    printf("%d", tmp);
    q.pop();
    if(node[tmp].rchild != -1)
      q.push(node[tmp].rchild);
    if(node[tmp].lchild != -1)
      q.push(node[tmp].lchild);
  }
  putchar('\n');
}
int flagFirst = 1;
void getInOrder(int root)
{
  if(node[root].rchild != -1)
    getInOrder(node[root].rchild);
  if(flagFirst == 1)
    flagFirst = 0;
  else
    printf(" ");
  printf("%d", root);
  if(node[root].lchild != -1)
    getInOrder(node[root].lchild);
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  char ch1, ch2;
  for(int i = 0;i < n;i++)
  {
    scanf("%*c%c %c", &ch1, &ch2);
    node[i].lchild = getChild(ch1);
    node[i].rchild = getChild(ch2);
    //printf("%d %d\n", node[i].lchild, node[i].rchild);
  }
  //find root:
  int root;
  for(int i = 0;i < n;i++)
  {
    if(notRoot[i] == 0)
    {
      root = i;
      break;
    }
  }
  getLevelOrder(root);
  getInOrder(root);
  putchar('\n');
  return 0;
}
```
-FIN-
