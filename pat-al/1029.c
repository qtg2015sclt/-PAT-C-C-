/**
 * pat-al-1029
 * 2017-02-23
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#define INF 0x3f3f3f3f
#define MAX 1000010
long num1[MAX], num2[MAX];//放在main里会段错误
int main()
{
  freopen("in.txt", "r", stdin);
  int n1, n2;
  scanf("%d", &n1);
  for(int i = 0;i < n1;i++)
  {
    scanf("%ld", &num1[i]);
  }
  num1[n1] = INF;//哨兵
  scanf("%d", &n2);
  for(int i = 0;i < n2;i++)
  {
    scanf("%ld", &num2[i]);
  }
  num2[n2] = INF;
  int mid = (n1+n2+1)/2;
  int cnt = 0, i = 0, j = 0;
  long median;
  while(cnt < mid)
  {
    if(num1[i] < num2[j])
    {
      median = num1[i];
      i++;
    }
    else
    {
      median = num2[j];
      j++;
    }
    cnt++;
  }
  printf("%ld\n", median);
}
