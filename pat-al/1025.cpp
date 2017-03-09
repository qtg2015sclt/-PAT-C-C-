/**
 * pat-al-1025
 * 2017-02-21
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#define MAX 30010
using namespace std;
struct TESTEE
{
  long long id;
  int score;
  int location;
  int rank[2];//0: final rank;1: local rank
}testee[MAX];
bool cmp(TESTEE a, TESTEE b)
{
  if(a.score != b.score)
    return a.score > b.score;
  else
    return a.id < b.id;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, k;
  scanf("%d", &n);
  int cnt = 0, start, end;
  for(int i = 1;i <= n;i++)
  {
    scanf("%d", &k);
    start = cnt;
    for(int j = 0;j < k;j++)
    {
      scanf("%lld%d", &testee[cnt].id, &testee[cnt].score);
      testee[cnt].location = i;
      cnt++;
    }
    end = cnt;
    sort(testee+start, testee+end, cmp);
    for(int j = start;j < end;j++)
    {
      if(j != start && testee[j].score == testee[j-1].score)
      {
        testee[j].rank[1] = testee[j-1].rank[1];
      }
      else
      {
        testee[j].rank[1] = j - start + 1;
        //printf("j = %d, rank = %d\n", j, testee[j].rank[1]);
      }
    }
  }
  sort(testee, testee+cnt, cmp);
  for(int i = 0;i < cnt;i++)
  {
    if(i != 0 && testee[i].score == testee[i-1].score)
      testee[i].rank[0] = testee[i-1].rank[0];
    else
      testee[i].rank[0] = i + 1;
  }
  printf("%d\n", cnt);
  for(int i = 0;i < cnt;i++)
  {
    printf("%013lld %d %d %d\n", testee[i].id, testee[i].rank[0], testee[i].location, testee[i].rank[1]);
  }
  return 0;
}
