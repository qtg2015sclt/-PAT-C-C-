/**
 * pat-al-1067
 * 2017-03-01
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#define MAX 100010
using namespace std;
int main()
{
  freopen("in.txt", "r", stdin);
  int n, pos[MAX], num, diffrent, min = 1, tmp, cnt = 0;
  scanf("%d", &n);
  diffrent = n-1;
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &num);
    pos[num] = i;
    if(num == i)
      diffrent--;
  }
  while(diffrent > 0)
  {
    if(pos[0] == 0)
    {
      while(min < n)
      {
        if(pos[min] != min)
        {
          swap(pos[0], pos[min]);
          cnt++;
          break;
        }
        min++;
      }
    }
    while(pos[0] != 0)
    {
      swap(pos[0], pos[pos[0]]);
      diffrent--;
      cnt++;
      // for(int i = 0;i < n;i++)
      // {
      //   for(int j = 0;j < n;j++)
      //   {
      //     if(pos[j] == i)
      //       printf("%d ", j);
      //   }
      // }
      // putchar('\n');
    }
    //printf("diffrent = %d\n", diffrent);
  }
  printf("%d\n", cnt);
  return 0;
}
