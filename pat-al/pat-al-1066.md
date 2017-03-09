1066.Root of AVL Tree (25)...to be continued...

pat-al-1066

2017-03-01

- AVL树，主要是搞清楚四种情况对应的调整方案，以及左旋和右旋的写法
- 坑见注释

```c++
/**
 * pat-al-1066
 * 2017-03-01
 * Cpp version
 * Author: fengLian_S
 */
#include<stdio.h>
#include<algorithm>
using namespace std;
struct NODE
{
  int key;
  int height;
  NODE* lchild;
  NODE* rchild;
}*root;
NODE* newNode(int num)
{
  NODE* root = new NODE;
  root->key = num;
  root->height = 1;
  root->lchild = NULL;
  root->rchild = NULL;
  return root;
}
int getHeight(NODE* root)//坑：必须要写，否则就会出现段错误（是因为root为空的情况）
{
  if(root == NULL)
    return 0;
  return root->height;
}
void updateHeight(NODE* &root)
{
  root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getBalanceFactor(NODE* root)
{
  return getHeight(root->lchild) - getHeight(root->rchild);
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
void R(NODE* &root)
{
  NODE* tmp = root->lchild;
  root->lchild = tmp->rchild;
  tmp->rchild = root;
  updateHeight(root);
  updateHeight(tmp);
  root = tmp;
}
void R(NODE* &root);
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
      if(getBalanceFactor(root->lchild) == 1)
      {
        R(root);
      }
      else if(getBalanceFactor(root->lchild) == -1)
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
      if(getBalanceFactor(root->rchild) == -1)
      {
        L(root);
      }
      else if(getBalanceFactor(root->rchild) == 1)
      {
        R(root->rchild);
        L(root);
      }
    }
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, num;
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &num);
    insert(root, num);
  }
  printf("%d\n", root->key);
  return 0;
}
```
-TBC-
