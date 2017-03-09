/**
 * pat-bl-1031
 * 2017-01-20
 * C version
 */
#include<stdio.h>

int main()
{
  int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};//前17位的权重
  char m[12] = "10X98765432";
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  char idnum[19];
  int flagCorrect = 1;//是否全部正确的标志，默认为全部通过
  for(int i = 0;i < n;i++)
  {
    scanf("%s", idnum);
    int sum = 0;
    for(int j = 0;j < 17;j++)
    {
      sum += (idnum[j] - '0') * weight[j];
      sum %= 11;
    }
    if(m[sum] != idnum[17])
    {
      printf("%s\n", idnum);
      flagCorrect = 0;
    }
  }
  if(flagCorrect)
    printf("All passed\n");
}
