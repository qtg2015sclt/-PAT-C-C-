1123.Is It a Complete AVL Tree (30)

pat-al-1123

2017-03-07

- 是否是完全二叉树的判断：如果出现了一个空结点后又继续出现了非空结点，那么就不是完全二叉树了

```c++
/**
 * pat-al-1123
 * 2017-03-07
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<queue>
#define MAX 25
using namespace std;
struct NODE
{
  int key, height;
  NODE* lchild;
  NODE* rchild;
}*root;
int n;
int getHeight(NODE* root)
{
  if(root == NULL)
    return 0;
  else
    return root->height;
}
void updateHeight(NODE* &root)
{
  root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
NODE* newNode(int num)
{
  NODE* root = new NODE;
  root->key = num;
  root->lchild = NULL;
  root->rchild = NULL;
  root->height = 1;
  return root;
}
int getBalanceFactor(NODE* root)
{
  return getHeight(root->lchild) - getHeight(root->rchild);
}
void R(NODE* &root)
{
  NODE* tmp = root->lchild;
  root->lchild = tmp->rchild;
  tmp->rchild = root;
  updateHeight(root);
  updateHeight(tmp);
  root = tmp;
}
void L(NODE* &root)
{
  NODE* tmp = root->rchild;
  root->rchild = tmp->lchild;
  tmp->lchild = root;
  updateHeight(root);
  updateHeight(tmp);
  root = tmp;
}
void insert(NODE* &root, int num)
{
  if(root == NULL)
  {
    root = newNode(num);
    return;
  }
  if(num < root->key)
  {
    insert(root->lchild, num);
    updateHeight(root);
    if(getBalanceFactor(root) == 2)
    {
      if(getBalanceFactor(root->lchild) == 1)//LL
      {
        R(root);
      }
      else if(getBalanceFactor(root->lchild) == -1)//LR
      {
        L(root->lchild);
        R(root);
      }
    }
  }
  else
  {
    insert(root->rchild, num);
    updateHeight(root);
    if(getBalanceFactor(root) == -2)
    {
      if(getBalanceFactor(root->rchild) == -1)//RR
      {
        L(root);
      }
      else if(getBalanceFactor(root->rchild) == 1)//RL
      {
        R(root->rchild);
        L(root);
      }
    }
  }
}
void getLevelOrder(NODE* root)
{
  int notComplete = 0, nodeNull = 0;
  int flagFirst = 1;
  queue<NODE*> q;
  q.push(root);
  while(!q.empty())
  {
    if(flagFirst == 1)
      flagFirst = 0;
    else
      printf(" ");
    NODE* tmp = q.front();
    printf("%d", tmp->key);
    q.pop();
    if(tmp->lchild != NULL)
    {
      q.push(tmp->lchild);
      if(nodeNull == 1)
        notComplete = 1;
    }
    else
      nodeNull = 1;
    if(tmp->rchild != NULL)
    {
      q.push(tmp->rchild);
      if(nodeNull == 1)
        notComplete = 1;
    }
    else
      nodeNull = 1;
  }
  putchar('\n');
  if(notComplete == 1)
    printf("NO\n");
  else
    printf("YES\n");
}
int main()
{
  freopen("in.txt", "r", stdin);
  int tmp;
  scanf("%d", &n);
  if(n == 0)
    return 0;
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &tmp);
    insert(root, tmp);
  }
  getLevelOrder(root);
  return 0;
}
```
-FIN-
