pat-bl-1061

2017-01-24

- 和选择题一个套路，但更简单

```c
/**
 * pat-bl-1061
 * 2017-01-24
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
struct QUE
{
  int score;
  int ans;
};
int main()
{
  freopen("in.txt", "r", stdin);
  int numStu, numQue;
  scanf("%d %d", &numStu, &numQue);
  //printf("%d %d\n", numStu, numQue);
  struct QUE que[numQue];
  for(int i = 0;i < numQue;i++)
  {
    scanf("%d", &que[i].score);
    //printf("que[%d].score = %d\n", i, que[i].score);
  }
  for(int i = 0;i < numQue;i++)
  {
    scanf("%d", &que[i].ans);
    //printf("que[%d].ans = %d\n", i, que[i].ans);
  }
  for(int i = 0;i < numStu;i++)//i: 学生序号
  {
    int score = 0;
    for(int j = 0;j < numQue;j++)//j: 题目序号
    {
      int tmp;
      scanf("%d", &tmp);
      //printf("tmp = %d\n", tmp);
      if(tmp == que[j].ans)
      {
        //printf("que[%d].ans = %d\n", j, tmp);
        score += que[j].score;
      }
    }
    printf("%d\n", score);
  }
}
```
-FIN-
