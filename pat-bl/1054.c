/**
 * pat-bl-1054
 * 2017-01-22
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int isValid(char str[])
{
  char *tmp1 = NULL;
  char *tmp2 = NULL;
  char *tmp3 = NULL;
  tmp1 = strtok(str, ".");
  tmp2 = strtok(NULL, ".");
  tmp3 = strtok(NULL, ".");
  if(tmp2 != NULL && strlen(tmp2) > 2)//小数点后有数字且多余两位，不合法
  {
    //printf("tmp2 = %s\n", tmp2);
    return 0;
  }
  else if(tmp3 != NULL)//有两个及以上的小数点，不合法
  {
    //printf("tmp1 = %s, tmp2 = %s, tmp3 = %s\n", tmp1, tmp2, tmp3);
    return 0;
  }
  else
  {
    for(int i = 0;i < strlen(tmp1);i++)
    {
      if(i == 0 && tmp1[0] == '-')
        continue;
      else if(tmp1[i] < '0' || tmp1[i] > '9')//有字母，不合法
      {
        //printf("%c is invalid\n", tmp1[i]);
        return 0;
      }
    }
    return 1;
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, cnt = 0;
  double sum = 0;
  scanf("%d", &n);
  char str[1000], tmp[1000];//做分割会改变原字符串，所以复制一份，tmp拿去做分割
  for(int i = 0;i < n;i++)
  {
    scanf("%s", str);
    strcpy(tmp, str);
    //printf("before strtok, tmp = %s\n", tmp);
    if(isValid(tmp))
    {
      //printf("after strtok, tmp = %s\n", tmp);
      double num = atof(str);
      //printf("num = %lf\n", num);
      if(fabs(num) <= 1000)
      {
        //printf("num = %lf\n", num);
        cnt++;
        sum += num;
      }
      else
      {
        printf("ERROR: %s is not a legal number\n", str);
      }
    }
    else
    {
      printf("ERROR: %s is not a legal number\n", str);
    }
  }
  if(cnt == 1)
    printf("The average of 1 number is %.2lf\n", sum);//大坑！！number后面没有s
  else if(cnt > 1)
    printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
  else
    printf("The average of 0 numbers is Undefined\n");
}
