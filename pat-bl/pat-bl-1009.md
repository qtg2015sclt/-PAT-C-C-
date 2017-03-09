pat-bl-1009

2016-11-10更新

2016-11-06

- 方法：
  1. strtok函数分割字符串
  2. 每次scanf一个(已解决）
  3. 用C++写，基本数据类型、容器、迭代器。参考：[PAT Basic Level 1009. 说反话（20）](http://blog.csdn.net/shuaiilong/article/details/21169489)
- 未AC前出错6处
  1. gets() has been removed from C11 standard,所以要改用fgets()。参考：[Implicit declaration of 'gets'](http://stackoverflow.com/questions/34031514/implicit-declaration-of-gets)
  2. 不能写成ans[i++] = pStr,而是strcpy(ans[i++], pStr)。参考：[字符串数组/字符串指针的赋值](http://blog.csdn.net/douzixinxin/article/details/602815)
  3. 见代码内
  4. 方法1.的str[81]提交的话就会出问题，目前不清楚为什么
  5. scanf不能读指针只能读数组,why?因为没分配空间？
  6. 无法终止读入至今没改对(已改好)


```c
/**
 * pat-bl-1009
 * 2016-11-06
 * C version 2.0更新于2016-11-10
 * 方法:
 *      1.strtok函数分割字符串
 *      2.每次scanf一个（已改好）
 * 未AC时出错6处
 */
#include<stdio.h>
#include<string.h>

//idea 1:
int main()
{
  char str[82];//出错4：str[81]提交的话就会出问题，目前不清楚为什么
  char *pStr;
  char ans[82][82];
  int i = 0, cnt = 0;;
  fgets(str, sizeof(str), stdin);//出错1:gets() has been removed from C11 standard,所以要改用fgets()
  str[strlen(str)-1] = '\0';
  pStr = strtok(str, " ");//做第一次分割
  while(pStr)
  {
    strcpy(ans[i++], pStr);//出错2：不能写成ans[i++] = pStr
    pStr = strtok(NULL, " ");//继续分割
  }
  while(i--)//出错3：写成了--i的话第0个就不能输出了
  {
    if(cnt++)
    {
      putchar(' ');
    }
    printf("%s", ans[i]);
  }
  printf("\n");
  return 0;
}

//idea 2:
int main()
{
  char tmp[81];
  char str[81][81];
  int i = 0, cnt = 0;
  //scanf("%s", tmp);//出错5:scanf不能读指针只能读数组,why?因为没分配空间？
  while(scanf("%s", tmp) != EOF)//出错6：改为while(scanf("%s", tmp) != EOF)就可以
  {
    //printf("%s\n", tmp);
    strcpy(str[i++], tmp);//出错2：不能写成ans[i++] = pStr
    //scanf("%s", tmp);
  }
  while(i--)//出错3：写成了--i的话第0个就不能输出了
  {
    if(cnt++)
    {
      putchar(' ');
    }
    printf("%s", str[i]);
  }
  printf("\n");
  return 0;
}

```

-Fin-
