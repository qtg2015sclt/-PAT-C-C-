/**
 * pat-al-1024
 * 2017-02-20
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct bign
{
  int d[1000];
  int len;
  bign()
  {
    memset(d, 0, sizeof(d));
    len = 0;
  }
};
bign change(char str[])
{
  bign a;
  a.len = strlen(str);
  for(int i = 0;i < a.len;i++)
  {
    a.d[i] = str[i] - '0';
  }
  return a;
}
bool judge(bign a)
{
  for(int i = 0;i < a.len/2;i++)
  {
    if(a.d[i] != a.d[a.len-1-i])
      return false;
  }
  return true;
}
bign add(bign a, bign b)
{
  bign c;
  int carry = 0;
  for(int i = 0;i < a.len;i++)
  {
    int tmp = a.d[i] + b.d[i] + carry;
    c.d[c.len++] = tmp % 10;
    carry = tmp / 10;
  }
  if(carry != 0)
    c.d[c.len++] = carry;
  return c;
}
void print(bign a)
{
  for(int i = a.len-1;i >= 0;i--)
  {
    printf("%d", a.d[i]);
  }
  printf("\n");
}
int main()
{
  freopen("in.txt", "r", stdin);
  char num[1000];
  int k, cnt = 0;
  scanf("%s%d", num, &k);
  bign a = change(num);
  while(cnt < k && judge(a) == false)
  {
    cnt++;
    bign b = a;
    reverse(b.d, b.d+b.len);
    a = add(a, b);//注意：得到的是并非真正的a+b，而是倒置的a+b
  }
  print(a);
  printf("%d\n", cnt);
  return 0;
}
