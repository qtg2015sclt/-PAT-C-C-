pat-al-1005

2017-01-24

- 零的时候特殊处理一下，不知道有没有测试点测这个
- 用字符串二维数组保存要输出的英文

```c
/**
 * pat-al-1005
 * 2017-01-25
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  freopen("in.txt", "r", stdin);
  char str[102];
  scanf("%s", str);
  int sum = 0;
  for(int k = 0;k < strlen(str);k++)
  {
    //printf("str[%d] = %c\n", k, str[k]);
    sum += str[k] - '0';
  }
  int num[10];
  if(sum == 0)
  {
    printf("zero\n");
    return 0;
  }
  int i = 0;
  while(sum)
  {
    num[i++] = sum % 10;//常常写while的时候忘了写成i++，就会段错误
    sum /= 10;
  }
  char num2English[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  printf("%s", num2English[num[--i]]);
  for(i = i-1;i >= 0;i--)
  {
    printf(" %s", num2English[num[i]]);
  }
  putchar('\n');
  return 0;
}
```
-FIN-
