1097.Deduplication on a Linked List (25)

pat-al-1097

2017-03-03

- 使用order来记录是第几个结点，一个巧妙的方式分开了需要保留下来的结点和需要摘除的结点

```c++
/**
 * pat-al-1097
 * 2017-03-03
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#define MAX 100010
using namespace std;
struct NODE
{
  int addr;
  int key;
  int next;
  int order;
}node[MAX];
bool cmp(NODE a, NODE b)
{
  return a.order < b.order;
}
int isExist[MAX] = {0};
int main()
{
  freopen("in.txt", "r", stdin);
  int start, n;
  scanf("%d%d", &start, &n);
  for(int i = 0;i < MAX;i++)
  {
    node[i].order = 2*MAX;
  }
  for(int i = 0;i < n;i++)
  {
    int address;
    scanf("%d", &address);
    scanf("%d %d", &node[address].key, &node[address].next);
    node[address].addr = address;
    //printf("%05d %d %05d %d\n", node[address].addr, node[address].key, node[address].next, node[address].order);
  }
  int index = start, orderResult = 0, orderRemove = 0;
  while(index != -1)
  {
    if(isExist[abs(node[index].key)] == 0)
    {
      isExist[abs(node[index].key)] = 1;
      node[index].order = orderResult++;
    }
    else
      node[index].order = MAX + orderRemove++;
    //printf("%05d %d %05d %d\n", node[index].addr, node[index].key, node[index].next, node[index].order);
    index = node[index].next;
  }
  sort(node, node+MAX, cmp);
  int cnt = orderResult+orderRemove;
  for(int i = 0;i < cnt;i++)
  {
    //printf("%05d %d %05d %d\n", node[i].addr, node[i].key, node[i].next, node[i].order);
    if(i != orderResult-1 && i != cnt-1)
      printf("%05d %d %05d\n", node[i].addr, node[i].key, node[i+1].addr);
    else
      printf("%05d %d -1\n", node[i].addr, node[i].key);
  }
  return 0;
}
```
-FIN-
