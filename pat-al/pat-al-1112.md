1112.Stucked Keyboard (20)

pat-al-1112

2017-01-28

- 注意1：输出坏键的时候要按照遇到的顺序，而非哈希表的顺序
- 注意2：如果一个键被正常输出过，那么就算出现了k次也不是坏键
- 坑：总觉得是3，其实是k……
- 一点启发：读完题后思考的越全面，一边来说完成的越快，因为不需要一遍一遍去试错了。

```c++
/**
 * pat-al-1112
 * 2017-01-28
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;
int main()
{
  freopen("in.txt", "r", stdin);
  int k;
  scanf("%d\n", &k);//注意接下来用gets读取一定要加'\n'
  char str[1002];
  int hs[128] = {0};//0表示未遇到该字符，1表示已遇到且未被卡住，2表示目前认为被卡住。一旦置位1就不能更改了
  gets(str);
  int i;
  for(i = 0;i <= strlen(str)-k;)
  {
    //printf("str[%d] = %c\n", i, str[i]);
    if(hs[str[i]] == 1)//每个字符先检验一下，是未被卡住的键就continue去检查下一个
    {
      i++;
      continue;
    }
    int flagStucked = 1;
    char ch = str[i];
    for(int j = 1;j < k;j++)
    {
      if(ch != str[i+j])//说明未卡住
      {
        flagStucked = 0;
        break;
      }
    }
    if(flagStucked == 0)
    {
      hs[str[i]] = 1;
      i++;
    }
    else//卡住了
    {
      hs[str[i]] = 2;
      i += k;//跳过目前被认为是卡住的键。不写这句会出错。坑，总觉得是3，其实应该写k。
    }
  }
  for(;i < strlen(str);i++)//如果还有剩下的键的话，是不可能被卡住的了
  {
    hs[str[i]] = 1;
  }
  //output:
  set<char> printed;
  for(int i = 0;i < strlen(str);i++)
  {
    if(hs[str[i]] == 2 && printed.find(str[i]) == printed.end())//是坏键且没被打印过。注意set的find的判定
    {
      printf("%c", str[i]);
      printed.insert(str[i]);
    }
  }
  putchar('\n');
  for(int i = 0;i < strlen(str);)
  {
    if(hs[str[i]] == 2)
    {
      printf("%c", str[i]);
      i += k;
    }
    else
    {
      printf("%c", str[i]);
      i++;
    }
  }
  putchar('\n');
  return 0;
}
```
-FIN-
