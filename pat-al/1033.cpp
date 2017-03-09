/**
 * pat-al-1033
 * 2017-02-05
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct STA
{
  double price;
  double dist;
};
bool cmp(STA a, STA b)
{
  return a.dist < b.dist;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int maxC, maxDist, avgDis, n;
  scanf("%d%d%d%d", &maxC, &maxDist, &avgDis, &n);
  vector<STA> sta(n+1);
  sta[0].price = 0;
  sta[0].dist = maxDist;
  for(int i = 1;i <= n;i++)
  {
    scanf("%lf%lf", &sta[i].price, &sta[i].dist);
  }
  sort(sta.begin(), sta.end(), cmp);
  double tmpDist = 0, maxCanReach = 0, tmpPrice = 0, totalPrice = 0, tmpC = 0;//tmpC是目前油箱里的油量
  if(sta[0].dist != 0)
  {
    printf("The maximum travel distance = 0.00\n");
    return 0;
  }
  else
    tmpPrice = sta[0].price;
  while(tmpDist < maxDist)
  {
    maxCanReach = tmpDist + maxC * avgDis;
    double minPrice = INF, minPriceDist;
    int flagFind = 0;
    for(int i = 1;i <= n && sta[i].dist <= maxCanReach;i++)
    {
      if(sta[i].dist <= tmpDist)
        continue;
      if(sta[i].price < tmpPrice)
      {
        //printf("sta.price = %.2lf, tmpPrice = %.2lf\n", sta[i].price, tmpPrice);
        totalPrice += ((sta[i].dist - tmpDist) / avgDis - tmpC) * tmpPrice;
        //printf("falgFind, totalPrice = %.2lf, tmpDist = %d\n", totalPrice, (int)tmpDist);
        tmpC = 0;
        tmpPrice = sta[i].price;
        tmpDist = sta[i].dist;
        flagFind = 1;
        break;
      }
      if(sta[i].price < minPrice)
      {
        minPrice = sta[i].price;
        minPriceDist = sta[i].dist;
        //printf("minPriceDist = %d, minPrice = %.2lf\n", (int)minPriceDist, minPrice);
      }
    }
    if(flagFind == 0 && minPrice == INF)
    {
      printf("The maximum travel distance = %.2lf\n", maxCanReach);
      return 0;
    }
    if(flagFind == 0 && minPrice != INF)
    {
      totalPrice += (maxC - tmpC) * tmpPrice;
      tmpC = maxC - (minPriceDist - tmpDist) / avgDis;
      //printf("totalPrice = %.2lf, tmpDist = %d\n", totalPrice, (int)tmpDist);
      tmpPrice = minPrice;
      tmpDist = minPriceDist;
      //printf("minPriceDist = %d, minPrice = %.2lf\n", (int)minPriceDist, minPrice);
    }
  }
  printf("%.2lf\n", totalPrice);
  return 0;
}
