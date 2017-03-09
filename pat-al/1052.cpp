/**
 * pat-al-1052
 * 2017-02-26
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
using namespace std;
struct NODE
{
  int addr;
  int key;
  int next;
  int flagValid;
}newNode, list[100010];
bool cmp(NODE a, NODE b)
{
  if(a.flagValid == 0 || b.flagValid == 0)
    return a.flagValid > b.flagValid;
  else
    return a.key < b.key;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, start, tmp;
  scanf("%d%d", &n, &start);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &tmp);
    list[tmp].addr = tmp;
    scanf("%d%d", &list[tmp].key, &list[tmp].next);
    list[tmp].flagValid = 0;
  }
  int cnt = 0, index = start;
  while(index != -1)
  {
    list[index].flagValid = 1;
    cnt++;
    index = list[index].next;
  }
  if(cnt == 0)//注意，要判断全部节点都无效的情况
  {
    printf("0 -1\n");//大坑，不能输出：0 0
    return 0;
  }
  sort(list, list+100010, cmp);
  for(int i = 0;i < cnt-1;i++)
  {
    list[i].next = list[i+1].addr;
  }
  list[cnt-1].next = -1;
  printf("%d %05d\n", cnt, list[0].addr);
  for(int i = 0;i < cnt;i++)
  {
    if(list[i].next != -1)
      printf("%05d %d %05d\n", list[i].addr, list[i].key, list[i].next);
    else
      printf("%05d %d -1\n", list[i].addr, list[i].key);
  }
  return 0;
}
