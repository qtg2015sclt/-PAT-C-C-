1032.Sharing (25)

pat-al-1032

2017-02-09

- 第一次提交循环用while写的，有一个测试点超时了，后来改成for循环就好了，第一次应该是写的有问题
- 坑见注释

```c
/**
 * pat-al-1032
 * 2017-02-09
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
struct NODE
{
  char ch;
  int next;
  int flag;
}node[100001];
int main()
{
  freopen("in.txt", "r", stdin);
  int start1, start2, n;
  scanf("%d%d%d\n", &start1, &start2, &n);
  for(int i = 0;i < n;i++)
  {
    int tmp;
    scanf("%d ", &tmp);//注意，后面有空格哦
    scanf("%c %d", &node[tmp].ch, &node[tmp].next);
  }
  for(int i = start1;i != -1;i = node[i].next)
  {
    node[i].flag = 1;
  }
  for(int i = start2;i != -1;i = node[i].next)
  {
    if(node[i].flag == 1)
    {
      printf("%05d\n", i);
      return 0;
    }
  }
  printf("-1\n");
}
```
-FIN-
