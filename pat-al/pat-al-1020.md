1020.Tree Traversals (25)...to be continued...

pat-al-1020

2017-02-20

- NODE* root = new NODE;
- 参考：《算法笔记：上机训练实战指南》机械工业出版社

```c++
/**
 * pat-al-1020
 * 2017-02-18
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<queue>
#define MAX 50
using namespace std;
int post[MAX], in[MAX];
struct NODE
{
  int data;
  NODE* lchild;
  NODE* rchild;
};
NODE* create(int postL, int postR, int inL, int inR)
{
  if(postL > postR)
    return NULL;
  NODE* root = new NODE;
  root->data = post[postR];
  int k;
  for(k = inL;k<= inR;k++)
  {
    if(in[k] == post[postR])
      break;
  }
  int numLeft = k - inL;//左子树的结点个数
  root->lchild = create(postL, postL+numLeft-1, inL, k-1);
  root->rchild = create(postL+numLeft, postR-1, k+1, inR);
  return root;
}
void BFS(NODE* root)
{
  int flagFirst = 1;
  queue<NODE*> q;
  q.push(root);
  while(!q.empty())
  {
    NODE* tmp = q.front();
    q.pop();
    if(flagFirst == 1)
    {
      printf("%d", tmp->data);
      flagFirst = 0;
    }
    else
      printf(" %d", tmp->data);
    if(tmp->lchild != NULL)
      q.push(tmp->lchild);
    if(tmp->rchild != NULL)
      q.push(tmp->rchild);
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  //printf("n = %d\n", n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &post[i]);
  }
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &in[i]);
  }
  NODE* root = create(0, n-1, 0, n-1);
  BFS(root);
  putchar('\n');
  return 0;
}
```
-TBC-
