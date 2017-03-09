/**pat-bl-1013
 *2016-11-12
 *C version 1.0
 *未AC前出错2处
 */
#include<stdio.h>
#include<math.h>

int main()
{
  int m, n, i, j, k, spaceFlag = 0;
  //printf("input m & n:\n");
  int prime[10001] = {1, 2, 3};//出错2：prime[0]置1，以便第i个素数存储在prime[i]
  //printf("input m & n:\n");
  scanf("%d%d", &m, &n);
  //printf("m = %d n = %d\n", m, n);
  for(i = 5, k = 3;k <= n;i++)
  {
    for(j = 2;j <= (int)sqrt((double)i);j++)
    {
      if(i % j == 0)//出错1：>_<忘写了==0，调了好久才发现
      {
        //printf("%d mod %d = %d\n", i, j, i%j);
        break;
      }
    }
    if(j > (int)sqrt((double)i))
    {
      prime[k++] = i++;
      //printf("prime[%d] = %d\n", k-1, prime[k-1]);
    }
  }

  for(k = m;k <= n;k++)
  {
    if((k-m)%10 == 0)//换行处理在输出数据之前。（k-m）为10的整数倍则换行，否则输出空格
    {
      if(k != m)//第一个数据不换行
        putchar('\n');
    }
    else
      putchar(' ');
    printf("%d", prime[k]);
  }
  putchar('\n');
}
