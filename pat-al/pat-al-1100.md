1100.Mars Numbers (20)...to be continued...

pat-al-1100

2017-02-20

- 之前在乙级做过一遍，但是写的特别麻烦，这次参考书上优化了一下
- 因为数的范围不大，选择使用map工具以及打表的方式
- atof：字符串转换成浮点数，在stdlib.h中
- c_str()：从string转成char数组

```c++
/**
 * pat-al-1100
 * 2017-02-20
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<map>
#include<string>
using namespace std;
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string num2Str[170];
map<string, int> str2Num;
void init()
{
  for(int i = 0;i < 13;i++)
  {
    num2Str[i] = unitDigit[i];//个位0~12，十位0
    str2Num[unitDigit[i]] = i;
    num2Str[i*13] = tenDigit[i];//个位0，十位0~12
    str2Num[tenDigit[i]] = i*13;
  }
  for(int i = 1;i < 13;i++)//十位
  {
    for(int j = 1;j < 13;j++)//个位
    {
      string str = tenDigit[i] + " " + unitDigit[j];
      num2Str[i*13+j] = str;
      str2Num[str] = i*13+j;
    }
  }
}
int main()
{
  init();
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d\n", &n);
  for(int i = 0;i < n;i++)
  {
    string str;
    getline(cin, str);
    //cout << "str = " << str << endl;
    if(str[0] >= '0' && str[0] <= '9')
    {
      int num = (int)atof(str.c_str());
      cout << num2Str[num] << endl;
    }
    else
      cout << str2Num[str] << endl;
  }
  return 0;
}
```
-TBC-
