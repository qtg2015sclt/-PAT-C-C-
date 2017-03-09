1017.Queueing at Bank (25)...to be continued...

pat-al-1017

2017-02-16

- 坑见注释
- 参考：《算法笔记：上机训练实战指南》机械工业出版社

```c++
/**
 * pat-al-1017
 * 2017-02-16
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct CUS
{
  int comeTime;
  int serveTime;
}newCustomer;
int converTime(int h, int m, int s)
{
  return (h * 3600 + m * 60 + s);
}
bool cmp(CUS a, CUS b)
{
  return a.comeTime < b.comeTime;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, k, waitTime = 0;
  scanf("%d%d", &n, &k);
  vector<CUS> cus;
  int start = converTime(8, 0, 0);
  int end = converTime(17, 0, 0);
  int endTime[k];
  for(int i = 0;i < k;i++)
  {
    endTime[i] = start;
  }
  for(int i = 0;i < n;i++)
  {
    int hh, mm, ss, serveTime;
    scanf("%d:%d:%d %d", &hh, &mm, &ss, &serveTime);
    int comeTime = converTime(hh, mm, ss);
    if(comeTime > end)
      continue;
    newCustomer.comeTime = comeTime;
    newCustomer.serveTime = serveTime <= 60 ? serveTime*60 : 3600;//坑，别忘了把分钟转成秒
    cus.push_back(newCustomer);
  }
  sort(cus.begin(), cus.end(), cmp);
  for(int i = 0;i < cus.size();i++)
  {
    //printf("%d %d\n", cus[i].comeTime, cus[i].serveTime);
  }
  for(int i = 0;i < cus.size();i++)
  {
    int minWindow = 0, minEndTime = endTime[0];
    // for(int test = 0;test < k;test++)
    // {
    //   printf("endTime[%d] = %d\n", test, endTime[test]);
    // }
    for(int j = 1;j < k;j++)
    {
      if(endTime[j] < minEndTime)
      {
        minEndTime = endTime[j];
        minWindow = j;
      }
    }
    //printf("minWindow = %d, minEndTime = %d\n", minWindow, minEndTime);
    if(cus[i].comeTime >= minEndTime)//客户来得比窗口空闲的时间还晚
    {
      endTime[minWindow] = cus[i].comeTime + cus[i].serveTime;//坑，和需要等待的情况是不同的
    }
    else//客户需要等待空闲窗口
    {
      //printf("i = %d, comeTime = %d\n", i, cus[i].comeTime);
      waitTime += (minEndTime - cus[i].comeTime);
      endTime[minWindow] += cus[i].serveTime;
    }
    //printf("waitTime = %d\n", waitTime);
  }
  if(cus.size() == 0)
    printf("0.0\n");
  else
    printf("%.1lf\n", waitTime/60.0/cus.size());
  return 0;
}
```
-TBC-
