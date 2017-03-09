1038.Recover the Smallest Number (30)

pat-al-1038

2017-02-08

- 参考了：[1038. Recover the Smallest Number (30)-PAT甲级真题](http://www.liuchuo.net/archives/2303)
- string中erase的用法：[C++中string erase函数的使用(转载)](http://www.cnblogs.com/ylwn817/articles/1967689.html)

```c++
/**
 * pat-al-1038
 * 2017-02-08
 * Cpp version
 * Author: fengLian_s
 */
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(string a, string b)
{
  return a+b < b+a;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  string str[10002];
  for(int i = 0;i < n;i++)
  {
    cin >> str[i];
  }
  sort(str, str+n, cmp);
  string s;
  for(int i = 0;i < n;i++)
  {
    s += str[i];
  }
  while(s.length() != 0 && s[0] == '0')
    s.erase(s.begin());
  if(s.length() == 0)
    cout << 0;
  else
    cout << s;
  putchar('\n');
}
```
-FIN-
