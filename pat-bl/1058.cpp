/**
 * pat-bl-1058
 * 2017-01-23
 * Cpp version
 * Author: fengLian_s
 */
#include<iostream>
#include<vector>
using namespace std;
struct QUE
{
  int score;
  int opt;
  int rightOpt;
  string ans;
  int wrongCnt;
};

int main()
{
  int numStu, numQue;
  cin >> numStu >> numQue;
  vector<QUE> que(numQue);
  for(int i = 0;i < numQue;i++)
  {
    cin >> que[i].score >> que[i].opt >> que[i].rightOpt;
    char tmp;
    que[i].ans = "";
    for(int j = 0;j < que[i].rightOpt;j++)
    {
      cin >> tmp;
      que[i].ans += tmp;
    }
    que[i].wrongCnt = 0;
    //cout << "ans = " << que[i].ans << endl;
  }
  getchar();//吃掉换行符
  int stuScore[numStu];
  for(int i = 0;i < numStu;i++)
  {
    //cout << "stu" << i << ": ";
    stuScore[i] = 0;
    char ch;
    int queNum = 0;//第几题
    while((ch = getchar()) != '\n')
    {
      if(ch == '(')
      {
        //cout << "que" << queNum << ", ";
        int tmpOpt;
        string ans = "";
        cin >> tmpOpt;
        //cout << "tmpOpt = " << tmpOpt << endl;
        while(tmpOpt)
        {
          ch = getchar();
          if(ch != ' ')
          {
            tmpOpt--;
            ans += ch;
          }
        }
        //cout << "stu" << i << "," << queNum << ": " << ans << endl;
        if(que[queNum].ans == ans)
        {
          stuScore[i] += que[queNum].score;
          //cout << "i = " << i << ": " << stuScore[i] << endl;
        }
        else
          que[queNum].wrongCnt++;
        queNum++;
      }
      else
        continue;
    }
  }
  for(int i = 0;i < numStu;i++)
  {
    cout << stuScore[i] << endl;
  }
  int maxWrongCnt = que[0].wrongCnt;
  for(int i = 1;i < numQue;i++)
  {
    if(maxWrongCnt < que[i].wrongCnt)
    {
      maxWrongCnt = que[i].wrongCnt;
    }
  }
  if(maxWrongCnt != 0)
  {
    cout << maxWrongCnt;
    for(int i = 0;i < numQue;i++)//出错：没把这一段输出放进这个if里……
    {
      if(maxWrongCnt == que[i].wrongCnt)
      {
        cout << " " << i+1;
      }
    }
  }
  else
    cout << "Too simple";//不能再多输出回车符（下面已经有一个统一的输出了），否则会格式错误
  putchar('\n');
}
