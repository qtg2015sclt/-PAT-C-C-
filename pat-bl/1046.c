/**
 * pat-bl-1046
 * 2017-01-22
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>

int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int a[n][2], b[n][2];
  for(int i = 0;i < n;i++)
  {
    scanf("%d %d %d %d", &a[i][0], &a[i][1], &b[i][0], &b[i][1]);
  }
  int aDrink = 0, bDrink = 0;
  for(int i = 0;i < n;i++)
  {
    if(a[i][1] == (a[i][0] + b[i][0]) && a[i][1] != b[i][1])//甲划出的等于二人喊的，但乙划出的不等于，那么甲胜，乙喝酒
    {
      bDrink++;
    }
    else if(b[i][1] == (a[i][0] + b[i][0]) && a[i][1] != b[i][1])//乙划出的等于二人喊的，但甲划出的不等于，那么乙胜，甲喝酒
    {
      aDrink++;
    }
    else//同输或同赢，进行下一轮
      continue;
  }
  printf("%d %d\n", aDrink, bDrink);
}
