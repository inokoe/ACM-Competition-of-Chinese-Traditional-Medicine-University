/*
题目描述
在编写代码的时候，有些人习惯使用制表符（Tab 键）来控制缩进、作分隔等，而有一些人则喜欢使用空格来做这些事情。
在一些代码编辑器中，有一种将制表符转化为空格的功能。使用者只需设定好每个制表符要用多少 个空格来替代，代码编辑器就会自动地对代码进行文本替代，使其代码风格与使用者接近。
这里将会给出一份n 行的代码，你的任务是写一个程序，将代码中的所有制表符（用“->” 表示） 转化为k 个空格，并将转化后的代码输出。


输入
第一行包含一个正整数T(1 ≤ T ≤ 10)，表示测试数据的组数。
每组测试数据第一行包含两个正整数n; k(1 ≤ n ≤ 10; 1 ≤ k ≤ 8)，分别表示代码的行数以及制表符应该被替换成多少个空格。
接下来n 行，每行一个非空的字符串，表示每行代码。每个字符串长度均不超过50，且字符串仅由小写字母“a” 到“z”、数字“0” 到“9”、特殊字符“{”,“}”,“(”,“)”,“;”,“-”,“>” 构成。
输出
对于每组测试数据，输出n 行，每行一个字符串，表示每行代码转化后的结果。
样例输入 Copy
2
5 2
dfs(x){
->if(x){
->->dfs(x);
->}
}
1 3
->->->print(a);->print(b);
样例输出 Copy
dfs(x){
  if(x){
    dfs(x);
  }
}
         print(a);   print(b);
*/

//http://202.196.1.136/problem.php?id=2137

//水题

//注意：使用asci码值代替字符，在在线OJ系统中，因为HTTP传输，- 和 > 等字符容易设置为防侵入的违禁规则

#include <iostream>
#include <string>
using namespace std;
int main()
{
  ios ::sync_with_stdio(false);
  cin.tie(0);
  int x, y, z;
  cin >> x;
  while (x--)
  {
    cin >> y >> z;
    string s;
    cin.ignore();
    while (y--)
    {
      getline(cin, s);
      for (int i = 0; i < s.size() - 1; i++)
      {
        if (s[i] == 45 && s[i + 1] == 62)
        {
          for (int a = 0; a < z; a++)
            cout << ' ';
          i++;
          continue;
        }
        cout << s[i];
      }
      cout << s[s.size() - 1] << endl;
    }
  }
  return 0;
}