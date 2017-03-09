pat-bl-1035

2017-01-21

- 考查的是归并排序和插入排序，比较难了，如果不会写排序，先把几种排序分别写写好、写到熟练再做这题
- 注意归并不能用分治的递归写，要按非递归使用步长的那种来写
- 没有什么坑（比如，一趟排序做完后没有变化就不算能这一趟必须再做一遍这种），但是写了很久
- 三个测试点是插入，另外的是递归，来不及可以先写自己熟练的

```c
/**
 * pat-bl-1035
 * 2017-01-21
 * C version
 * Author:fengLian_s
 */
#include<stdio.h>
int tmpArr[102], target[102];
int isInsertionSort(int num[], int size)
{
  // for(int k = 0;k < size;k++)
  //   printf("%d ", num[k]);
  // putchar('\n');
  int i, j, tmp;
  int flagEqual;
  for(i = 1;i < size;i++)
  {
    flagEqual = 1;//默认相等
    tmp = num[i];
    j = i;
    while(j && num[j-1] > tmp)
    {
      num[j] = num[j-1];
      j--;
    }
    num[j] = tmp;
    // for(int k = 0;k < size;k++)
    //   printf("%d ", num[k]);
    // putchar('\n');
    //一次排序结束，进行比较：
    for(int k = 0;k < size;k++)
    {
      if(num[k] != target[k])//遇到有不相等的，结束比较，直接继续下一次排序
      {
        flagEqual = 0;
        //printf("not equal\n");
        break;
      }
    }
    if(flagEqual)//两个序列相等，再迭代一轮并输出结果
    {
      //printf("is equal\n");
      i++;
      tmp = num[i];
      j = i;
      while(j && num[j-1] > tmp)
      {
        num[j] = num[j-1];
        j--;
      }
      num[j] = tmp;
      printf("Insertion Sort\n");
      printf("%d", num[0]);
      for(int k = 1;k < size;k++)
        printf(" %d", num[k]);
      putchar('\n');
      return 1;
    }
    else
      continue;
  }
  return 0;
}
int isMergeSort(int num[], int size)
{
  int flagEqual;
  for(int h = 1;h < size;h *= 2)//h是步长
  {
    flagEqual = 1;//默认相等
    for(int i = 0;i < size - h;i += h*2)//本次合并次数
    {
      //printf("merge:%d - %d\n", i, i + h*2 - 1);
      int low = i, high = i + h*2 - 1;
      if(high >= size)
        high = size - 1;
      if(low < high)
      {
        int mid = low + h -1;
        for(int j = low;j <= high;j++)
          tmpArr[j] = num[j];
        int p = low, q = mid+1, k = low;
        while(p <= mid && q <= high)
        {
          if(tmpArr[p] <= tmpArr[q])
            num[k++] = tmpArr[p++];
          else
            num[k++] = tmpArr[q++];
        }
        while(p <= mid)
          num[k++] = tmpArr[p++];
        while(q <= high)
          num[k++] = tmpArr[q++];
      }
    }
    // printf("%d", num[0]);
    // for(int k = 1;k < size;k++)
    //   printf(" %d", num[k]);
    // putchar('\n');
    //一次合并完毕，开始比较：
    for(int k = 0;k < size;k++)
    {
      if(num[k] != target[k])//遇到有不相等的，结束比较，直接继续下一次排序
      {
        flagEqual = 0;
        //printf("not equal\n");
        break;
      }
    }
    if(flagEqual)//两个序列相等，再迭代一次
    {
      h *= 2;
      for(int i = 0;i < size - h;i += h*2)//本次合并次数
      {
        //printf("merge:%d - %d\n", i, i + h*2 - 1);
        int low = i, high = i + h*2 - 1;
        if(high >= size)
          high = size - 1;
        if(low < high)
        {
          int mid = low + h -1;
          for(int j = low;j <= high;j++)
            tmpArr[j] = num[j];
          int p = low, q = mid+1, k = low;
          while(p <= mid && q <= high)
          {
            if(tmpArr[p] <= tmpArr[q])
              num[k++] = tmpArr[p++];
            else
              num[k++] = tmpArr[q++];
          }
          while(p <= mid)
            num[k++] = tmpArr[p++];
          while(q <= high)
            num[k++] = tmpArr[q++];
        }
      }
      printf("Merge Sort\n");
      printf("%d", num[0]);
      for(int k = 1;k < size;k++)
        printf(" %d", num[k]);
      putchar('\n');
      return 1;
    }
    else
      continue;
  }
  return 0;
}
int main()
{
  freopen("in.txt", "r", stdin);
  //input:
  int n;
  scanf("%d", &n);
  int input1[102], input2[102];//两个数组，分别用来计算插入和归并
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &input1[i]);
    input2[i] = input1[i];
  }
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &target[i]);
  }
  // for(int i = 0;i < n;i++)
  // {
  //   printf("%d ", input2[i]);
  // }
  // putchar('\n');
  //compute
  if(isInsertionSort(input1, n) == 0)
  {
    isMergeSort(input2, n);
  }
}
```
-FIN-
