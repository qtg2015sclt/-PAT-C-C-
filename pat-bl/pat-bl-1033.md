pat-bl-1033

2017-01-21

- 并不难，就是在大写多判断一个'+'就好了
- 注意：题目说第二个串一定不空，那么第一个串有可能为空，不能用scanf读取，要用fgets，不然有个测试点过不了。
- 一个还没搞清楚的问题：最后一个测试点会运行超时。改成一个一个读直到文件流结束就正确了。
- **一个启发：如果遇到出错和超时，但是认为代码没问题的时候，改变输入的方法试一试，说不定就过了。**

```c
/**
 * pat-bl-1033
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>

int main()
{
  //test:
  // char tmp = '_';
  // printf("%c: %d\n", tmp, tmp);
  // tmp = ',';
  // printf("%c: %d\n", tmp, tmp);
  // tmp = '.';
  // printf("%c: %d\n", tmp, tmp);
  // tmp = '-';
  // printf("%c: %d\n", tmp, tmp);
  // tmp = '+';
  // printf("%c: %d\n", tmp, tmp);
  //test end
  freopen("in.txt", "r", stdin);
  int hs[128] = {0};//键位坏掉的标志，默认没坏
  char str1[128], ch;
  fgets(str1, sizeof(str1), stdin);//坑点：第一个串可能为空，不能用scanf读。有一个测试点测的就是这个。
  str1[strlen(str1) - 1] = '\0';
  //printf("strlen(str1) = %lu\n", strlen(str1));
  //scanf("%s", str2);
  //printf("%s %s\n", str1, str2);
  for(int i = 0;i < strlen(str1);i++)
  {
    hs[str1[i]] = 1;//将坏掉的键标志置1
    if(str1[i] >= 'A' && str1[i] <= 'Z')
      hs[str1[i] + 32] = 1;//注意：如果这个字母是坏键，要将小写字母也置1
  }
  while(scanf("%c", &ch) != EOF)//一个还没搞清楚的问题：虽然说第二个串不是空串，..
  {//..但如果不写成判断文件结束（之前用的是跟在第一个串后一次读入），就过不了最后一个测试点
    if(hs[ch] == 0)
    {
      if(ch >= 'A' && ch <= 'Z' && hs['+'] == 1)//大写字母要额外判断'+'键
        continue;
      putchar(ch);
    }
  }
}
```
-FIN-
