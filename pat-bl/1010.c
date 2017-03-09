/**
 *pat-bl-1010
 *2016-11-10
 *C version
 *方法：每次读入两个直到文件尾，处理完后输出，注意判断运算后系数为0的就跳过不输出了
 *之前关于scanf() != EOF出错，其实网站上是可以用的
 *未AC前出错一处
 */
#include<stdio.h>

int main()
{
  int spaceFlag = 0;
  int tmpC, tmpE;

  //while(scanf("%d%d", &tmpC, &tmpE) != EOF)
  while(scanf("%d%d", &tmpC, &tmpE) && tmpC != 0)
  {
    tmpC *= tmpE;
    tmpE--;
    if(tmpC == 0)//系数为零就不输出了
      continue;
    if(spaceFlag)
      putchar(' ');
    else
      spaceFlag = 1;
    printf("%d %d", tmpC, tmpE);
  }
  if(!spaceFlag)//出错：对输入是只有一个”零多项式”的判断。奇怪，不写这句会导致两个测试点过不了，所以那两个测试点都是输入了零多项式？
    printf("0 0");
  putchar('\n');
}
