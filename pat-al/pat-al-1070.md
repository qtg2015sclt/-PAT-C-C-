1070.Mooncake (25)

pat-al-1070

2017-02-09

- 典型的贪心
- 乙级里也有这题
- 遇到段错误，可以考虑是不是数组越界，看看用到数组的地方是不是要对下标的判断更谨慎一点。坑见注释

```c++
/**
 * pat-al-1070
 * 2017-02-09
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
using namespace std;
struct MC
{
  double amount;
  double price;
  double unitPrice;
}mc[1001];
bool cmp(MC a, MC b)
{
  return a.unitPrice > b.unitPrice;
}
int main()
{
  freopen("in.txt", "r", stdin);
  int n, d;
  scanf("%d%d", &n, &d);
  for(int i = 0;i < n;i++)
  {
    scanf("%lf", &mc[i].amount);
  }
  for(int i = 0;i < n;i++)
  {
    scanf("%lf", &mc[i].price);
    mc[i].unitPrice = mc[i].price / mc[i].amount;
  }
  sort(mc, mc+n, cmp);
  int sum = 0, i = 0;
  double maxProfit = 0;
  while(sum < d && i < n)
  {
    if(d - sum >= mc[i].amount)
    {
      sum += mc[i].amount;
      maxProfit += mc[i++].price;
    }
    else
    {
      maxProfit += (d - sum) * (mc[i].price / mc[i].amount);
      break;
    }
  }
  printf("%.2lf\n", maxProfit);
}
```
-FIN-
