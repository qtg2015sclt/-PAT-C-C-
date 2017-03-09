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
