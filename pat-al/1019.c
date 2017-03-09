/**
 * pat-al-1019
 * 2017-01-26
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n, b;
  scanf("%d %d", &n, &b);
  int num[35];
  int i = 0;
  if(n == 0)//坑：要把0的情况特殊处理一下，不然有一个测试点在自己这跑出来可能是正确的、提交了却是错误的
  {//坑（续1）：而且虽然在自己这跑出来可能正确，但事实上是错误的，见后面注释的坑（续2）
    printf("Yes\n0\n");
    return 0;
  }
  while(n)
  {
    num[i] = n % b;
    i++;
    n /= b;
  }
  int cnt = i, flagFail = 0;
  for(i = 0;i < cnt;i++)
  {
    if(num[i] == num[cnt - i - 1])
      continue;
    else
    {
      flagFail = 1;
      break;
    }
  }
  if(flagFail)
    printf("No\n");
  else
    printf("Yes\n");
  printf("%d", num[cnt-1]);//坑（续2）：如果不特殊处理，事实上这里对数组的访问会越界（因为cnt = 0）
  for(i = cnt - 2;i >= 0;i--)
  {
    printf(" %d", num[i]);
  }
  putchar('\n');
  return 0;
}
