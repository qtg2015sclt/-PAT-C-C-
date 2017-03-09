/**
 * pat-bl-1060
 * 2017-01-23
 * Cpp version
 * Author: fengLian_s
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int a, int b)
{
  return a > b;
}
int main()
{
  int n;
  cin >> n;
  vector<int> v(n+1);
  for(int i = 1;i <= n;i++)
  {
    cin >> v[i];
  }
  //想到怎么做这题就很简单。先按从大到小排个序，所求的e一定是使v中保存的骑车距离比其下标要大的那个下标（最大的），从前向后遍历一下就好了
  //想不清楚自己在草稿纸上写一下找个规律
  sort(v.begin()+1, v.end(), cmp);//第0位是空，注意不排第0位
  // for(int i = 1;i <= n;i++)
  // {
  //   cout << v[i] << " ";
  // }
  // cout << endl;
  int i = 1;
  while(v[i] > i)
  {
    i++;
  }
  cout << i-1 << endl;
}
