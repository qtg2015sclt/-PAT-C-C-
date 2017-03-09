pat-bl-1025

2017-01-19

- 这题对我来说有点难……
- 首先存储一个点使用结构体，开了一个比较大的NODE数组，直接以数据的地址作为下标，然后转存到vector中
- 翻转是使用algorithm中的reverse函数，每k个翻转一下
- 最后，输出时将该节点的next重新设置成翻转过后下一个节点的地址
- 一个坑点：测试点中可能包含无效节点，使用遍历是为了筛除无效节点

```c
/**
 * pat-bl-1025
 * 2017-01-19
 * Cpp version
 */

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct NODE{
  int addr;
  int data;
  int next;
}node[100002];

 int main()
 {
   freopen("in.txt", "r", stdin);
   int addr;
   int n, k;
   scanf("%d %d %d", &addr, &n, &k);
   //printf("addr = %05d\n", addr);
   //struct NODE node[n+10];
   //input:
   for(int i = 0;i < n;i++)
   {
     struct NODE tmpNode;
     scanf("%d %d %d", &tmpNode.addr, &tmpNode.data, &tmpNode.next);
     //printf("%d: %05d %d %05d\n", i, tmpNode.addr, tmpNode.data, tmpNode.next);
     node[tmpNode.addr] = tmpNode;
   }
   //遍历:为了筛除无效节点
   vector<NODE> List;
   int cnt = 0;
   for(int i = 0, tmpAddr = addr;i < n && tmpAddr != -1;i++)
   {
     List.push_back(node[tmpAddr]);
     tmpAddr = node[tmpAddr].next;
     cnt++;
   }
   //翻转:
   for(unsigned int i = 0;i < List.size()/k;i++)
   {
     reverse(List.begin() + i*k, List.begin() + (i+1) * k);
   }
   //output:
   for(unsigned int i = 0;i < List.size();i++)
   {
     if(i == List.size() - 1)
     {
       printf("%05d %d -1\n", List[i].addr, List[i].data);
     }
     else
     {
       printf("%05d %d %05d\n", List[i].addr, List[i].data, List[i+1].addr);
     }
   }
 }
```
-FIN-
