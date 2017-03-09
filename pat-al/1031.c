/**
 * pat-al-1031
 * 2017-01-26
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  freopen("in.txt", "r", stdin);
  char str[85];
  scanf("%s", str);
  int n = strlen(str);
  int n1, n2;
  for(int i = 3;i < n;i++)
  {
    int j;
    if((n+2-i) % 2 == 0)
      j = (n + 2 - i) / 2;
    else
      continue;
    if(j <= i)
    {
      n1 = j;
      n2 = i;
      break;
    }
  }
  //output:
  for(int i = 0;i < n1-1;i++)
  {
    printf("%c", str[i]);
    for(int j = 0;j < n2-2;j++)
      printf(" ");
    printf("%c\n", str[n-1-i]);
  }
  for(int i = 0;i < n2;i++)
  {
    printf("%c", str[n1-1+i]);
  }
  putchar('\n');
  return 0;
}
