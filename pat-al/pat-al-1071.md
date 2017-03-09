1071.Speech Patterns (25)...to be continued...

pat-al-1071

2017-02-20

- string是可以拼接的
- map的迭代器it使用: it->first, it->second
- check一下字符是否合法（是否是数字或者字母），合法就拼接到word上，直到读入一个非字母数字的字符
- 写一个循环把不合法的字符跳掉
- 坑：别忘了把大写转换成小写
- 似乎不需要判断word是否非空，也可能是因为测试点不全面吗？（还不太明白……）

```c++
/**
 * pat-al-1071
 * 2017-02-20
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
bool check(char c)
{
  if(c >= '0' && c <= '9')
    return true;
  if(c >= 'a' && c <= 'z')
    return true;
  if(c >= 'A' && c <= 'Z')
    return true;
  return false;
}
int main()
{
  freopen("in.txt", "r", stdin);
  map<string, int> count;
  string str;
  getline(cin, str);
  int i = 0;
  while(i < str.length())
  {
    string word;
    while(i < str.length() && check(str[i]) == true)
    {
      if(str[i] >= 'A' && str[i] <= 'Z')
        str[i] += 32;
      word += str[i++];
    }
    if(word != "")
      count[word]++;
    while(i < str.length() && check(str[i]) == false)
      i++;
  }
  int max = 0;
  string result;
  for (map<string, int>::iterator it = count.begin();it != count.end();it++)
  {
    if(it->second > max)
    {
      max = it->second;
      result = it->first;
    }
  }
  cout << result << " " << max << endl;
  return 0;
}
```
-TBC-
