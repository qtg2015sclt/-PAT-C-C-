pat-al-1069

2017-01-27

- 乙级就写过这题，这次再写就优化了一下
- 排序直接使用了sort
- 使用sprintf和sscanf进行字符串和数字之间的转换
- 坑见注释

```c++
/**
 * pat-al-1069
 * 2017-01-27
 * Cpp version
 * Auhtor: fengLian_s
 */
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp1(char a, char b)
{
  return a > b;
}
bool cmp2(char a, char b)
{
  return a < b;
}
int main()
{
  int n;
  scanf("%d", &n);
  char num[5];//坑：4的话会出错
  sprintf(num, "%04d", n);//坑：注意格式控制
  //printf("n = %d\n", n);
  do {
    int max, min;
    sprintf(num, "%04d", n);
    //printf("n = %d\n", n);
    if(num[0] == num[1] && num[0] == num[2] && num[0] == num[3])
    {
      printf("%d - %d = 0000\n", n, n);
      return 0;
    }
    sort(num, num+4, cmp1);
    //printf("num = %s\n", num);
    sscanf(num, "%d", &max);
    //cout << "max = " << max << endl;
    sort(num, num+4, cmp2);
    sscanf(num, "%d", &min);
    //cout << "min = " << min << endl;
    n = max - min;
    printf("%04d - %04d = %04d\n", max, min, n);
  } while(n != 6174);
}
```
-FIN-
