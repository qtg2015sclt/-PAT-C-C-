1014.Waiting in Line (30)...to be continued...

pat-al-2014

2017-02-16

- 参考：[1014. Waiting in Line (30)-PAT甲级真题](http://www.liuchuo.net/archives/2943)
- 一个问题：代码的67行左右有一句：window[minWindow].q.push(T[index]);在上述参考的博客中写的是window[tempwindow].q.push(tempmin);虽然都能AC，但个人认为是有区别的，所以，到底是等价的还是有一个人写错了只是测试点没测出来啊？

```c++
/**
 * pat-al-2014
 * 2017-02-16
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<queue>
using namespace std;
struct NODE
{
  int popTime;
  int endTime;
  queue<int> q;
};
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m, k, q, index = 1;
  scanf("%d%d%d%d", &n, &m, &k, &q);
  int T[k];
  for(int i = 1;i <= k;i++)
    scanf("%d", &T[i]);
  vector<NODE> window(n+1);
  vector<int> result(k+1);
  vector<bool> sorry(k+1, false);//一个新尝试
  for(int i = 1;i <= m;i++)//初始化，先把n*m的位置填满
  {
    for(int j = 1;j <= n;j++)
    {
      if(index <= k)
      {
        window[j].q.push(T[index]);
        if(i == 1)
          window[j].popTime = T[index];
        if(window[j].endTime >= 540)
          sorry[index] = true;
        window[j].endTime += T[index];
        result[index] = window[j].endTime;
      }
      index++;
    }
  }
  while(index <= k)//如果存在排在m*n之后的人，按照题意排队
  {
    int minTime = window[1].popTime, minWindow = 1;
    for(int i = 2;i <= n;i++)
    {
      if(window[i].popTime < minTime)
      {
        minWindow = i;
        minTime = window[i].popTime;
      }
    }
    window[minWindow].q.pop();
    window[minWindow].q.push(T[index]);
    printf("T[index] = %d\n", T[index]);
    window[minWindow].popTime += window[minWindow].q.front();
    if(window[minWindow].endTime >= 540)
      sorry[index] = true;
    window[minWindow].endTime += T[index];
    result[index] = window[minWindow].endTime;
    index++;
  }
  for(int i = 0;i < q;i++)
  {
    int request;
    scanf("%d", &request);
    if(sorry[request] == true)
      printf("Sorry\n");
    else
      printf("%02d:%02d\n", (result[request]+480)/60, (result[request]+480)%60);
  }
  return 0;
}
```
-TBC
