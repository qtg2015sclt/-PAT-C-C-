1089.Insert or Merge (25)...to be continued...

pat-al-1089

2017-02-24

- 乙级里面写过，优化了一下，原来还可以这样写
- 参考：《算法笔记：上机训练实战指南》机械工业出版社

```c++
/**
 * pat-al-1089
 * 2017-02-23
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#define MAX 110
using namespace std;
int n, input[MAX], tmpInput[MAX], changed[MAX];
bool isSame(int a[], int b[])
{
  for(int i = 0;i < n;i++)
  {
    if(a[i] != b[i])
      return false;
  }
  return true;
}
bool insertSort()
{
  //printf("hello\n");
  bool flag = false;
  for(int i = 1;i < n;i++)
  {
    if(i != 1 && isSame(tmpInput, changed))
      flag = true;
    int tmp = tmpInput[i], j = i;
    while(j > 0 && tmpInput[j-1] > tmp)
    {
      tmpInput[j] = tmpInput[j-1];
      j--;
    }
    tmpInput[j] = tmp;
    if(flag == true)
      return true;
  }
  return false;
}
void mergeSort()
{
  bool flag = false;
  for(int step = 2;step / 2 <= n;step *= 2)
  {
    if(step != 2 && isSame(tmpInput, changed))
    {
      flag = true;
    }
    for(int i = 0;i < n;i += step)
    {
      sort(tmpInput+i, tmpInput+min(i+step, n));
    }
    if(flag == true)
      return;
  }
}
void printArray(int a[])
{
  printf("%d", a[0]);
  for(int i = 1;i < n;i++)
  {
    printf(" %d", a[i]);
  }
  putchar('\n');
}
int main()
{
  freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  //printf("n = %d\n", n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &input[i]);
    tmpInput[i] = input[i];
  }
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &changed[i]);
    //printf("%d ", changed[i]);
  }
  //putchar('\n');
  if(insertSort())
  {
    printf("Insertion Sort\n");
    printArray(tmpInput);
  }
  else
  {
    printf("Merge Sort\n");
    for(int i = 0;i < n;i++)
    {
      tmpInput[i] = input[i];
    }
    mergeSort();
    printArray(tmpInput);
  }
  return 0;
}
```
-TBC-
