/**
 * pat-al-1095
 * 2017-02-22
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#define MAX 10010
using namespace std;
struct RECORD
{
  string id;
  int time;//以second为单位
  bool flagIn;
}input[MAX], valid[MAX];
int convertTime(int hh, int mm, int ss)
{
  return hh*3600 + mm*60 + ss;
}
bool cmpById(RECORD a, RECORD b)
{
  if(a.id !=  b.id)
    return a.id < b.id;
  else
    return a.time < b.time;
}
bool cmpByTime(RECORD a, RECORD b)
{
  return a.time < b.time;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, k;
  int hh, mm, ss;
  char state[5];
  scanf("%d%d", &n, &k);
  for(int i = 0;i < n;i++)
  {
    cin >> input[i].id;
    scanf("%d:%d:%d %s", &hh, &mm, &ss, state);
    input[i].time = convertTime(hh, mm, ss);
    if(state[0] == 'i')
      input[i].flagIn = true;
    else
      input[i].flagIn = false;
  }
  sort(input, input+n, cmpById);
  // for(int i = 0;i < n;i++)
  // {
  //   cout << input[i].id;
  //   printf(": time = %d, flagIn = %d\n", input[i].time, input[i].flagIn);
  // }
  map<string, int> parkTime;
  int cnt = 0, maxTime = 0;
  for(int i = 0;i < n-1;i++)
  {
    if(input[i].id == input[i+1].id && input[i].flagIn == true && input[i+1].flagIn == false)
    {
      valid[cnt++] = input[i];
      valid[cnt++] = input[i+1];
      parkTime[input[i].id] += (input[i+1].time - input[i].time);
      if(maxTime < parkTime[input[i].id])
        maxTime = parkTime[input[i].id];
    }
  }
  sort(valid, valid+cnt, cmpByTime);
  // for(int i = 0;i < cnt;i++)
  // {
  //   cout << valid[i].id;
  //   printf(": time = %d, flagIn = %d\n", valid[i].time, valid[i].flagIn);
  // }
  int index = 0, numCar = 0;
  for(int i = 0;i < k;i++)
  {
    scanf("%d:%d:%d", &hh, &mm, &ss);
    int queryTime = convertTime(hh, mm, ss);
    while(index < cnt && valid[index].time <= queryTime)
    {
      if(valid[index].flagIn == true)
        numCar++;
      else
        numCar--;
      index++;
    }
    printf("%d\n", numCar);
  }
  for(map<string, int>::iterator it = parkTime.begin();it != parkTime.end();it++)
  {
    if(it->second == maxTime)
      cout << it->first << " ";
  }
  printf("%02d:%02d:%02d\n", maxTime/3600, maxTime%3600/60, maxTime%60);
  return 0;
}
