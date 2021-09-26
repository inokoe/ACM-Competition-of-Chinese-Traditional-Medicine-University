/*
Description
第二届全国中医药程序设计大赛在云南中医学院举行，全国各中医药院校从全国各地奔赴云南。
每个人的车票或机票上都会有如下信息:

地名 出发时间 到达时间 
地名:长度不超过20
出发时间: 格式hhmm
到达时间: 格式hhmm
(0 <= hh <= 23,0 <= mm <= 59)
但是他们想知道在路上所花费的时间总共是多少。
现在请你编写程序帮助他们计算时间。

Input
多组数据
每组数据有一个字符串s和两个整数Time1,Time2,分别表示地名，出发时间，到达时间。 

保证 到达时间 >= 出发时间

Output
输出旅途时间。格式见样例。

Sample Input
Hangzhou 1245 1723
Sample Output
Hangzhou to Kunming: 04:38
HINT
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int x, y;
    while (cin >> s >> x >> y)
    {
        int hour = 0, Min = 0;
        int MinE = y - (y / 100) * 100;
        int MinS = x - (x / 100) * 100;
        //cout<<MinS<<":"<<MinE<<endl;
        if (y / 100 >= x / 100)
        {
            hour = y / 100 - x / 100;
        }
        else
        {
            hour = (y / 100 + 24) - x / 100;
        }
        if (MinS > MinE)
        {
            hour--;
            Min = 60 - MinS + MinE;
        }
        else
            Min = MinE - MinS;
        cout << s + " to Kunming: ";
        if (hour == 0)
            cout << "00";
        else if (hour < 10 && hour > 0)
        {
            cout << "0";
            cout << hour;
        }
        else
            cout << hour;
        cout << ":";
        if (Min == 0)
            cout << "00";
        else if (Min > 0 && Min < 10)
        {
            cout << "0";
            cout << Min << endl;
        }
        else
            cout << Min << endl;
    }
    return 0;
}