/**
 * pat-bl-1044
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>

int main()
{
  char first[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
  char second[13][5] = {" ", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
  //freopen("in.txt", "r", stdin);
  int n;
  scanf("%d\n", &n);//fgets会读回车，所以加上\n
  char str[10];
  int num;
  for(int i = 0;i < n;i++)
  {
    //scanf("%s", str);
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    //printf("%s", str);
    if(str[0] >= '0' && str[0] <= '9')//is number of earth
    {
      //printf("str[0] = %c\n", str[0]);
      num = str[0] - '0';
      //printf("num = %d\n", num);
      int i = 1;
      while(str[i] != '\0')
      {
        num = num * 10 + str[i++] - '0';
      }
      //printf("num = %d\n", num);
      if(num / 13 != 0 && num % 13 != 0)
        printf("%s %s\n", second[num / 13], first[num % 13]);
      else if(num / 13 == 0)
        printf("%s\n", first[num % 13]);
      else//坑点：13应该输出tam，而不是tam tret，有两个测试点是包含这个的
        printf("%s\n", second[num / 13]);
    }
    else//is number of marz
    {
      num = 0;
      char *secNum = NULL;
      secNum = strtok(str, " ");
      char *firNum = NULL;
      firNum = strtok(NULL, " ");
      if(firNum != NULL)//有两个字串
      {
        //printf("strlen(firNum) = %lu, strlen(secNum) = %lu\n", strlen(firNum), strlen(secNum));
        //printf("secNum = %s, firNum = %s", secNum, firNum);
        for(int k = 0;k < 13;k++)
        {
          //printf("hello, compute the first\n");
          if(strcmp(firNum, first[k]) == 0)
          {
            num = k;
            //printf("fir: k = %d, num = %d\n", k, num);
            break;
          }
        }
      }
      //printf("hello, firNum is NULL\n");
      //printf("secNum = %s", secNum);
      int k;
      for(k = 0;k < 13;k++)
      {
        if(strcmp(secNum, second[k]) == 0)
        {
          num += k * 13;
          //printf("sec: k = %d, num = %d\n", k, num);
          break;
        }
      }
      if(k == 13)
      {
        for(k = 0;k < 13;k++)
        {
          if(strcmp(secNum, first[k]) == 0)
          {
            num += k;
            //printf("sec: k = %d, num = %d\n", k, num);
            break;
          }
        }
      }
      printf("%d\n", num);
    }
  }
}
