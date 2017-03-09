1043.Is It a Binary Search Tree (25)...to be continue...

- 参考：[1043. Is It a Binary Search Tree (25)-PAT甲级真题](http://www.liuchuo.net/archives/2153)

```c++
/**
 * pat-al-1043
 * 2017-02-13
 * Cpp version
 * Author: fengLian_s
 */
 #include<stdio.h>
 #include<vector>
 using namespace std;
 vector<int> pre;
 vector<int> post;
 int isMirror;
 void getPost(int root, int tail)
 {
   //printf("root = %d, tail = %d\n", root, tail);
  if(root > tail)
    return;
  int i = root+1, j = tail;
  if(!isMirror)
  {
    while(i <= tail && pre[i] < pre[root])
      i++;
    while(j > root && pre[j] >= pre[root])
      j--;
  }
  else
  {
    while(i <= tail && pre[i] >= pre[root])
      i++;
    while(j > root && pre[j] < pre[root])
      j--;
  }
  //printf("i = %d, j = %d\n", i, j);
  if(i - j != 1)
    return;
  //printf("i = %d, j = %d\n", i, j);
  getPost(root+1, j);
  getPost(i, tail);
  post.push_back(pre[root]);
 }
 int main()
 {
   freopen("in.txt", "r", stdin);
   int n;
   scanf("%d", &n);
   pre.resize(n);
   for(int i = 0;i < n;i++)
   {
     scanf("%d", &pre[i]);
   }
   getPost(0, n-1);
   if(post.size() != n)
   {
     post.clear();
     isMirror = 1;
     getPost(0, n-1);
   }
   if(post.size() == n)
   {
     printf("YES\n");
     printf("%d", post[0]);
     for(int i = 1;i < n;i++)
     {
       printf(" %d", post[i]);
     }
     putchar('\n');
   }
   else
    printf("NO\n");
 }
```
-TBC-
