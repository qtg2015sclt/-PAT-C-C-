/**
 * pat-al-1034
 * 2017-02-04
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#define MAX 2003//坑……我还以为是1000，导致段错误
using namespace std;
int k;
int maxNumberOfPeople = 1;
int visited[MAX], weight[MAX], e[MAX][MAX];
map<string, int> str2int;
map<int, string> int2str;
map<string, int> result;
int string2int(string s)
{
  if(str2int[s] == 0)//还未放入映射中
  {
    str2int[s] = maxNumberOfPeople;
    int2str[maxNumberOfPeople] = s;
    //cout << s << ": " << maxNumberOfPeople << endl;
    return maxNumberOfPeople++;
  }
  else
    return str2int[s];
}
void dfs(int u, int &head, int &numberOfMember, int &totalWeight)
{
  visited[u] = 1;
  numberOfMember++;
  if(weight[u] > weight[head])
    head = u;
  for(int v = 1;v < maxNumberOfPeople;v++)
  {
    if(e[u][v] != 0)//坑：和下面的visited必须要分开判断，此处判断的是是否有边没有加入总权重
    {
      totalWeight += e[u][v];
      //printf("e[%d][%d] = %d\n", u, v, e[u][v]);
      e[u][v] = e[v][u] = 0;//坑，一条路只能加一遍
      if(visited[v] == 0)//坑：visited判断的时候是否继续深搜
        dfs(v, head, numberOfMember, totalWeight);
    }
  }
}
int main()
{
  int n;
  scanf("%d%d", &n, &k);
  for(int i = 0;i < n;i++)
  {
    string s1, s2;
    int w;
    cin >> s1 >> s2 >> w;
    int id1, id2;
    id1 = string2int(s1);
    id2 = string2int(s2);
    weight[id1] += w;
    weight[id2] += w;
    e[id1][id2] += w;
    e[id2][id1] += w;//坑，不用+=的话会被新的权值覆盖
  }
  //solve:
  for(int i = 1;i < maxNumberOfPeople;i++)
  {
    if(visited[i] == 0)
    {
      int head = i, totalWeight = 0, numberOfMember = 0;
      dfs(i, head, numberOfMember, totalWeight);
      //cout << "head = " << head << ", numberOfMember = " << numberOfMember << ", totalWeight = " << totalWeight << endl;
      if(numberOfMember > 2 && totalWeight > k)
        result[int2str[head]] = numberOfMember;
    }
  }
  //output:
  printf("%lu\n", result.size());
  for(map<string, int>::iterator it = result.begin();it != result.end();it++)
    cout << it->first << " " << it->second << endl;
  return 0;
}
