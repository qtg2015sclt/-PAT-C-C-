1064.Complete Binary Search Tree (30)...to be continue...

pat-al-1064

2017-02-14

- 参考：[1064. Complete Binary Search Tree (30)-PAT甲级真题](http://www.liuchuo.net/archives/2161)

```c++
/**
 * pat-al-1064
 * 2017-02-14
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#define min(a, b) ((a) < (b)?(a):(b))
using namespace std;
vector<int> input, level;
void getLevelOrder(int start, int end, int index)
{
  if(start > end)
    return;
  int n = end - start + 1;
  int l = log(n+1) / log(2);//求总共的层数
  int leaves = n - (pow(2, l)-1);
  int root = start + pow(2, l-1) - 1 + min(leaves, pow(2, l-1));//找到中序的根
  //printf("root = %d\n", root);
  level[index] = input[root];
  getLevelOrder(start, root-1, index*2+1);
  getLevelOrder(root+1, end, index*2+2);
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  input.resize(n);
  level.resize(n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &input[i]);
  }
  sort(input.begin(), input.end());//sort也可以这样用
  getLevelOrder(0, n-1, 0);
  printf("%d", level[0]);
  for(int i = 1;i < n;i++)
  {
    printf(" %d", level[i]);
  }
  putchar('\n');
}
```
-TBC-
