1091.Acute Stroke (30)...to be continued...

pat-al-1091

2017-03-01

- 三维情况的bfs
- 要注意的是六个方向上：位置是否合法、是否被访问过、是否不为1

```c++
/**
 * pat-al-1091
 * 2017-03-01
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
  int x, y, z;
}Node;
int m, n, l, t;
int pixel[1290][130][65];
bool inq[1290][130][65] = {false};
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
bool judge(int x, int y, int z)
{
  if(x >= m || x < 0 || y >= n || y < 0 || z >= l || z < 0)
    return false;
  if(pixel[x][y][z] == 0 || inq[x][y][z] == true)
    return false;
  return true;
}
int bfs(int x, int y, int z)
{
  int total = 0;
  queue<node> q;
  Node.x = x, Node.y = y, Node.z = z;
  q.push(Node);
  inq[x][y][z] = true;
  while(!q.empty())
  {
    node top = q.front();
    q.pop();
    total++;
    for(int i = 0;i < 6;i++)
    {
      int newX = top.x + X[i];
      int newY = top.y + Y[i];
      int newZ = top.z + Z[i];
      if(judge(newX, newY, newZ))
      {
        Node.x = newX, Node.y = newY, Node.z = newZ;
        q.push(Node);
        inq[newX][newY][newZ] = true;
      }
    }
  }
  if(total >= t)
    return total;
  else
    return 0;
}
int main()
{
  freopen("in.txt", "r", stdin);
  scanf("%d%d%d%d", &m, &n, &l, &t);
  for(int z = 0;z < l;z++)
    for(int x = 0;x < m;x++)
      for(int y = 0;y < n;y++)
        scanf("%d", &pixel[x][y][z]);
  int ans = 0;
  for(int z = 0;z < l;z++)
    for(int x = 0;x < m;x++)
      for(int y = 0;y < n;y++)
        if(pixel[x][y][z] == 1 && inq[x][y][z] == false)
          ans += bfs(x, y, z);
  printf("%d\n", ans);
  return 0;
}
```
-TBC-
