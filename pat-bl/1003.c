/**
 * pat-bl-1003
 * 2017-01-24
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  //个人理解：基本形式是PAT，然后P和T之间可以包含大于等于一个A，T之后A的个数一定要是P之前A的个数的整数倍
  //然而是不对的，参考了别人的分析，自己又在草稿纸上写了写，发现是这样的：如果说A的个数分别是a,b,c,满足a*b=c的关系
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  char str[102];
  for(int i = 0;i < n;i++)
  {
    int flagP = 0, flagT = 0, flagFail = 0;
    int numA1 = 0, numA2 = 0, numA3 = 0;
    scanf("%s", str);
    for(int j = 0;j < strlen(str);j++)
    {
      if(str[j] == 'P' && flagP == 0)
        flagP = 1;
      else if(str[j] == 'T' && flagT == 0)
        flagT = 1;
      else if(str[j] == 'A' && flagP == 0 && flagT == 0)
        numA1++;
      else if(str[j] == 'A' && flagP == 1 && flagT == 0)
        numA2++;
      else if(str[j] == 'A' && flagP == 1 && flagT == 1)
        numA3++;
      else
      {
        flagFail = 1;
        break;
      }
    }
    if(flagFail == 0)
    {
      if(numA2 > 0 && numA1 * numA2 == numA3 && flagT == 1)//大坑：如果没有判断T是否出现，那么PA也能通过，第二个测试点测这个。这坑主要是因为我的写法有问题……
        printf("YES\n");
      else
        printf("NO\n");
    }
    else
      printf("NO\n");
  }
}
