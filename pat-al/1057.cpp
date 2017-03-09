/**
 * pat-al-1057
 * 2017-02-27
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<stack>
#include<string.h>
#define MAX 100010
#define sqrN 316
using namespace std;
stack<int> st;
int block[sqrN];
int table[MAX];
void Push(int num)
{
  st.push(num);
  table[num]++;
  block[num/sqrN]++;
}
void Pop()
{
  int num = st.top();
  st.pop();
  table[num]--;
  block[num/sqrN]--;
  printf("%d\n", num);
}
void peekMedian(int k)
{
  int sum = 0, index = 0;
  while(sum + block[index] < k)
  {
    sum += block[index++];
  }
  int num = index * sqrN;
  while(sum + table[num] < k)
  {
    sum += table[num++];
  }
  printf("%d\n", num);
}
int main()
{
  memset(block, 0, sizeof(block));
  memset(table, 0, sizeof(table));
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  char cmd[20];
  int num;
  for(int i = 0;i < n;i++)
  {
    scanf("%s", cmd);
    if(strcmp(cmd, "Push") == 0)
    {
      scanf("%d", &num);
      Push(num);
    }
    else if(strcmp(cmd, "Pop") == 0)
    {
      if(st.empty())
        printf("Invalid\n");
      else
        Pop();
    }
    else//peekMedian
    {
      if(st.empty())
        printf("Invalid\n");
      else
      {
        int k = (st.size() + 1) / 2;
        peekMedian(k);
      }
    }
  }
  return 0;
}
