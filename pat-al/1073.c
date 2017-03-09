/**
 * pat-al-1073
 * 2017-01-27
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  freopen("in.txt", "r", stdin);
  char sign = getchar();
  if(sign == '-')
    putchar('-');
  char ch = getchar();//读小数点前的数
  int a = ch - '0';
  //printf("a = %d\n", a);
  getchar();//读掉'.'
  char str[10002];//读小数点后的数
  int i = 0;
  while((ch = getchar()) != 'E')
  {
    str[i++] = ch;
  }
  str[i] = '\0';
  //printf("str = %s\n", str);
  sign = getchar();//读指数的符号
  //printf("sign of e = %c\n", sign);
  int e;
  scanf("%d", &e);//读指数
  //printf("e = %d\n", e);
  if(e == 0)//坑：指数为0的时候特殊处理一下，不然会出错
  {
    printf("%d.%s\n", a, str);
    return 0;
  }
  if(sign == '-')
  {
    printf("0.");
    for(int i = 1;i < e;i++)
      putchar('0');
    printf("%d%s", a, str);
  }
  else
  {
    printf("%d", a);
    if(strlen(str) <= e)
    {
      printf("%s", str);
      for(int i = 0;i < e-strlen(str);i++)
        putchar('0');
    }
    else
    {
      int i;
      for(i = 0;i < e;i++)//出错：一开始写成strlen(str)-e了……
        putchar(str[i]);
      if(i < strlen(str))
        putchar('.');
      for(;i < strlen(str);i++)
        putchar(str[i]);
    }
  }
  putchar('\n');
}
