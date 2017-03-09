pat-bl-1047

2017-01-22

- 还是那个套路解法，做这么多太熟了

```c
/**
 * pat-bl-1047
 * 2017-01-22
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>

int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int tmpTeam, tmpPerson, tmpScore;
  int score[1001] = {0};//以学校编号为下标，存储内容为总分
  for(int i = 0;i < n;i++)
  {
    scanf("%d-%d %d", &tmpTeam, &tmpPerson, &tmpScore);//虽然读入个人编号，但其实在本题是不需要的
    score[tmpTeam] += tmpScore;
  }
  int maxTeam = 1, maxScore = score[1];
  for(int i = 2;i < 1001;i++)
  {
    if(maxScore < score[i])
    {
      maxScore = score[i];
      maxTeam = i;
    }
  }
  printf("%d %d\n", maxTeam, maxScore);
}
```
-FIN-
