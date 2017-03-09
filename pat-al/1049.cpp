/**
 * pat-al-1049
 * 2017-02-26
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
int main()
{
  freopen("in.txt", "r", stdin);
  int n, a = 1, ans = 0;
  scanf("%d", &n);
  int left, right, now;
  while(n / a != 0)
  {
    left = n / (a * 10);
    now = n / a % 10;
    right = n % a;
    if(now == 0)
      ans += left * a;
    else if(now == 1)
      ans += left * a + (right + 1);
    else//now > 1
      ans += (left + 1) * a;
    a *= 10;
  }
  printf("%d\n", ans);
  return 0;
}
