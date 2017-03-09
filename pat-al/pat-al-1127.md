1127.ZigZagging on a Tree (30)

pat-al-1127

2017-03-04

- 今天考试把这题想错了……就得了1分……
- 写的有点麻烦，先按照层次遍历全部输出到数组，同时记录每层有多少个结点，输出的时候根据当前是奇数层还是偶数层来决定顺序还是逆序输出（由于保存了每层有多少个，可以把输出的下标范围限制住）

```c++
/**
 * pat-al-1127
 * 2017-03-04
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<queue>
#define MAX 35
using namespace std;
struct NODE
{
  int key;
  NODE* lchild;
  NODE* rchild;
};
int in[MAX], post[MAX];
int n;
NODE* create(int inL, int inR, int postL, int postR)
{
  if(postL > postR)
    return NULL;
  NODE *root = new NODE;
  root->key = post[postR];
  int k;
  for(k = inL;k < inR;k++)
  {
    if(in[k] == post[postR])
      break;
  }
  int len = k - inL;
  root->lchild = create(inL, k-1, postL, postL+len-1);
  root->rchild = create(k+1, inR, postL+len, postR-1);
  return root;
}
int num[MAX], level[MAX], numOfThisLevel[MAX] = {1, 1}, nowLevel;
void bfs(NODE* root)
{
  int front = 0, tail = 0;
  queue<NODE*> q;
  q.push(root);
  level[0] = 1;
  while(!q.empty())
  {
    NODE *tmp = new NODE;
    tmp = q.front();
    num[front] = tmp->key;
    nowLevel = level[front++]+1;
    q.pop();
    if(tmp->lchild != NULL)
    {
      q.push(tmp->lchild);
      level[++tail] = nowLevel;
      numOfThisLevel[nowLevel]++;
    }
    if(tmp->rchild != NULL)
    {
      q.push(tmp->rchild);
      level[++tail] = nowLevel;
      numOfThisLevel[nowLevel]++;
    }
  }
}
void print()
{
  int index = 0, l = 1, flagFirst = 1;
  while(l <= nowLevel && index < n)
  {
    if(l % 2 == 0)//从左到右
    {
      //printf("l = %d\n", l);
      for(int start = index;start < index + numOfThisLevel[l];start++)
      {
        //printf("start = %d\n", start);
        if(flagFirst == 1)
          flagFirst = 0;
        else
          printf(" ");
        printf("%d", num[start]);
      }
      index += numOfThisLevel[l];
    }
    else
    {
      //printf("l = %d\n", l);
      for(int start = index + numOfThisLevel[l] - 1;start >= index;start--)
      {
        //printf("start = %d: ", start);
        if(flagFirst == 1)
          flagFirst = 0;
        else
          printf(" ");
        printf("%d", num[start]);
      }
      index += numOfThisLevel[l];
    }
    l++;
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &in[i]);
  }
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &post[i]);
  }
  NODE* root = create(0, n-1, 0, n-1);
  bfs(root);
  // for(int i = 0;i < n;i++)
  // {
  //   printf("%d ", num[i]);
  // }
  // for(int l = 1;l < nowLevel;l++)
  // {
  //   printf("level%d: %d\n", l, numOfThisLevel[l]);
  // }
  print();
}
```
-FIN-
