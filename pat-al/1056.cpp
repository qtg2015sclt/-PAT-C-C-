/**
 * pat-al-1056
 * 2017-02-27
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<queue>
#define MAX 1010
using namespace std;
struct MOUSE
{
  int weight;
  int rank;
}mouse[MAX];
int main()
{
  freopen("in.txt", "r", stdin);
  int np, ng;
  scanf("%d%d", &np, &ng);
  for(int i = 0;i < np;i++)
  {
    scanf("%d", &mouse[i].weight);
  }
  int index;
  queue<int> q;
  for(int i = 0;i < np;i++)
  {
    scanf("%d", &index);
    q.push(index);
  }
  int tmp = np, group;
  while(q.size() != 1)
  {
    if(tmp % ng == 0)
      group = tmp / ng;
    else
      group = tmp / ng + 1;
    for(int i = 0;i < group;i++)
    {
      int max = q.front();
      for(int j = 0;j < ng;j++)
      {
        if(i * ng + j >= tmp)
          break;
        int front = q.front();
        if(mouse[front].weight > mouse[max].weight)
          max = front;
        mouse[front].rank = group + 1;
        q.pop();
      }
      q.push(max);
    }
    tmp = group;
  }
  mouse[q.front()].rank = 1;
  printf("%d", mouse[0].rank);
  for(int i = 1;i < np;i++)
  {
    printf(" %d", mouse[i].rank);
  }
  putchar('\n');
  return 0;
}
