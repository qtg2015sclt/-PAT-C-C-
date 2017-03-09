/**
 * pat-al-1041
 * 2017-01-26
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  //坑：没注意第一个数字是接下来总共要输入的个数
  freopen("in.txt", "r", stdin);
  int num[10001];
  memset(num, 0, sizeof(num));
  int n;
  scanf("%d", &n);
  int input[n];
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &input[i]);
    num[input[i]]++;
  }
  int flagWin = 0;
  for(int i = 0;i < n;i++)
  {
    if(num[input[i]] == 1)
    {
      printf("%d\n", input[i]);
      flagWin = 1;
      break;
    }
  }
  if(flagWin == 0)//没人赢
    printf("None\n");
}
