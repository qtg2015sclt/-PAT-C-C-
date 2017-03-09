/**
 *pat-bl-1015
 *2016-11-14
 *C++ version 1.0
 *注意：要细心点不要写错了
 */
#include<cstdio>
#include<algorithm>
using namespace std;
struct STU//考生的结构体
{
  int num;
  int score[3];//分别存放德分、才分、总分
};
bool cmp(STU s1, STU s2)//sort函数的比较函数
{
  if(s1.score[2] == s2.score[2])//总分相等按德分降序排
  {
    if(s1.score[0] == s2.score[0])//德分也相等按准考证号升序排
    {
      return s1.num < s2.num;
    }
    return s1.score[0] > s2.score[0];
  }
  return s1.score[2] > s2.score[2];
}
int main()
{
  int n, l, h;
  int tmpNum, tmpScore1, tmpScore2, i;
  STU stu1[100001], stu2[100001], stu3[100001], stu4[100001];
  int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
  //freopen("in.txt", "r", stdin);//样例的输入放在in.txt里了
  // int test = 10000001;
  // printf("test = %d\n", test);
  scanf("%d%d%d", &n, &l, &h);
  while(n--)
  {
    scanf("%d%d%d", &tmpNum, &tmpScore1, &tmpScore2);
    if(tmpScore1 < l || tmpScore2 < l)
    {
      //printf("%d %d %d\n",tmpNum, tmpScore1, tmpScore2);
      continue;
    }
    else if(tmpScore1 >= h && tmpScore2 >= h)//第一类：德才全尽
    {
      //printf("1:%d %d %d\n",tmpNum, tmpScore1, tmpScore2);
      stu1[cnt1].num = tmpNum;
      stu1[cnt1].score[0] = tmpScore1;
      stu1[cnt1].score[1] = tmpScore2;
      stu1[cnt1].score[2] = tmpScore1 + tmpScore2;
      cnt1++;
    }
    else if(tmpScore1 >= h && tmpScore2 < h)//第二类：德胜才
    {
      //printf("2:%d %d %d\n",tmpNum, tmpScore1, tmpScore2);
      stu2[cnt2].num = tmpNum;
      stu2[cnt2].score[0] = tmpScore1;
      stu2[cnt2].score[1] = tmpScore2;
      stu2[cnt2].score[2] = tmpScore1 + tmpScore2;
      cnt2++;
    }
    else if(tmpScore1 >= tmpScore2)//第三类：才德兼亡但德胜才
    {
      //printf("3:%d %d %d\n",tmpNum, tmpScore1, tmpScore2);
      stu3[cnt3].num = tmpNum;
      stu3[cnt3].score[0] = tmpScore1;
      stu3[cnt3].score[1] = tmpScore2;
      stu3[cnt3].score[2] = tmpScore1 + tmpScore2;
      cnt3++;
    }
    else//第四类：过线但不属于前三类的其余考生
    {
      //printf("4:%d %d %d\n",tmpNum, tmpScore1, tmpScore2);
      stu4[cnt4].num = tmpNum;
      stu4[cnt4].score[0] = tmpScore1;
      stu4[cnt4].score[1] = tmpScore2;
      stu4[cnt4].score[2] = tmpScore1 + tmpScore2;
      cnt4++;
    }
  }
  //putchar('\n');
  //sort:
  sort(stu1, stu1+cnt1, cmp);
  sort(stu2, stu2+cnt2, cmp);
  sort(stu3, stu3+cnt3, cmp);
  sort(stu4, stu4+cnt4, cmp);
  //output
  printf("%d\n", cnt1+cnt2+cnt3+cnt4);
  for(i = 0;i < cnt1;i++)
  {
    printf("%d %d %d\n", stu1[i].num, stu1[i].score[0], stu1[i].score[1]);
  }
  for(i = 0;i < cnt2;i++)
  {
    printf("%d %d %d\n", stu2[i].num, stu2[i].score[0], stu2[i].score[1]);
  }
  for(i = 0;i < cnt3;i++)
  {
    printf("%d %d %d\n", stu3[i].num, stu3[i].score[0], stu3[i].score[1]);
  }
  for(i = 0;i < cnt4;i++)
  {
    printf("%d %d %d\n", stu4[i].num, stu4[i].score[0], stu4[i].score[1]);
  }
}
