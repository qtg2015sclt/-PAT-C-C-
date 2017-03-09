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
