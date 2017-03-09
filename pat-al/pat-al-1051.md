1051.Pop Sequence (25)

pat-al-1051

2017-02-26

- 使用了stack
- 模拟手工计算的情况，对每次读到的数据进行入栈和出站，然后分情况判断是否符合要求（别忘了还要判断栈的容量）

```c++
/**
 * pat-al-1051
 * 2017-02-26
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
  freopen("in.txt", "r", stdin);
  int capacity, n, k;
  int num, max;
  int flagFail;
  scanf("%d%d%d", &capacity, &n, &k);
  for(int i = 0;i < k;i++)
  {
    stack<int> st;
    max = 0;
    flagFail = 0;
    for(int j = 0;j < n;j++)
    {
      scanf("%d", &num);
      if(flagFail == 1)
        continue;
      //printf("num = %d\n", num);
      if(max < num)
      {
        while(max < num)
        {
          max++;
          st.push(max);
        }
        if(st.size() > capacity)
        {
          //printf("st.size = %lu, capacity = %d\n", st.size(), capacity);
          printf("NO\n");
          flagFail = 1;
        }
        st.pop();
      }
      else if(max == num)
      {
        st.pop();
      }
      else if(max > num && st.top() == num)
      {
        st.pop();
      }
      else if(max > num && st.top() != num)
      {
        printf("NO\n");
        flagFail = 1;
      }
    }
    if(flagFail == 0)
      printf("YES\n");
  }
  return 0;
}
```
-FIN-
