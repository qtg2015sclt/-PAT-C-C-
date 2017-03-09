pat-bl-1048

2017-01-22

- 字符的处理
- 奇偶数分开处理比较方便，注意细节
- 坑：如果被加密的串长度小于加密串，是要在前面补零的

```c
/**
 * pat-bl-1048
 * 2017-01-22
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  freopen("in.txt", "r", stdin);
  char a[102], b[102];
  char theRemainder[] = "0123456789JQK";
  scanf("%s %s", a, b);
  int Dvalue = strlen(a) - strlen(b);
  if(Dvalue)//坑点：加密串长度大于被加密串，给被加密串补零
  {
    char tmp[102];
    int k;
    for(k = 0;k < Dvalue;k++)
      tmp[k] = '0';
    tmp[k] = '\0';
    strcat(tmp , b);
    strcpy(b, tmp);
  }
  //printf("b = %s\n", b);
  for(int i = strlen(a)-1, j = strlen(b)-1;i >= 0;i -= 2, j -= 2)//处理奇数位
  {
    b[j] = theRemainder[(a[i] - '0' + b[j] - '0') % 13];
    //printf("b[%d] = %c\n", j, b[j]);
  }
  for(int i = strlen(a)-2, j = strlen(b)-2;i >= 0;i -= 2, j -= 2)//处理偶数位
  {
    if(b[j] >= a[i])
      b[j] = b[j] - a[i] + '0';
    else
    {
      b[j] = b[j] - a[i] + 10 + '0';
    }
    //printf("b[%d] = %c\n", j, b[j]);
  }
  printf("%s\n", b);
}
```
-FIN-
