pat-al-1031

2017-01-26

- 只要求出n1和n2，接下来输出就好了
- 求n1和n2：对每一个n2>=3开始，（因为n已知）求出对应的n1（当然前提是该对应的n1是整数），一旦该次的n2大于等于n1了，就说明已经得到了最合适的n1和n2。可以手工在草稿纸上做一遍，更清楚。
- 输出的时候注意一下格式和细节

```c
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
```
-FIN-
