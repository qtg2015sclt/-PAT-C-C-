pat-al-1035

2017-01-26

- 注意一下输出

```c
/**
 * pat-al-1035
 * 2017-01-26
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
struct STU
{
  char name[12];
  char password[12];
};
int main()
{
  freopen("in.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  struct STU stu[n];
  char tmpName[12], tmpPassword[12];
  int cnt = 0;
  for(int i = 0;i < n;i++)
  {
    scanf("%s %s", tmpName, tmpPassword);
    int flagModified = 0;//是否修改的标志，0为未修改
    for(int j = 0;j < strlen(tmpPassword);j++)
    {
      if(tmpPassword[j] == '1')
      {
        tmpPassword[j] = '@';
        flagModified = 1;
      }
      else if(tmpPassword[j] == '0')
      {
        tmpPassword[j] = '%';
        flagModified = 1;
      }
      else if(tmpPassword[j] == 'l')
      {
        tmpPassword[j] = 'L';
        flagModified = 1;
      }
      else if(tmpPassword[j] == 'O')
      {
        tmpPassword[j] = 'o';
        flagModified = 1;
      }
    }
    if(flagModified)
    {
      strcpy(stu[cnt].name, tmpName);
      strcpy(stu[cnt++].password, tmpPassword);
    }
  }
  if(cnt == 0)
  {
    if(n == 1)
      printf("There is 1 account and no account is modified\n");
    else
      printf("There are %d accounts and no account is modified\n", n);
  }
  else
  {
    printf("%d\n", cnt);
    for(int i = 0;i < cnt;i++)
    {
      printf("%s %s\n", stu[i].name, stu[i].password);
    }
  }
}
```
-FIN-
