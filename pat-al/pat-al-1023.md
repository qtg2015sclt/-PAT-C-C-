pat-al-1023

2017-01-26

- 注意没法用long long写，必须用字符串处理
- 坑见注释

```c
/**
 * pat-al-1023
 * 2017-01-26
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
int main()
{
  //test:
  // int a = 123456789;
  // a *= 2;
  // printf("a * 2 = %d\n", a);
  // a *= 2;
  // printf("a * 2 = %d\n", a);
  //test end
  freopen("in.txt", "r", stdin);
  char num[22];//用long long不行，后三个测试点过不了，应该是位数超限了
  scanf("%s", num);
  char newNum[22];
  newNum[strlen(num)] = '\0';//坑：不用long long，换成字符串处理之后，如果不加这句，后三个点能过，前面的又过不了了。不懂为什么后三个点能过？
  int tmpNum, c = 0;//c是进位
  int hs1[10] = {0}, hs2[10] = {0};
  for(int i = strlen(num)-1;i >= 0;i--)
  {
    tmpNum = (num[i] - '0') * 2 + c;
    c = tmpNum / 10;//更新进位的值
    newNum[i] = tmpNum % 10 + '0';
    hs1[num[i] - '0']++;
    hs2[newNum[i] - '0']++;
  }
  if(c > 0)//对最高位进位的特殊处理
    hs2[c]++;
  int flagFail = 0;
  for(int i = 0;i < 10;i++)
  {
    if(hs1[i] != hs2[i])
    {
      flagFail = 1;
      break;
    }
  }
  if(flagFail)
    printf("No\n");
  else
    printf("Yes\n");
  if(c > 0)
    printf("%d", c);
  printf("%s\n", newNum);
  return 0;
}
```
-FIN-
