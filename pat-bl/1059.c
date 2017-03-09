/**
 * pat-bl-1059
 * 2017-01-23
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int prime[10000] = {1, 2, 3};//素数表，1只是作为第0位的占位，并非素数
void primeNum()
{
  int num, i, flag;
  for(num = 5;num < 10000;num += 2)//从5开始求取素数表
  {
    i = 1, flag = 1;//默认是素数
    while(prime[i] != 0)
    {
      if(num % prime[i] == 0)
      {
        flag = 0;
        break;
      }
      else
        i++;
    }
    if(flag)//是素数
      prime[i] = num;
  }
  //test:
  // for(int k = 0;k < 20;k++)
  // {
  //   printf("%d ", prime[k]);
  // }
  // putchar('\n');
  //test end
}
int isPrime(int num)
{
  int i = 0;
  while(prime[i] != 0)
  {
    if(num == prime[i])
    {
      return 1;//在素数表中找到了该数，说明是素数
    }
    else
      i++;
  }
  return 0;//表中没有此数，说明是合数
}
int main()
{
  primeNum();//求素数
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int hs[10000];//编号作为下标，名次作为内容
  memset(hs, -1, sizeof(hs));
  for(int i = 0;i < n;i++)
  {
    int tmp;
    scanf("%d", &tmp);
    hs[tmp] = i+1;
  }
  int k;
  scanf("%d", &k);
  for(int i = 0;i < k;i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if(hs[tmp] == 1)
    {
      hs[tmp] = 0;//将领过奖品的置为0
      printf("%04d: Mystery Award\n", tmp);
    }
    else if(hs[tmp] == -1)
    {
      printf("%04d: Are you kidding?\n", tmp);
    }
    else if(hs[tmp] == 0)
    {
      printf("%04d: Checked\n", tmp);
    }
    else if(isPrime(hs[tmp]))
    {
      hs[tmp] = 0;
      printf("%04d: Minion\n", tmp);
    }
    else
    {
      hs[tmp] = 0;
      printf("%04d: Chocolate\n", tmp);
    }
  }
}
