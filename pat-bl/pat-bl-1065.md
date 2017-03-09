pat-bl-1065

2017-01-23

- 觉得这题不难，结果把所有坑踩了一边……
- 坑1：初始化的时候要设置为-1，因为有编号00000的客人
- 坑2：边界情况，没有单身的客人时注意控制输出
- 坑3：坑2的升级，躲过了坑2但可能躲不过坑3，连换行都不能输出哦
- 练习了一下迭代器的使用

```c++
/**
 * pat-bl-1065
 * 2017-01-23
 * Cpp version
 * Author: fengLian_s
 */
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int tmp1, tmp2;
  int couple[100000];
  int hs[100000] = {0};//默认没来
  memset(couple, -1, sizeof(couple));//坑1：不能设置为0，因为有编号00000的客人
  for(int i = 0;i < n;i++)
  {
    cin >> tmp1 >> tmp2;
    couple[tmp1] = tmp2;
    couple[tmp2] = tmp1;
  }
  int m;
  cin >> m;
  int tmp;
  vector<int> result;
  vector<int> storeID;
  for(int i = 0;i < m;i++)
  {
    cin >> tmp;
    if(couple[tmp] == -1)
    {
      //cout << "tmp = " << tmp << endl;
      result.push_back(tmp);
    }
    else
    {
      hs[tmp] = 1;//设置为在场
      storeID.push_back(tmp);
    }
  }
  vector<int>::iterator it;
  for(it = storeID.begin();it < storeID.end();it++)
  {
    if(hs[couple[*it]] == 0)
      result.push_back(*it);
  }
  sort(result.begin(), result.end());
  it  = result.begin();
  cout << result.size() << endl;
  if(result.size() != 0)//坑2：零的时候不输出，不然会段错误
    printf("%05d", *it);
  for(it++;it < result.end();it++)
  {
    printf(" %05d", *it);
  }
  //putchar('\n');坑3：当没有单身的客人时不输出第二行，连换行都不能输出，不然就格式错误
}
```
-FIN-
