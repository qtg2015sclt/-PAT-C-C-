pat-bl-1024

2017-01-19

- 注意字符串数组开的不要太小，也不要贴着边界，可能会出错
- 使用了strtok分割和atof字符串转换为浮点数的函数，分别在string.h和stdlib.h中

```c
/**
 * pat-bl-1024
 * 2017-01-19
 * C version
 * 字符串处理
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  freopen("in.txt", "r", stdin);
  char tmp;
  char str[10001];//出错：如果是10000的话，最后一个测试点过不了
  char str2[] = ".E";//用来分割的字符
  int sign = 0;//默认是正数

  if(scanf("%c", &tmp) && tmp == '-')
  {
    putchar('-');
  }

  fgets(str, sizeof(str), stdin);
  str[strlen(str) - 1] = '\0';
  char *a1 = NULL, *a2 = NULL, *e = NULL;
  a1 = strtok(str, str2);//分割
  //printf("a1 = %s\n", a1);
  a2 = strtok(NULL, str2);//分割
  //printf("a2 = %s\n", a2);
  e = strtok(NULL, str2);//分割
  int num = atof(e);//字符串转换为浮点数
  if(e[0] == '-' && num != 0)//指数为负数的时候，根据指数输出多个0.以及多个0，之后拼接上a1和a2即可
  {
    num = -1 * num;
    //printf("\ne = %d\n", num);
    printf("0.");
    while(num > 1)
    {
      printf("0");
      num--;
    }
    printf("%s%s", a1, a2);
    putchar('\n');
  }
  else//指数非负的时候两种情况
  {
    printf("%s", a1);
    if(strlen(a2) <= num)//情况1：指数大于等于小数点后的位数，输出小数点后的数，然后补零
    {
      printf("%s", a2);
      num -= strlen(a2);
      while(num)
      {
        printf("0");
        num--;
      }
      putchar('\n');
    }
    else//情况2：指数小于小数点后的位数，输出部分数后加小数点，然后输出剩下的数
    {
      int i = 0;
      for(;i < num;i++)
      {
        printf("%c", a2[i]);
      }
      printf(".");
      printf("%s\n", (a2+i));
    }
  }
}
```
-FIN-
