/**
 * pat-al-1059
 * 2017-02-27
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#define MAX 500010
using namespace std;
vector<int> prime(MAX);
int main()
{
  for(int i = 2;i * i < 500000;i++)
    for(int j = 2;j * i < 500000;j++)
      prime[i*j] = 1;//非素数置为1
  freopen("in.txt", "r", stdin);
  long n;
  scanf("%ld", &n);
  printf("%ld=", n);
  int cnt, i = 2, notFirst = 0;
  if(n == 1)
    printf("1");
  while(n != 1)
  {
    cnt = 0;
    while(n % i == 0 && prime[i] == 0)
    {
      cnt++;
      n /= i;
    }
    if(cnt != 0)
    {
      if(notFirst)
        putchar('*');
      printf("%d", i);
      notFirst = 1;
      if(cnt > 1)
        printf("^%d", cnt);
    }
    i++;
  }
  putchar('\n');
  return 0;
}
