pat-bl-1019

2016-11-18

- 方法：在数字和字符数组之间转换，进行处理后输出
- 利用sprintf和sscanf进行数字和字符串的转变，不用自己写函数了
- 坑点：注意转换和输出时的格式控制，以及对边界的处理，具体见注释

```c
/**
 *pat-bl-1019
 *2016-11-18
 *C version
 *注意格式控制
 */
#include<stdio.h>

int main()
{
  int num;
  int flag = 1;
  //freopen("in.txt", "r", stdin);
  scanf("%d", &num);
  char str[5];// = num2str(num);
  while(num != 6174)
  {
    flag = 0;//设置flag来判断是否进入过while循环，没进过的话循环flag为1，说明num为6174，后面判断后直接输出
    sprintf(str, "%04d", num);//要控制格式，不然会出错和超时
    if(str[0] == str[1] && str[0] == str[2] && str[0] == str[3])
    {
      printf("%d - %d = 0000\n", num, num);
      break;
    }
    //printf("str = %s\n", str);
    int maxNum, minNum;
    //冒泡排序得到非降序排列：
    for(int i = 3;i >= 0;i--)
    {
      for (int j = 0;j < i; j++) {
        if(str[j] > str[j+1])
        {
          int tmp = str[j];
          str[j] = str[j+1];
          str[j+1] = tmp;
        }
      }
      //printf("str[%d] = %c\n", i, str[i]);
    }
    sscanf(str, "%d", &minNum);
    //交换字符得到非升序排列：
    for(int i = 0;i <= 1;i++)
    {
      int tmp = str[i];
      str[i] = str[3-i];
      str[3-i] = tmp;
    }
    sscanf(str, "%d", &maxNum);
    num = maxNum - minNum;
    printf("%d - %04d = %04d\n", maxNum, minNum, num);//要控制输出格式
  }
  if(flag)//flag为1说明num是6174，直接输出
  {
    printf("7641 - 1467 = 6174\n");
  }
}
```
-Fin-
