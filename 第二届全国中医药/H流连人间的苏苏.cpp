/*
Description
苏苏在做红尘仙的任务时，发现坐落于风景秀丽、四季如春的昆明市的云南中医学院。

没过多久，苏苏就喜欢上了这个学校。以致于苏苏忘了回涂山的时间，现在她只剩下d天的时间待在云南中医学院。由于时间紧迫，苏苏想方设法为建设更好的云南中医学院。

假设学校里某条街道有n个房子。

每天选择两个门牌号l、r,给这两个门牌号之间的所有房子的门前都栽一棵树，已经有树的不需要再种。

苏苏想知道在某天，有哪些房子前有树。

Input
每个输入文件只有一组数据
第一行包含n,d。(1 <= n,d <= 1000)
接下来d行，每行包含两个整数l,r(1 <= l <= r <= n)

Output
输出d行。
每行输出门牌号的区间。每个区间以逗号分隔。
具体看样例。

Sample Input
10 4
1 3
2 4
5 6
8 10
Sample Output
[1,3]
[1,4]
[1,6]
[1,6],[8,10]
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, x, y, z;
    cin >> a >> x;
    vector<int> vc(a+2);
    while (x--)
    {
        cin >> y >> z;
        for (int i = y; i <= z; i++)vc[i] = 1;
        vector<pair<int, int> >pr;
        int s, e;
        vc[0] = 0;
        for (int i = 1; i < vc.size(); i++)
        {
            if (vc[i - 1] == 0 && vc[i] == 1)
            {
                s = i;
            }
            if (vc[i - 1] == 1 && vc[i] == 0)
            {
                e = i-1;
                pr.push_back(make_pair(s, e));
            }
        }
        for (int i = 0; i < pr.size(); i++)
        {
            if (i != pr.size() - 1)
                cout << '[' << pr[i].first << "," << pr[i].second << "],";
            else
                cout << '[' << pr[i].first << "," << pr[i].second << "]";
        }
        cout << endl;
    }
    return 0;
}