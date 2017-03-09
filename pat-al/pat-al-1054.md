pat-al-1054

2017-01-26

- 写了好久的一题，一开始用c写的，全部用数组手动查找，一个测试点超时，一个测试点出错
- 后来看到一个不错的思路：[PAT 解题报告 1054. The Dominant Color (20)](http://www.sigmainfy.com/blog/pat-1054-the-dominant-color.html)自己照着写了一下发现还是有一个测试点超时
- 于是又找了一个新的方法：[1054. The Dominant Color (20)-PAT甲级真题](http://www.liuchuo.net/archives/2048)写了发现那个测试点依旧超时，突然想起来cin比scanf耗时大，果然替换之后就不超时了
- 坑：如果使用了cin、cout，有测试点超时且感觉不是程序有问题，那么换成scanf和printf试试
- 强迫症的难过：一开始写的那个方法，那个出错的测试点到底是为什么？……可能我永远都不会知道了……
- map的使用

```c++
/**
 * pat-al-1054
 * 2017-01-26
 * Cpp version
 * Author: fengLian_s
 */
#include<map>
using namespace std;
int main()
{
  int m, n;//m是列数，n是行数
  scanf("%d %d", &m, &n);
  int half = m*n/2;
  //cout << "half = " << half << endl;
  map<int, int> color;
  for(int i = 0;i < m*n;i++)
  {
    int tmp;
    scanf("%d", &tmp);//大坑：有一个测试点运行超时是因为用cin输入耗时
    color[tmp]++;
    //cout << tmp << ": " << color[tmp] << endl;
    if(color[tmp] > half)
    {
      printf("%d\n", tmp);
      break;
    }
  }
  return 0;
}
```
-FIN-
