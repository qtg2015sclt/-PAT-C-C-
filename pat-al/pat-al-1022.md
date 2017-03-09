1022.Digital Library (30)...to be continued...

pat-al-1022

2017-02-20

- 关于map的用法：如果是一一对应关系，直接令mp[index] = content就可以；如果是一对多，就要用到mp[index].insert
- getline的用法：getline(cin, input)。别忘了如果前一个输入是scanf，要读掉换行
- map和set的方法中都有find
- 判断一个查询内容是否存在可以用：if(mp.find(queryContent) == mp.end())，或者if(mp.count(queryContent) == 0)，或者if(mp[queryContent].size() == 0)

```c++
/**
 * pat-al-1022
 * 2017-02-20
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;
void query(map<string, set<int> >& mp, string& queryContent)
{
  if(mp[queryContent].size() == 0)
  {
    printf("Not Found\n");
  }
  else
  {
    for(set<int>::iterator it = mp[queryContent].begin();it != mp[queryContent].end();it++)
    {
      printf("%07d\n", *it);
    }
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, m, id, type;
  string title, author, key, pub, year;
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d\n", &id);
    getline(cin, title);
    //cout << "title = " << title << endl;
    mpTitle[title].insert(id);
    getline(cin, author);
    //cout << "author = " << author << endl;
    mpAuthor[author].insert(id);
    while(cin >> key)
    {
      char c = getchar();
      mpKey[key].insert(id);
      //cout << "key = " << key << endl;
      if(c == '\n')
        break;
    }
    getline(cin, pub);
    //cout << "pub = " << pub << endl;
    mpPub[pub].insert(id);
    getline(cin, year);
    //cout << "year = " << year << endl;
    mpYear[year].insert(id);
  }
  scanf("%d", &m);
  string queryContent;
  for(int i = 0;i < m;i++)
  {
    scanf("%d: ", &type);
    getline(cin, queryContent);
    printf("%d: ", type);
    cout << queryContent << endl;
    if(type == 1)
      query(mpTitle, queryContent);
    else if(type == 2)
      query(mpAuthor, queryContent);
    else if(type == 3)
      query(mpKey, queryContent);
    else if(type == 4)
      query(mpPub, queryContent);
    else
      query(mpYear, queryContent);
  }
  return 0;
}
```
-TBC-
