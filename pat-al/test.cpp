#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
  int n = 1000;
  int cnt = 0;
  for(int i = 5;i <= n;i += 5)
  {
    int tmp = i;
    while(tmp % 5 == 0)
    {
      cnt++;
      tmp /= 5;
    }
  }
  printf("cnt = %d\n", cnt);
}
