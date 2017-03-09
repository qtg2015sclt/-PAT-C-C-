/**
 *pat-bl-1014
 *2016-11-13
 *C version 1.0
 *未AC前出错3处
 *坑点：要仔细读题，到底是大写还是小写，是英文字符还是字符，是判断字符还是判断下标位置，以及判断的边界在哪里，都要搞清楚
 */
#include<stdio.h>

int main()
{
  char str[4][70];
  char arrayDay[8][10] = {"zero", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  int day;
  int hh, mm;
  int i, j;
  for(i = 0;i < 4;i++)
  {
    scanf("%s", str[i]);
  }
  i = 0;
  while(1)//判断是星期几
  {
    if(str[0][i] <= 'G' && str[0][i] >= 'A')//出错3：边界问题，应该<='G'，而不是<='Z'
    {
      if(str[0][i] == str[1][i])
      {
        day = str[0][i] - 'A' + 1;
        break;
      }
    }
    i++;
  }
  while(1)//判断是一天中的几点
  {
    i++;//出错1：忘记跳出上一个循环要++
    if(str[0][i] == str[1][i])
    {
      if((str[0][i] <= 'N')&&(str[0][i] >= 'A'))
      {
        hh = str[0][i] - 'A' + 10;
        //printf("%c, %d\n", str[0][i], hh);
        break;
      }
      if((str[0][i] <= '9')&&(str[0][i] >= '0'))
      {
        hh = str[0][i] - '0';
        break;
      }
    }
  }
  i = 0;
  while(1)//判断是第几分钟
  {
    if(str[2][i] == str[3][i])
    {
      if((str[2][i] <= 'z' && str[2][i] >= 'a') || (str[2][i] <= 'Z' && str[2][i] >= 'A'))
      {
        mm = i;
        break;
      }
    }
    i++;
  }
  //output:出错2：格式控制
  printf("%s %02d:%02d\n", arrayDay[day], hh, mm);
}
