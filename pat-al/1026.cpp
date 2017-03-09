/**
 * pat-al-1026
 * 2017-02-22
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int n, hh, mm, ss, k, m, tmpTableId;
struct TABLE
{
  int endTime;
  int numServe;
  int isVIP;
}table[110];
struct PLAYER
{
  int comeTime;
  int serveTime;
  int lastTime;
  int isVIP;
}newPlayer;
vector<PLAYER> player;
bool cmpByComeTime(PLAYER a, PLAYER b)
{
  return a.comeTime < b.comeTime;
}
bool cmpByServeTime(PLAYER a, PLAYER b)
{
  return a.serveTime < b.serveTime;
}
int convertTime(int hh, int mm, int ss)
{
  return hh*3600 + mm*60 + ss;
}
int nextVipPlayer(int pVip)
{
  pVip++;
  while(pVip < player.size() && player[pVip].isVIP == 0)
    pVip++;
  return pVip;
}
void allocTable(int pID, int tID)
{
  if(player[pID].comeTime <= table[tID].endTime)
    player[pID].serveTime = table[tID].endTime;
  else
    player[pID].serveTime = player[pID].comeTime;
  table[tID].endTime = player[pID].serveTime + player[pID].lastTime;
  table[tID].numServe++;
}
int main()
{
  freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  int startTime = convertTime(8, 0, 0);
  int endTime = convertTime(21, 0, 0);
  for(int i = 0;i < n;i++)
  {
    scanf("%d:%d:%d", &hh, &mm, &ss);
    newPlayer.comeTime = convertTime(hh, mm, ss);
    scanf("%d%d", &newPlayer.lastTime, &newPlayer.isVIP);
    if(newPlayer.comeTime >= endTime)//关门了才来，不记录该球员
      continue;
    newPlayer.serveTime = endTime;//开始被服务时间初始化为21点
    newPlayer.lastTime = newPlayer.lastTime <= 120 ? newPlayer.lastTime * 60 : 7200;
    player.push_back(newPlayer);
  }
  scanf("%d%d", &k, &m);
  for(int i = 1;i <= k;i++)//注意是1~k
  {
    table[i].endTime = startTime;
    table[i].numServe = table[i].isVIP = 0;
  }
  for(int i = 0;i < m;i++)
  {
    scanf("%d", &tmpTableId);
    table[tmpTableId].isVIP = 1;
  }
  sort(player.begin(), player.end(), cmpByComeTime);
  // for(int i = 0;i < n;i++)
  // {
  //   printf("%d %d %d\n", player[i].comeTime, player[i].lastTime, player[i].isVIP);
  // }
  int index = 0, pVip = -1;//pVip指向当前最前的vip
  pVip = nextVipPlayer(pVip);
  while(index < player.size())
  {
    int minTable, minEndTime = convertTime(22, 0, 0);
    for(int i = 1;i <= k;i++)
    {
      if(table[i].endTime < minEndTime)
      {
        minEndTime = table[i].endTime;
        minTable = i;
      }
    }
    if(table[minTable].endTime >= endTime)//最早的球桌都已经超过关门时间了，剩下的球员就不服务了
      break;
    if(player[index].isVIP == 1 && index < pVip)
    {
      index++;//index是vip，但pVip > index，说明index已经在训练
      continue;
    }
    //球桌是否Vip、球员是否Vip，分四种情况
    if(table[minTable].isVIP == 1)
    {
      if(player[index].isVIP == 1)
      {
        allocTable(index, minTable);
        if(index == pVip)
          pVip = nextVipPlayer(pVip);
        index++;
      }
      else
      {
        if(pVip < player.size() && player[pVip].comeTime <= table[minTable].endTime)
        {
          allocTable(pVip, minTable);
          pVip = nextVipPlayer(pVip);
        }
        else{
          allocTable(index, minTable);
          index++;
        }
      }
    }
    else//球桌不是Vip
    {
      if(player[index].isVIP == 0)
      {
        allocTable(index, minTable);
        index++;
      }
      else//球员是Vip，大坑，要判断Vip球员来之前有没有Vip球桌空着，如果有，分到Vip球桌上，否则才会分到最早空闲的普通球桌上
      {
        int minVipTable = -1, minVipEndTime = convertTime(22, 0, 0);
        for(int i = 1;i <= k;i++)
        {
          if(table[i].isVIP == 1 && table[i].endTime < minVipEndTime)
          {
            minVipEndTime = table[i].endTime;
            minVipTable = i;
          }
        }
        if(minVipTable != -1 && table[minVipTable].endTime <= player[index].comeTime)
        {
          allocTable(index, minVipTable);
          if(index == pVip)
            pVip = nextVipPlayer(pVip);
          index++;
        }
        else
        {
          allocTable(index, minTable);
          if(index == pVip)
            pVip = nextVipPlayer(pVip);
          index++;
        }
      }
    }
  }
  sort(player.begin(), player.end(), cmpByServeTime);
  for(int i = 0;i < player.size() && player[i].serveTime < endTime;i++)
  {
    int t1 = player[i].comeTime;
    int t2 = player[i].serveTime;
    printf("%02d:%02d:%02d ", t1/3600, t1%3600/60, t1%60);
    printf("%02d:%02d:%02d ", t2/3600, t2%3600/60, t2%60);
    printf("%.0f\n", round((t2-t1)/60.0));
  }
  printf("%d", table[1].numServe);
  for(int i = 2;i <= k;i++)
  {
    printf(" %d", table[i].numServe);
  }
  putchar('\n');
  return 0;
}
