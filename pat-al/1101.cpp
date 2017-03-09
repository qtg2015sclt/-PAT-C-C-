/**
 * pat-al-1101
 * 2017-03-02
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#define MAX 100010
int main()
{
  freopen("in.txt", "r", stdin);
  int n, num[MAX], flagPartition[MAX] = {0}, maxNow[MAX];//maxNow其实可以不用数组
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &num[i]);
    if(i > 0 && maxNow[i-1] < num[i])
    {
      maxNow[i] = num[i];
      flagPartition[i] = 1;
    }
    else if(i == 0)
    {
      maxNow[i] = num[i];
      flagPartition[i] = 1;
    }
    else
      maxNow[i] = maxNow[i-1];
  }
  int minNow;
  for(int i = n-1;i >= 0;i--)
  {
    if(i == n-1)
      minNow = num[i];
    else if(i < n-1 && minNow > num[i])
    {
      minNow = num[i];
    }
    else
    {
      flagPartition[i] = 0;
    }
  }
  int cnt = 0;
  for(int i = 0;i < n;i++)
  {
    if(flagPartition[i] == 1)
      cnt++;
  }
  printf("%d\n", cnt);
  int flagFirst = 1;
  for(int i = 0;i < n;i++)
  {

    if(flagPartition[i] == 1)
    {
      if(flagFirst == 1)
        flagFirst = 0;
      else
        printf(" ");
      printf("%d", num[i]);
    }
  }
  putchar('\n');//坑，不输出换行会有一个测试点(测的是一个candidate都没有的时候)“格式错误”
  return 0;
}
