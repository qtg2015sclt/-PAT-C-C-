/**
 * pat-al-1015
 * 2017-01-26
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int prime[100000] = {1, 2, 3};//素数表，1作为占位，并非素数
void primeNum()//使用筛法求取素数表
{
  int num, i, flag;
  for(num = 5;num < 100000;num += 2)
  {
    i = 1, flag = 1;//默认是素数
    while(prime[i] != 0)
    {
      if(num % prime[i] == 0)
      {
        flag = 0;//非素数
        break;
      }
      else
        i++;
    }
    if(flag)//是素数
      prime[i] = num;
  }
}
int isPrime(int num)
{
  int i = 1;
  while(prime[i] != 0)
  {
    if(prime[i] == num)//在素数表中找到，说明是素数
      return 1;
    else
      i++;
  }
  return 0;//没在素数表中找到，说明是合数
}
int transformAndReverse(int n, int d)
{
  int num[20];//n最大为99999，转成2进制，最最长不超过17位
  int i = 0;
  while(n)
  {
    num[i] = n % d;
    i++;
    n /= d;
  }
  int result = 0;
  for(int j = 0;j < i;j++)
  {
    result = result * d + num[j];
  }
  return result;
}
int main()
{
  //坑：一开始就理解错题目了，题目的意思是先判断该数是否素数，如果不是直接no，如果是，就继续将之转换为d进制数，然后反转再转回十进制数判断是否是素数
  primeNum();//先求素数表
  freopen("in.txt", "r", stdin);
  int n, d;
  scanf("%d", &n);
  while(n  > 0)
  {
    //printf("n = %d\n", n);
    scanf("%d", &d);
    //printf("d = %d\n", d);
    int newN = transformAndReverse(n, d);
    //printf("new n = %d\n", newN);
    if(isPrime(n) && isPrime(newN))
    {
      printf("Yes\n");
    }
    else
      printf("No\n");//出错：注意字母大小写
    scanf("%d", &n);
  }
}
