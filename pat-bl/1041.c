/**
 * pat-bl-1041
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
struct Stu
{
  char id[15];
  //int testSeat;
  int seat;
};
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  struct Stu stu[1001];//最多1000个，直接开这么大的数组
  for(int i = 0;i < n;i++)
  {
    char tmpID[15];
    int  tmpTestSeat, tmpSeat;
    scanf("%s %d %d", tmpID, &tmpTestSeat, &tmpSeat);
    stu[tmpTestSeat].seat = tmpSeat;//直接使用试机位号作为下标来进行存储，以便之后的查找
    strcpy(stu[tmpTestSeat].id, tmpID);
    //printf("%s %d %d\n", stu[tmpTestSeat].id, tmpTestSeat, stu[tmpTestSeat].seat);
  }
  int m;
  scanf("%d", &m);
  for(int i = 0;i < m;i++)
  {
    int tmpSeat;
    scanf("%d", &tmpSeat);
    printf("%s %d\n", stu[tmpSeat].id, stu[tmpSeat].seat);
  }
}
