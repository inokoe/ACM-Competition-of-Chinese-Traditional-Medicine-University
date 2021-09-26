/*
题目描述
Title description
Given N(1 ≤ N ≤ 10000) unordered positive integers ranging from 1 to 30000. The same positive 给定 n (1≤ n ≤10000)为1ー30000的无序正整数
integer may appear multiple times and the most frequently occurring integer is called the mode. Find 整数可能出现多次，最常出现的整数称为模式
the sequence’s mode(s) and the number of times it appears. 序列的模式和出现的次数
输入
Inputting
There are several test files and each contains one case. 有几个测试文件，每个文件包含一个案例
The first line of the input is a positive integers N and the second line begins with N positive integers. 输入的第一行是正整数 n，第二行以正整数 n 开头

输出
Output
The output has several lines, two for each line. The first is the mode, and the second is the number of 输出有几行，每行两行。第一个是模式，第二个是数字
times the mode appears. 1 space between the middle. If there are multiple modes, print the modes in 时间模式出现。1空间之间的中间。如果有多个模式，打印模式在
ascending order. 升序
样例输入 Sample inputCopy 收到
12
2 4 2 3 2 5 3 7 2 3 4 3
样例输出 Sample outputCopy 收到
2 4
3 4
*/

//map set 基本运用
//2744 KB  65 ms

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    int x, y, MAX = 0;
    while (cin >> x)
    {
        map<int, int> mp;
        for (int i = 0; i < x; i++)
        {
            cin >> y;
            mp[y]++;
            if (mp[y] > MAX)
                MAX = mp[y];
        }
        map<int, int>::iterator it = mp.begin();
        set<int> st;
        for (it; it != mp.end(); it++)
        {
            if (it->second == MAX)
            {
                st.insert(it->first);
            }
        }
        for (auto i : st)
            cout << i << ' ' << MAX << endl;
    }
    return 0;
}