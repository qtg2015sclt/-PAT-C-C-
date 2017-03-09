pat-bl-1020

2016-12-16

- 使用了结构体，利用sort排序

```c++
/**
 *pat-bl-1020
 *2016-12-16
 *C++ version
 *
 */
#include<iostream>
#include<algorithm>
using namespace std;

struct MOONCAKE
{
  double amount;
  double price;
  double unitPrice;
};
bool cmpUnitPrice(MOONCAKE a, MOONCAKE b)
{
  return a.unitPrice > b.unitPrice;
}
int main()
{
  int kind, amount;
  freopen("in.txt", "r", stdin);
  cin >> kind >> amount;
  MOONCAKE mc[kind];
  for(int i = 0;i < kind;i++)
  {
    cin >> mc[i].amount;
  }
  for(int i = 0;i < kind;i++)
  {
    cin >> mc[i].price;
  }
  for(int i = 0;i < kind;i++)
  {
    mc[i].unitPrice = 1.0 * mc[i].price / mc[i].amount;
    //cout << "mc" << i << ":" << mc[i].unitPrice << endl;
  }
  sort(mc, mc+kind, cmpUnitPrice);
  // for(int i = 0;i < kind;i++)
  // {
  //   cout << "mc amount" << i << ":" << mc[i].amount << endl;
  // }
  double earnings = 0;
  int i = 0;
  while(amount > 0)
  {
    if(amount > mc[i].amount)
    {
      earnings += mc[i].price;
      amount -= mc[i].amount;
    }
    else
    {
      earnings += mc[i].price * amount / mc[i].amount;
      //cout << "price:" << mc[i].price << ", amount:" << amount << ", mcamount:" << mc[i].amount << endl;
      amount = 0;
    }
    i++;
  }
  printf("%.2f\n", earnings);
  return 0;
}
```
-FIN-
