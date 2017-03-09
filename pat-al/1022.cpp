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
