/**
 * pat-al-1042
 * 2017-01-26
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  char card[55][4] = {"0", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
                      "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
                      "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
                      "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
                      "J1", "J2"};//"0"用来占位
  int k;
  scanf("%d", &k);
  int order[55] = {0};
  for(int i = 1;i < 55;i++)
  {
    scanf("%d", &order[i]);
  }
  int result[55] = {0};//result存放最终结果，result[j]的内容是牌号，比如result[4] = 14表示H1这张牌放在4位置
  for(int i = 1;i < 55;i++)//i表示牌号，每张牌查一遍
  {
    int newOrder = i;//最初牌号为i的牌是放在i位的
    for(int j = 0;j < k;j++)
    {
      newOrder = order[newOrder];//在order中查询出新的位置，更新newOrder
    }
    result[newOrder] = i;//把牌号为i的牌放在最终的位置上
  }
  //output:
  printf("%s", card[result[1]]);
  for(int i = 2;i < 55;i++)
  {
    printf(" %s", card[result[i]]);
  }
  putchar('\n');
}
