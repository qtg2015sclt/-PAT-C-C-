/**
 * pat-bl-1045
 * 2017-01-22
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>

int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int num[n], maxArr[n], max = 0;
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &num[i]);
    maxArr[i] = max;//maxArr保存当前数之前的数中最大的那个
    if(num[i] > max)//每个数都不相同，无需考虑等于号
      max = num[i];
  }
  // for(int i = 0;i < n;i++)
  //   printf("%d ", maxArr[i]);
  // putchar('\n');
  int min = 1000000001;//因为每个数不超过10^9
  int result[n], k = 0;
  // for(int i = 0;i < n;i++)
  //   printf("%d ", result[i]);
  // putchar('\n');
  for(int i = n-1;i >= 0;i--)
  {
    if(num[i] < min)//更新当前最小值
    {
      if(num[i] > maxArr[i])//如果比最小值还小，且比之前的所有数都大，说明可能是主元
        result[k++] = num[i];
      min = num[i];
    }
  }
  printf("%d\n", k);
  if(k != 0)//当没有找到可能的划分主元时不输出
    printf("%d", result[--k]);
  for(k = k-1;k >= 0;k--)
  {
    printf(" %d", result[k]);
  }
  putchar('\n');
}
