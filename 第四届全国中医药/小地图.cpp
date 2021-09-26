/*
Description
给定一个n行m列的网格地图，从上到下依次编号为第1行到第n行，从左往右依次编号为第1列到第m列。每个格子要么可以通行（用.表示），要么不可通行（用#表示）。


玩家P现在位于某个可以通行的格子上，小地图显示出了玩家所在位置周围3 * 3 = 9个格子。请写一个程序，根据地图和小地图找到玩家可能所在的位置。
Input
第一行包含一个正整数T(1 <= T <= 10)，表示测试数据的组数。


每组测试数据第一行包含两个正整数n,m(1 <= n,m <= 100)，表示行数和列数。


接下来n行，每行包含一个长度为m的字符串，依次描述每一行每个格子的情况。字符串仅由.和#构成。


接下来3行，每行包含一个长度为3的字符串，描述玩家所在位置周围的情况。字符串由.、#、P（表示玩家所在位置）和*（表示超出地图的部分）构成。输入数据保证有且仅有一个P，且P一定位于小地图的第2行第2列。


请注意：你不能旋转/翻转小地图。
Output
对于每组数据，输出一行一个整数，即玩家可能所在的位置的数量。
Sample Input
2
5 8
#.#....#
#.#..#..
.#..#.#.
#..###..
...#....
.#.
#P.
...
1 2
.#
***
*P#
***
Sample Output
2
1
*/

//https://acm.zcmu.edu.cn/JudgeOnline/problem.php?id=5080

//基础，图形匹配  。 思路 ： 一维数组即可，图形四周补上一圈* ，P换成. ，然后匹配。

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    int x, y, z;
    cin >> x;
    while (x--)
    {
        int ans = 0;
        cin >> y >> z;
        string s, tp = "";
        vector<string> vs;
        for (int i = 0; i < z + 2; i++)
        {
            tp += '*';
        }
        vs.push_back(tp);
        for (int i = 0; i < y; i++)
        {
            tp = "";
            cin >> s;
            tp += '*';
            tp += s;
            tp += '*';
            vs.push_back(tp);
        }
        tp = "";
        for (int i = 0; i < z + 2; i++)
        {
            tp += '*';
        }
        vs.push_back(tp);
        /*
        cout << endl;
        for (auto i : vs)
            cout << i << endl;
        cout << endl;
        */
        vector<string> Fix;
        for (int i = 0; i < 3; i++)
        {
            cin >> s;
            tp = "";
            for (int a = 0; a < 3; a++)
            {
                if (s[a] == 'P')
                    s[a] = '.';
                tp += s[a];
            }
            Fix.push_back(tp);
        }
        tp = "";
        for (int i = 0; i < vs.size() - 2; i++)
        {
            /*
            cout << endl;
            cout << endl;
            cout << i << endl;
            */
            s = vs[i];
            int position = s.find(Fix[0]);
            while (position != -1)
            {
                tp += vs[i + 1][position];
                tp += vs[i + 1][position + 1];
                tp += vs[i + 1][position + 2];
                //cout << tp << endl;
                if (tp == Fix[1])
                {
                    tp = "";
                    tp += vs[i + 2][position];
                    tp += vs[i + 2][position + 1];
                    tp += vs[i + 2][position + 2];
                    //cout << tp << endl;
                    if (tp == Fix[2])
                        ans++;
                }
                position = s.find(Fix[0], position + 1);
                tp = "";
            }
            tp = "";
        }
        cout << ans << endl;
    }
    return 0;
}