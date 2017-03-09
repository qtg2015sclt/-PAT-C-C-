/**
 * pat-al-1096
 * 2017-01-27
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<math.h>
int main()
{
  //本题没什么思路（甚至一开始题目都没读懂QAQ），完全参考了别人的，链接见md文件
  //test:
  // long result1 = 1;
  // for(int i = 0;i < 31;i++)
  //   result1 *= 2;
  // long result2 = 1;
  // for(int i = 1;i <= 12;i++)
  //   result2 *= i;
  // long result3 = 1;
  // for(int i = 1;i <= 13;i++)
  //   result3 *= i;
  // printf("result1 = %ld\n", result1);
  // printf("result2 = %ld\n", result2);
  // printf("result3 = %ld\n", result3);
  //test end
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int max = sqrt(n);
  for(int len = 12;len >= 1;len--)//坑：len必须是>=1，等于号必须加上，不然连乘因子数等于1的情况无法输出
  {
    for(int start = 2;start <= max;start++)
    {
      int ans = 1;
      for(int i = start;i - start <= len - 1;i++)
        ans *= i;
      if(n % ans == 0)
      {
        printf("%d\n%d", len, start);
        for(int i = start+1;i - start <= len - 1;i++)
          printf("*%d", i);
        putchar('\n');
        return 0;
      }
    }
  }
  printf("1\n%d\n", n);//坑，不加这句，素数会没有输出
}
