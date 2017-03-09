1086.Tree Traversals Again (25)...to be continued...

pat-al-1086

2017-02-1086

- 参考：《算法笔记：上机训练实战指南》机械工业出版社

```c++
/**
 * pat-al-1086
 * 2017-02-18
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#include<stack>
#define MAX 50
using namespace std;
int pre[MAX], in[MAX], post[MAX];
struct NODE
{
  int data;
  NODE* lchild;
  NODE* rchild;
};
NODE* create(int preL, int preR, int inL, int inR)
{
  if(preL > preR)
    return NULL;
  NODE* root = new NODE;
  root->data = pre[preL];
  int k;
  for(k = inL;k <= inR;k++)
  {
    if(in[k] == pre[preL])
      break;
  }
  int numLeft = k - inL;
  root->lchild = create(preL+1, preL+numLeft, inL, k-1);
  root->rchild = create(preL+numLeft+1, preR, k+1, inR);
  return root;
}
int flagFirst = 1;
void getPostOrder(NODE* root)
{
  if(root == NULL)
    return;
  if(root->lchild != NULL)
    getPostOrder(root->lchild);
  if(root->rchild != NULL)
    getPostOrder(root->rchild);
  if(flagFirst == 1)
  {
    printf("%d", root->data);
    flagFirst = 0;
  }
  else
    printf(" %d", root->data);
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  stack<int> st;
  int cntPre = 0, cntIn;
  for(int i = 0;i < 2*n;i++)//先把先序和中序提取出来
  {
    //printf("hello\n");
    char oper[10];
    scanf("%s", oper);
    //printf("oper = %s\n", oper);
    if(strcmp(oper, "Push") == 0)
    {
      //printf("hello, Push\n");
      scanf("%d", &pre[cntPre]);
      st.push(pre[cntPre++]);
    }
    else
    {
      in[cntIn++] = st.top();
      //printf("%d ", in[cntIn-1]);
      st.pop();
    }
  }
  NODE* root = create(0, n-1, 0, n-1);
  getPostOrder(root);
  putchar('\n');
  return 0;
}
```
-TBC-
