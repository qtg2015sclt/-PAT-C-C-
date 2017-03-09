/**
 *pat-bl-1018
 *2016-11-17
 *C version 1.0
 */
#include<stdio.h>

char max(int x, int y, int z){//返回最大值所对应的手势
  if(x >= y)
  {
    if(x >= z)
      return 'B';
    else
      return 'J';
  }
  else if(y >= z)
    return 'C';
  else
    return 'J';
}
int main()
{
  int n, i;
  int arr[3][3] = {{0, 1, -1}, {-1, 0, 1}, {1, -1, 0}};//每对手势所对应的胜平负矩阵，0代表平
  char ch[2];
  int gesture[2];
  int ans[2][3] = {0}, gstMax[2][3] = {0};//ans是胜平负的结果，gstMax是每个手势的胜次
  char aMax, bMax;
  //freopen("in.txt", "r", stdin);
  scanf("%d%*c", &n);
  while(n--)
  {
    scanf("%c %c%*c", &ch[0], &ch[1]);
    //printf("ch0 = %c, ch1 = %c\n", ch[0], ch[1]);
    for(i = 0;i < 2;i++)
    {
      switch (ch[i]) {//读取手势并转换为数字
        case 'B':gesture[i] = 0;break;
        case 'C':gesture[i] = 1;break;
        case 'J':gesture[i] = 2;break;
      }
    }
    //printf("gesture0 = %d, gesture1 = %d\n", gesture[0], gesture[1]);
    switch (arr[gesture[0]][gesture[1]]) {//根据胜平负保存结果并累加每个手势的胜次
      case 1:ans[0][0]++;ans[1][2]++;gstMax[0][gesture[0]]++;break;
      case 0:ans[0][1]++;ans[1][1]++;break;
      case -1:ans[0][2]++;ans[1][0]++;gstMax[1][gesture[1]]++;break;
    }
  }
  // for(i = 0;i < 2;i++)
  // {
  //   printf("%d %d %d\n", gstMax[i][0], gstMax[i][1], gstMax[i][2]);
  // }
  printf("%d %d %d\n", ans[0][0], ans[0][1], ans[0][2]);
  printf("%d %d %d\n", ans[1][0], ans[1][1], ans[1][2]);
  aMax = max(gstMax[0][0], gstMax[0][1], gstMax[0][2]);//把手势的数字含义转换回字符
  bMax = max(gstMax[1][0], gstMax[1][1], gstMax[1][2]);
  printf("%c %c\n", aMax, bMax);
}
