pat-al-1001

2017-01-24

- 注意：和为0的时候要特殊处理
- 方法：用取余的方法从个位开始依次分割出每一位放入一个字符串数组中，并对数字的个数计数，每3个就填入一个逗号，注意最后3个（或不足3个）就无需填逗号了

```c
/**
 * pat-al-1001
 * 2017-01-24
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int a, b;
  scanf("%d %d", &a, &b);
  int c = a + b;
  if(c < 0)
  {
    putchar('-');
    c = -c;
  }
  if(c == 0)//对和为0特殊处理一下
  {
    printf("0\n");
    return 0;
  }
  char num[10];
  int cntNum = 0, k = 0;
  while(c)
  {
    num[k++] = c % 10 + '0';//从各位开始，将c依次填入num[]数组
    cntNum++;
    c /= 10;
    if(cntNum % 3 == 0 && c != 0)
    {
      //printf("cntNum = %d\n", cntNum);
      num[k++] = ',';
    }
    //printf("num[%d] = %d\n", cnt-1, num[cnt-1]);
  }
  for(int i = k-1;i >= 0;i--)
  {
    printf("%c", num[i]);
  }
  putchar('\n');
  return 0;
}
```
-FIN-
