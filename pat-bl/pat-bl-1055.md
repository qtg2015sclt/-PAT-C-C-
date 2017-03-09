pat-bl-1055

2017-01-23

- 先排序，然后从最后一排开始输出，参考别人使用了字符串拼接的做法
- 坑：用字符数组出现了段错误，还常常写反导致出错……
- 尝试了使用string和vector
- 注意：我自己这里不加#include<algorithm>也可以用sort，但提交的时候是一定要写的
- 一点启发：用对了方法，就不会太难

```c++
/**
 * pat-bl-1055
 * 2017-01-23
 * Cpp version
 * Author: fengLian_s
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct STU
{
  string name;
  int height;
};
bool cmp(STU a, STU b)
{
  if(a.height == b.height)
    return a.name < b.name;//一开始写反了……
  return a.height > b.height;
}
int main()
{
  int n, k;
  cin >> n >> k;
  vector<STU> stu(n);
  for(int i = 0;i < n;i++)
  {
    cin >> stu[i].name >> stu[i].height;
    //cout << stu[i].name << " " << stu[i].height << endl;
  }
  sort(stu.begin(), stu.end(), cmp);//按从高到矮，一样高时名字从a到z排序
  for(int i = 0;i < n;i++)
  {
    cout << stu[i].name << " " << stu[i].height << endl;
  }
  //记录一个坑：之前用char数组写，一直段错误，后来参考别人改成字符串拼接了
  string result = "";//用string保存这一排
  int cntFinal = n/k + n%k, cntELse = n/k;
  for(int i = 0;i < n;)
  {
    int cnt;
    if(i == 0)//判断一下是否是最后一排
      cnt = cntFinal;
    else
      cnt = cntELse;
    result = stu[i++].name;
    for(int j = 1;j < cnt;j++)
    {
      if(j % 2 == 1)//右左交叉
        result = stu[i++].name + " " + result;
      else
        result = result + " " + stu[i++].name;
    }
    cout << result << endl;
  }
}
```
-FIN-
