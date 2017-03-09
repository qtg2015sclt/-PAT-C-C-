1016.Phone Bills (25)...to be continued...

pat-al-1016

2017-02-16

- 坑见注释
- 参考：《算法笔记：上机训练实战指南》机械工业出版社

```c++
/**
 * pat-al-1016
 * 2017-02-16
 * Cpp version
 * Author: fengLian_s
 */
 #include<stdio.h>
 #include<algorithm>
 #include<string.h>
 #define MAX 1010
 using namespace std;
 struct RECORD
 {
   char name[25];
   int month;
   int dd, hh, mm;
   bool flagOn;//false为off，true为on
 }record[MAX], tmp;
 int cost[25];
 bool cmp(RECORD a, RECORD b)
 {
   if(strcmp(a.name, b.name) != 0)
     return strcmp(a.name, b.name) < 0;//坑，注意要用strcmp
   else if(a.dd != b.dd)
     return a.dd < b.dd;
   else if(a.hh != b.hh)
     return a.hh < b.hh;
   else if(a.mm != b.mm)
     return a.mm < b.mm;
 }
 void getAns(int on, int off, int& lastTime, double& money)
 {
   tmp = record[on];
   while(tmp.dd < record[off].dd || tmp.hh < record[off].hh || tmp.mm < record[off].mm)
   {
     lastTime++;
     money += cost[tmp.hh];
     tmp.mm++;
     if(tmp.mm == 60)
     {
       tmp.mm = 0;
       tmp.hh++;
     }
     if(tmp.hh == 24)
     {
       tmp.hh = 0;
       tmp.dd++;
     }
   }
 }
 int main()
 {
   freopen("in.txt", "r", stdin);
   int n;
   for(int i = 0;i < 24;i++)
   {
     scanf("%d", &cost[i]);
   }
   scanf("%d", &n);
   for(int i = 0;i < n;i++)
   {
     char tmpFlag[10];
     scanf("%s%d:%d:%d:%d", record[i].name, &record[i].month, &record[i].dd, &record[i].hh, &record[i].mm);
     scanf("%s", tmpFlag);
     if(tmpFlag[1] == 'f')
      record[i].flagOn = false;
     else
      record[i].flagOn = true;
   }
   sort(record, record+n, cmp);
  //  for(int i = 0;i < n;i++)
  //  {
  //    printf("%s %d:%d:%d:%d %d\n", record[i].name, record[i].month, record[i].dd, record[i].hh, record[i].mm, record[i].flagOn);
  //  }
   int on = 0, off, next;
   while(on < n)
   {
     next = on;
     int flagPrint = 0;
     while(next < n && strcmp(record[on].name, record[next].name) == 0)
     {
       if(flagPrint == 0 && record[next].flagOn == true)//一开始对这一对判断有点疑问，比如true和false之间又隔了一个true呢？思考后发现如果又隔了一个true就相当于是认为第二个true才是这一对的开始，是不影响结果的，好奇妙啊
        flagPrint = 1;
       else if(flagPrint == 1 && record[next].flagOn == false)
        flagPrint = 2;
       next++;
     }
     if(flagPrint < 2)
     {
       on = next;
       continue;
     }
     printf("%s %02d\n", record[on].name, record[on].month);
     double sumOfMoney = 0;
     while(on < next)
     {
       while(on + 1 < next && !(record[on].flagOn == true && record[on+1].flagOn == false))
       {
         on++;
       }
       off = on+1;
       if(off == next)//坑：不要漏了这个判断
       {
         on = next;
         break;
       }
       printf("%02d:%02d:%02d ", record[on].dd, record[on].hh, record[on].mm);
       printf("%02d:%02d:%02d ", record[off].dd, record[off].hh, record[off].mm);
       int lastTime = 0;
       double money = 0;
       getAns(on, off, lastTime, money);
       printf("%d $%.2lf\n", lastTime, money/100);
       sumOfMoney += money;
       on += 2;
     }
     printf("Total amount: $%.2lf\n", sumOfMoney/100);
   }
   return 0;
 }
```
-TBC-
