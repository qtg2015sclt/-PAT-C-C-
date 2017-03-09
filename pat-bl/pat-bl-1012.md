pat-bl-1012

2016-11-10

- 方法：对a1到a5分别做判断
- 未AC前出错3处
  1. 第一个数是数据规模
  2. count是为了查看满足a1（或其他）的数到底有没有出现过(说好的都是正整数呢，不能判a5是否为零，必须判count计数)
  3. 经尝试，发现a1需要判断的是“满足整除中的偶数”
- 难点：判定点有问题。对是否是“N”的判断，a1和a5是有坑的，a1判偶数，a5判出现

```c
/**
 *pat-bl-1012
 *2016-11-10
 *C version 1.0
 *未AC前出错3处。关于到底怎么判"N"，这题有毒
 */
#include<stdio.h>

int main()
{
  int tmpNum, tmp, i, spaceFlag = 0;
  int a1 = 0, a2 = 0, a4 = 0, a5 = 0;
  int a1c = 0, a2c = 0, a3c = 0, a4c = 0, a5c = 0;
  //出错2：count是为了查看满足a1（或其他）的数到底有没有出现过
  //出错3：经尝试，发现a1需要判断的是“满足整除中的偶数”
  scanf("%d", &i);//出错1：第一个数是数据规模
  while(i--)
  {
    //printf("tmpNum=%d\n", tmpNum);
    scanf("%d", &tmpNum);
    tmp = tmpNum % 5;
    //printf("tmp = %d\n", tmp);
    switch(tmp)
    {
      case 0:
      {
        a1c++;//出错3：如果放在这里，最后判断a1c就会出错
        if(tmpNum % 2 == 0)
          a1 += tmpNum;
        //printf("a1=%d\n", a1);
        break;
      }
      case 1:
      {
        a2c++;
        if(a2c % 2 == 0)
          tmpNum = -tmpNum;
        a2 += tmpNum;
        //printf("a2=%d\n", a2);
        break;
      }
      case 2:a3c++;/*printf("a3c=%d\n", a3c);*/break;
      case 3:a4c++;a4 += tmpNum;/*printf("a4=%.1f\n", a4);*/break;
      case 4:
      {
        a5c++;//出错2：说好的都是正整数呢，不能判a5是否为零，必须判count计数
        if(a5 < tmpNum)
          a5 = tmpNum;
          //printf("a5=%d\n", a5);
        break;
      }
    }
  }
  if(a1)//出错3：这里用a1c会错
    printf("%d ", a1);
  else
    printf("N ");
  if(a2c)
    printf("%d ", a2);
  else
    printf("N ");
  if(a3c)
    printf("%d ", a3c);
  else
    printf("N ");
  if(a4c)
    printf("%.1f ", 1.0*a4/a4c);
  else
    printf("N ");
  if(a5c)
    printf("%d", a5);
  else
    printf("N");
  putchar('\n');
}
```
-Fin-
