/**
 * pat-bl-1037
 * 2017-01-21
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>

int main()
{
  freopen("in.txt", "r", stdin);
  int pG, pS, pK, aG, aS, aK;
  scanf("%d.%d.%d %d.%d.%d", &pG, &pS, &pK, &aG, &aS, &aK);
  int p = pK, a = aK;
  p += pG * 17 * 29;
  p += pS * 29;
  a += aG * 17 * 29;
  a += aS * 29;
  int result = a - p;
  if(result < 0)
  {
    putchar('-');
    result = -result;
  }
  int resultK = result % 29;
  int resultG = result / (17 * 29);
  result -= resultG * (17 * 29);
  int resultS = result / 29;
  //result -= resultS * 29;
  //int resultK = result;
  printf("%d.%d.%d\n", resultG, resultS, resultK);
}
