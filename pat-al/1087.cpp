/**
 * pat-al-1087
 * 2017-02-03
 * Cpp version
 * Author: fengLian_s
 */
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#define MAX 202
#define INF 0x3f3f3f3f
using namespace std;
map<string, int> m1;
map<int, string> m2;
int pre[MAX] = {-1};
void printRoute(int city)
{
  if(pre[city] != -1)
    printRoute(pre[city]);
  else//找到起始点，直接返回
    return;
  cout << "->" << m2[city];
}
int main()
{
  int n, k, start = 0, end;
  int e[MAX][MAX], happiness[MAX] = {0}, visited[MAX], cost[MAX];
  int numOfDiffRoutes[MAX], numOfCities[MAX], amountOfHappiness[MAX];
  //memset(e, 0x3f, sizeof(e));
  fill(e[0], e[0]+MAX*MAX, INF);//尝试一下fill
  fill(visited, visited+MAX, 0);
  fill(cost, cost+MAX, INF);
  string tmp;
  scanf("%d %d", &n, &k);
  cin >> tmp;
  //printf("%d %d ", n, k);
  //cout << tmp << endl;
  m1[tmp] = 0;
  m2[0] = tmp;
  for(int i = 1;i < n;i++)
  {
    cin >> tmp;
    m1[tmp] = i;
    m2[i] = tmp;
    scanf("%d", &happiness[i]);
    if(tmp == "ROM")
    {
      end = i;
      //cout << "end = " << end << endl;
    }
    //cout << m2[i] << ": " << happiness[i] << endl;
  }
  for(int i = 0;i < k;i++)
  {
    string tmpC1, tmpC2;
    int tmpCost;
    cin >> tmpC1 >> tmpC2 >> tmpCost;
    e[m1[tmpC1]][m1[tmpC2]] = tmpCost;
    e[m1[tmpC2]][m1[tmpC1]] = tmpCost;
  }
  //dijkstra:
  cost[0] = 0;
  numOfDiffRoutes[0] = 1;
  numOfCities[0] = 0;
  amountOfHappiness[0] = 0;
  while(1)
  {
    int u, minCost = INF;
    for(int i = 0;i < n;i++)
    {
      if(visited[i] == 0 && cost[i] < minCost)
      {
        minCost = cost[i];
        u = i;
      }
    }
    if(minCost == INF)
      break;
    visited[u] = 1;
    for(int v = 0;v < n;v++)
    {
      if(visited[v] == 0 && cost[v] > cost[u] + e[u][v])
      {
        cost[v] = cost[u] + e[u][v];
        numOfDiffRoutes[v] = numOfDiffRoutes[u];
        amountOfHappiness[v] = amountOfHappiness[u] + happiness[v];
        numOfCities[v] = numOfCities[u] + 1;
        pre[v] = u;
      }
      else if(visited[v] == 0 && cost[v] == cost[u] + e[u][v])
      {
        numOfDiffRoutes[v] += numOfDiffRoutes[u];
        if(amountOfHappiness[v] < amountOfHappiness[u] + happiness[v])
        {
          amountOfHappiness[v] = amountOfHappiness[u] + happiness[v];
          numOfCities[v] = numOfCities[u] + 1;
          pre[v] = u;
        }
        else if(amountOfHappiness[v] == amountOfHappiness[u]+happiness[v] && numOfCities[v] > (numOfCities[u]+1))
        {//幸福感总量相同的时候，通过的城市越少，平均值越高
          numOfCities[v] = numOfCities[u] + 1;
          pre[v] = u;
        }
      }
    }
  }
  //output:
  printf("%d %d %d %d\n", numOfDiffRoutes[end], cost[end], amountOfHappiness[end], amountOfHappiness[end]/numOfCities[end]);
  cout << m2[start];
  printRoute(end);
  putchar('\n');
  return 0;
}
