/**
 * pat-bl-1028
 * 2017-01-20
 * C version
 */
#include<stdio.h>
#include<string.h>

int m[13][2] = {0, 0,
                31, 31,
                28, 29,
                31, 31,
                30, 30,
                31, 31,
                30, 30,
                31, 31,
                31, 31,
                30, 30,
                31, 31,
                30, 30,
                31, 31};//区分闰年和非闰年的日期差别
int isLeap(int y)//判断是否是闰年
{
  return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
int days(int yy, int mm, int dd)//计算该日期在该年已经过了多少天
{
  int k = 0, day = 0;
  if(isLeap(yy))
  {
    k = 1;
  }
  for(int i = 1;i < mm;i++)
  {
    day += m[i][k];
  }
  day += dd;
  return day;
}
int main()
{
  //预先计算出最早以及最晚的日期距离0年0月0日的天数：
  int minDays = days(1814, 9, 6);
  //printf("minDays = %d\n", minDays);
  for(int i = 1814;i < 1814;i++)
  {
    if(isLeap(i))
      minDays += 366;
    else
      minDays += 365;
  }
  int maxDays = days(2014, 9, 6);
  for(int i = 1814;i < 2014;i++)
  {
    if(isLeap(i))
      maxDays += 366;
    else
      maxDays += 365;
  }
  //printf("minDays = %d, maxDays = %d\n", minDays, maxDays);
  freopen("in.txt", "r", stdin);
  int n;
  char maxName[10], minName[10];
  int max = minDays, min = maxDays;
  int cnt = 0;
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
  {
    char tmpName[10];
    int tmpYY, tmpMM, tmpDD;
    scanf("%s", tmpName);
    scanf("%d/%d/%d\n", &tmpYY, &tmpMM, &tmpDD);
    //printf("%s: %04d %02d %02d\n", tmpName, tmpYY, tmpMM, tmpDD);
    if(tmpYY < 1814 || tmpYY > 2014)//判断年份是否有效，无效则进行下一行的输入
      continue;
    int tmpDays = days(tmpYY, tmpMM, tmpDD);
    //printf("tmpName = %s, tmpDays = %d\n", tmpName, tmpDays);
    for(int i = 1814;i < tmpYY;i++)
    {
      if(isLeap(i))
        tmpDays += 366;
      else
        tmpDays += 365;
    }
    //printf("tmpName = %s, tmpDays = %d\n", tmpName, tmpDays);
    if(tmpDays <= maxDays && tmpDays >= minDays)//判断日期是否有效
    {
      cnt++;
      //printf("cnt = %d\n", cnt);
      if(tmpDays < min)//如果日期比当前最小还小就更新
      {
        min = tmpDays;
        strcpy(minName, tmpName);
        //printf("refresh minName = %s\n", minName);
      }
      if(tmpDays > max)
      {
        max = tmpDays;
        strcpy(maxName, tmpName);
        //printf("refresh maxName = %s\n", maxName);
      }
    }
  }
  //printf("hello\n");
  if(cnt != 0)
    printf("%d %s %s\n", cnt, minName, maxName);//注意，日期越小越年长
  else//所有数据都无效时:
    printf("0\n");
}
