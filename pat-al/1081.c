/**
 * pat-al-1081
 * 2017-01-27
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int gcd(long a, long b)
{
  return b == 0 ? a : gcd(b, a%b);
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  long input[2], sum[2] = {0, 1};
  for(int i = 0;i < n;i++)
  {
    scanf("%ld/%ld", &input[0], &input[1]);//0位是分子，1位是分母
    if(input[0] == 0)//坑：要对输入的0特殊处理一下，有个测试点包括这个
      continue;
    sum[0] = sum[0] * input[1] + input[0] * sum[1];//新的分母
    sum[1] = sum[1] * input[1];
    long d = gcd(sum[0], sum[1]);//化为最简
    if(d < 0)//坑：对求出的d需要处理
      d = -d;
    sum[0] /= d;
    sum[1] /= d;
  }
  if(sum[0] < 0)
  {
    putchar('-');
    sum[0] = -sum[0];
  }
  if(sum[1] == 1)//分母为1就不要输出分母了
    printf("%ld\n", sum[0]);
  else if(sum[0] > sum[1])
    printf("%ld %ld/%ld\n", sum[0]/sum[1], sum[0]%sum[1], sum[1]);
  else
    printf("%ld/%ld\n", sum[0], sum[1]);
}
