pat-bl-1030

2017-01-20

- 先排序，然后对每一个数作为序列的开始，来查找此情况下的最大序列
- 使用了归并排序和二分查找（因为乙级的考察点里有排序算法，所以不知道能不能用内置的排序算法），插入排序超时，换成归并就不超时了
- 注意读题：要求找到一个符合要求的最大序列，并不是把排好序的第一个数（整个数列的最小值）作为最小值来查找，而是每个数都应该作为最小值找一下
- 坑点：最后一个测试点过不了的话，把p改成double类型试一试

```c
/**
 * pat-bl-1030
 * 2017-01-20
 * C version
 */
#include<stdio.h>

int tmpArr[100002];
void Merge(int num[], int low, int mid, int high)
{
  int i, j, k;
  for(i = low;i <= high;i++)
  {
    tmpArr[i] = num[i];
  }
  i = low, j = mid+1, k = low;
  while(i <= mid && j <= high)
  {
    if(tmpArr[i] <= tmpArr[j])
      num[k++] = tmpArr[i++];
    else
      num[k++] = tmpArr[j++];
  }
  while(i <= mid)
    num[k++] = tmpArr[i++];
  while(j <= high)
    num[k++] = tmpArr[j++];
}
void MergeSort(int num[], int low, int high)
{
  if(low < high)
  {
    int mid = (low + high) / 2;
    MergeSort(num, low, mid);
    MergeSort(num, mid+1, high);
    Merge(num, low, mid, high);
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  double p;//大坑，说好的正整数呢，但是改成double最后一个测试点才能通过
  scanf("%d %lf", &n, &p);
  int num[n];
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &num[i]);
  }
  MergeSort(num, 0, n - 1);//归并排序O(nlogn)。一开始用的插入排序，超时了，改成归并就好了
  // for(int i = 0;i < n;i++)
  // {
  //   printf("%d ", num[i]);
  // }
  // putchar('\n');
  int min, result;
  int low, high, mid;
  for(int i = 0;i < n;i++)
  {
    min = num[i];
    low = i, high = n - 1;
    while(low <= high)//用二分法进行查找O(nlogn)
    {
      mid = (low + high) / 2;
      if(num[mid] <= min * p)
      {
        if(result < mid - i + 1)
          result = mid - i + 1;
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
  }
  }
  printf("%d\n", result);
}
```
-FIN-
