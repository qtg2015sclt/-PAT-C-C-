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
