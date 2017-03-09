1074.Reversing Linked List (25)

pat-al-1074

2017-03-01

- 乙级做过，再做一遍就很顺手了
- 不知道有没有无效节点，反正也很简单，就写了一些利用vector来存放有效节点
- 主要是用到reverse函数，这样写就很简单了
- reverse之后，在把后一个节点的地址赋给当前节点的next，别忘了把最后一个节点的next置位-1

```c++
/**
 * pat-al-1074
 * 2017-03-01
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 100010
using namespace std;
struct NODE
{
  int addr;
  int key;
  int next;
}node[MAX], newNode;
int main()
{
  freopen("in.txt", "r", stdin);
  int start, n, k, tmp;
  vector<NODE> v;
  scanf("%d%d%d", &start, &n, &k);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &tmp);
    node[tmp].addr = tmp;
    scanf("%d%d", &node[tmp].key, &node[tmp].next);
  }
  int index = start;
  while(index != -1)
  {
    newNode.addr = index;
    newNode.key = node[index].key;
    newNode.next = node[index].next;
    v.push_back(newNode);
    index = node[index].next;
  }
  for(int i = 0;i < v.size();i += k)
  {
    if(i + k - 1 < v.size())
      reverse(v.begin()+i, v.begin()+i+k);
  }
  for(int i = 0;i < v.size()-1;i++)
  {
    v[i].next = v[i+1].addr;
  }
  v[v.size()-1].next = -1;
  for(int i = 0;i < v.size();i++)
  {
    if(v[i].next != -1)
      printf("%05d %d %05d\n", v[i].addr, v[i].key, v[i].next);
    else
      printf("%05d %d -1\n", v[i].addr, v[i].key);
  }
  return 0;
}
```
-FIN-
