/**
 * pat-al-1098
 * 2017-03-05
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<algorithm>
#define MAX 105
using namespace std;
int n;
int origin[MAX], changed[MAX], tmp[MAX];
int isSame()
{
  for(int i = 0;i < n;i++)
  {
    if(origin[i] != changed[i])
      return false;
  }
  return true;
}
void showArray()
{
  printf("%d", origin[0]);
  for(int i = 1;i < n;i++)
  {
    printf(" %d", origin[i]);
  }
  putchar('\n');
}
int insertSort()
{
  int flag = 0;
  for(int i = 1;i < n;i++)
  {
    //printf("i = %d: ", i);
    //showArray();
    if(i != 1 && isSame())
      flag = 1;
    sort(origin, origin+i+1);
    if(flag == 1)
      return true;
  }
  return false;
}
void fixDown(int now, int size)
{
  int index = now * 2 + 1;
  if(index >= size)
    return;
  if(origin[index] < origin[index+1] && index+1 < size)
    index++;
  if(origin[now] < origin[index])
  {
    swap(origin[now], origin[index]);
    fixDown(index, size);
  }
}
void heapSort()
{
  //create heap:
  for(int i = n/2;i >= 0;i--)
  {
    fixDown(i, n);
  }
  int flag = 0;
  for(int i = n-1;i >= 0;i--)
  {
    if(i != n-1 && isSame())
      flag = 1;
    swap(origin[0], origin[i]);
    fixDown(0, i);
    if(flag == 1)
      return;
  }
}
int main()
{
  freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &origin[i]);
    tmp[i] = origin[i];
  }
  for(int i = 0;i < n;i++)
  {
    scanf("%d", &changed[i]);
  }
  if(insertSort())
  {
    printf("Insertion Sort\n");
    showArray();
  }
  else
  {
    for(int i = 0;i < n;i++)
    {
      origin[i] = tmp[i];
    }
    printf("Heap Sort\n");
    heapSort();
    showArray();
  }
}
