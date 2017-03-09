1036.Boys vs Girls (25)

pat-al-1036

2017-02-24

- 每次读入新数据，根据性别和分数来判断是否更新、更新给哪个

```c++
/**
 * pat-al-1036
 * 2017-02-24
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct STU
{
  char name[15];
  char id[15];
  int score;
}newStu, maleStu, femaleStu;
int main()
{
  maleStu.score = 101;
  femaleStu.score = -1;
  freopen("in.txt", "r", stdin);
  int n;
  char gender;
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
  {
    scanf("%s %c %s %d", newStu.name, &gender, newStu.id, &newStu.score);
    if(gender == 'M' && newStu.score < maleStu.score)
      maleStu = newStu;
    else if(gender == 'F' && newStu.score > femaleStu.score)
      femaleStu = newStu;
  }
  if(femaleStu.score != -1)
    printf("%s %s\n", femaleStu.name, femaleStu.id);
  else
    printf("Absent\n");
  if(maleStu.score != 101)
    printf("%s %s\n", maleStu.name, maleStu.id);
  else
    printf("Absent\n");
  if(femaleStu.score == -1 || maleStu.score == 101)
    printf("NA\n");
  else
    printf("%d\n", femaleStu.score - maleStu.score);
  return 0;
}
```
-FIN-
