pat-bl-1052

2017-01-22

- 遇到了问题，不知道为什么，读进来就变成「？？？」……
- 解决：把'\0'填到了每个表情后面，这样似乎就对了……
- 看到有个用string和vector写的，特别简洁，如果有时间的话一定要练习一下
- 坑：要判断序号是否大于等于1
- 注意：输出的时候别忘了加括号
- 一个启发：一开始总写不对也是因为对字符串的处理不够熟悉，应该对每个字符同等对待，不要再写内重循环了，太容易错，具体见代码内flag那句注释

```c
/**
 * pat-bl-1052
 * 2017-01-22
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
//#include<string.h>

int main()
{
  freopen("in.txt", "r", stdin);
  char emotion[3][10][5];
  int i, j[3] = {0}, k;
  for(i = 0;i < 3;i++)
  {
    j[i] = 0;
    int flag = 0;
    char ch;
    while((ch = getchar()) != '\n')
    {
      if(ch == '[')
      {
        flag = 1;
        k = 0;
      }
      else if(ch == ']')
      {
        emotion[i][j[i]][k] = '\0';
        flag = 0;
        j[i]++;
      }
      else if(flag)//flag是把每个字符串都公平对待，都是在while里走一遍，而无需再写内重循环
      {
        emotion[i][j[i]][k++] = ch;
      }
    }
  }
  // for(i = 0;i < 3;i++)
  // {
  //   printf("j[%d] = %d\n", i, j[i]);
  //   for(k = 0;k < j[i];k++)
  //     printf("%s ", emotion[i][k]);
  //   putchar('\n');
  // }
  int K;
  scanf("%d", &K);
  for(i = 0;i < K;i++)
  {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    //printf("%d %d %d %d %d\n", a, b, c, d, e);
    if(a <= j[0] && a > 0 && b <= j[1] && b > 0 && c <= j[2] && c > 0 && d <= j[1] && d > 0 && e <= j[0] && e > 0)
      printf("%s(%s%s%s)%s\n", emotion[0][a-1], emotion[1][b-1], emotion[2][c-1], emotion[1][d-1], emotion[0][e-1]);
    else
      printf("Are you kidding me? @\\/@\n");
  }
}
```
-FIN-
