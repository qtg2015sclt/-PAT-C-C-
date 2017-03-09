1010.Radix (25)...to be continued...

pat-al-1010

2017-02-15

- LLONG_MAX在<limits.h>里
- 还有遗留问题见注释里
- 参考：[1010. Radix (25)-PAT甲级真题](http://www.liuchuo.net/archives/2458)

```c++
/**
 * pat-al-1010
 * 2017-02-15
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int map[256];
long long turn2Decimal(char n[], int radix)
{
  long long ans = 0;
  int len = strlen(n);
  for(int i = 0;i < len;i++)
  {
    ans = ans * radix + map[n[i]];
  }
  if(ans < 0 || ans > LLONG_MAX)
    return -1;
  return ans;
}
long long findLargestDigit(char n[])
{
  int len = strlen(n);
  int max = -1;
  for(int i = 0;i < len;i++)
  {
    if(max < map[n[i]])
      max = map[n[i]];
  }
  return max+1;
}
int cmp(long long num2, long long num1)
{
  if(num2 < 0)
    return 1;
  if(num2 < num1)
    return -1;
  return (num2 == num1) ? 0 : 1;
}
long long binarySearch(char n[], long long low, long long high, long long num1)
{
  long long mid;
  while(low <= high)
  {
    mid = (low + high) / 2;
    int flag = cmp(turn2Decimal(n, mid), num1);
    if(flag == 0)
      return mid;
    else if(flag == 1)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}
int main()
{
  for(char c = '0';c <= '9';c++)
    map[c] = c - '0';
  for(char c = 'a';c <= 'z';c++)
    map[c] = c - 'a' + 10;
  freopen("in.txt", "r", stdin);
  char n1[12], n2[12];
  int tag, radix;
  scanf("%s%s%d%d", n1, n2, &tag, &radix);
  //printf("%s %s %d %d\n", n1, n2, tag, radix);
  if(tag == 2)//交换，保证n1是radix进制的
  {
    swap(n1, n2);
  }
  long long num1 = turn2Decimal(n1, radix);
  long long low = findLargestDigit(n2);
  long long high = max(num1, low) + 1;//问题：没想清楚为什么
  long long result = binarySearch(n2, low, high, num1);
  if(result == -1)
    printf("Impossible\n");
  else
    printf("%lld\n", result);
}
```
-TBC-
