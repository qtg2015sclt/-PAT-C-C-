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
