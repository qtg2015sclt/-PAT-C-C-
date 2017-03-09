pat-bl-1016

2016-11-15

- 简单题。字符串读入，遍历判断就可以了

```c
/**
 *pat-bl-1016
 *2016-11-15
 *C version 1.0
 */
#include<stdio.h>

int main()
{
  char a[10], da, b[10], db;
  int pa, pb;
  int i;
  //freopen("in.txt", "r", stdin);//提交的时候别忘了注释掉
  while(scanf("%s %c %s %c", a, &da, b, &db) != EOF)
  {
    //printf("%s %c %s %c\n", a, da, b, db);
    pa = 0;
    pb = 0;
    i = 0;
    while(a[i] != '\0')
    {
        if(a[i] == da)
        {
          pa = pa * 10 + da - '0';
        }
        i++;
    }
    i = 0;
    while(b[i] != '\0')
    {
      if(b[i] == db)
      {
        pb = pb * 10 + db - '0';
      }
      i++;
    }
    printf("%d\n", pa+pb);
  }//while end
}
```
-Fin-
