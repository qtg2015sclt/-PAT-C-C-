/**
 * pat-bl-1029
 * 2017-01-20
 * C version
 */
#include<stdio.h>
#include<string.h>

int main()
{
  freopen("in.txt", "r", stdin);
  char str1[100], str2[100];
  int alp[26] = {0}, num[10] = {0}, _flag = 0;//分别是字母、数字和下划线是否坏掉的标志
  scanf("%s", str1);
  scanf("%s", str2);
  // printf("strlen(str1) = %lu\n", strlen(str1));
  // char test1 = 'a', test2 = 'A';
  // printf("a: %d, A: %d\n", test1, test2);
  //把两个字符串中的小写都变成大写字母
  for(int i = 0;i < strlen(str1);i++)
  {
    if(str1[i] <= 'z' && str1[i] >= 'a')
    {
      str1[i] -= 32;
    }
  }
  for(int i = 0;i < strlen(str2);i++)
  {
    if(str2[i] <= 'z' && str2[i] >= 'a')
    {
      str2[i] -= 32;
    }
  }
  //printf("str1 = %s, str2 = %s\n", str1, str2);
  //遍历字符串1，和字符串2的当前字符比较，如果相等，两个当前位置都后移，继续比较；否则输出该坏键
  //注意循环控制条件应该是字符串1是否结束而非字符串2，不然会导致在字符串末尾的坏键没有被判断
  int j = 0;
  for(int i = 0, j = 0;i < strlen(str1);i++)
  {
    if(str1[i] == str2[j] && j < strlen(str2))
    {
      j++;
    }
    else
    {
      if(str1[i] <= '9' && str1[i] >= '0')
      {
        if(num[str1[i] - '0'] == 0)//该坏键第一次出现，输出坏键，并置标志位为1
        {
          printf("%c", str1[i]);
          num[str1[i] - '0'] = 1;
        }
      }
      else if(str1[i] == '_')
      {
        if(_flag == 0)
        {
          printf("_");
          _flag = 1;
        }
      }
      else if(str1[i] <= 'Z' && str1[i] >= 'A')
      {
        if(alp[str1[i] - 'A'] == 0)
        {
          printf("%c", str1[i]);
          alp[str1[i] - 'A'] = 1;
        }
      }
    }//else end
  }
  putchar('\n');
}
