/*
题目描述
路哥是云南中医学院大一新生，对路哥来说任何人任何物都只是他的道具而已。
过程不重要，只要最后胜利是属于路哥的。
路哥每次出完手就把这锅扔给别人。
而他自己，深藏功与名，事了拂衣去。
毕竟，深藏不露是一种卓越的才能。
某天，路哥被班主任叫去清理海报。
这里有一块宽为W，高为H的海报栏。以左下角为原点建立直角坐标系。
第i张贴上去的海报左下角为(x1_i,y1_i),右上角为(x2_i,y2_i)。
撕去一张海报会导致所有覆盖在其上的海报被同时撕掉(这个过程具有传递性，即如果A覆盖B，B覆盖C，那么撕掉C会导致A和B均被撕掉)
一张海报如果可以被撕掉需要至少存在一个角没有被其他海报覆盖。
海报A被海报B覆盖当且仅当存在A和B的交面积大于0，并且A在B之前贴出。
由于路哥嫌麻烦，为了提高效率，路哥会一次性的撕掉尽可能多的海报。
现在请你帮路哥计算路哥一次最多可以撕掉多少张海报。
在张数相同的情况下，路哥会选择更早贴出的海报。

输入
多组数据。
第一行三个整数W,H,N,分别为海报栏的宽和高，贴出的海报数量。
接下来N行，每行四个整数x1_i,y1_i,x2_i,y2_i。
(1 <= W,H <= 10000000, 1 <= N <= 1000, 0 <= x1_i,x2_i <= W, 0 <= y1_i,y2_i <= H)

输出
输出两个整数，分别是海报数量和撕去的是第几张。

样例输入 Copy
6 7 4
0 0 4 4
1 0 3 4
1 4 4 6
0 0 3 5
样例输出 Copy
3 1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 100;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
struct node
{
    double x1, y1, x2, y2;
} s[maxn];
vector<int> a[maxn];
int vis[maxn];
int f[maxn];
int cnt;
int check(node a, node b, int x)
{
    int flag = 0;
    a.x1 += 0.1, a.y1 += 0.1;
    a.x2 -= 0.1, a.y2 -= 0.1;
    if (a.x1 > b.x1 && a.x1 < b.x2 && a.y1 > b.y1 && a.y1 < b.y2)
        f[x] |= 1, flag = 1;
    if (a.x1 > b.x1 && a.x1 < b.x2 && a.y2 > b.y1 && a.y2 < b.y2)
        f[x] |= 2, flag = 1;
    if (a.x2 > b.x1 && a.x2 < b.x2 && a.y2 > b.y1 && a.y2 < b.y2)
        f[x] |= 4, flag = 1;
    if (a.x2 > b.x1 && a.x2 < b.x2 && a.y1 > b.y1 && a.y1 < b.y2)
        f[x] |= 8, flag = 1;
    if (!(a.x1 > b.x2 || a.x2 < b.x1 || a.y1 > b.y2 || a.y2 < b.y1))
        flag = 1;
    return flag;
}

void dfs(int x)
{
    vis[x] = 1;
    cnt++;
    for (int i = 0; i < a[x].size(); i++)
    {
        if (!vis[a[x][i]])
        {
            dfs(a[x][i]);
        }
    }
}

int main()
{
    int w, n, h;
    while (cin >> w >> h >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf%lf%lf%lf", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2);
            a[i].clear();
        }
        for (int i = n; i >= 1; i--)
        {
            for (int j = n; j > i; j--)
            {
                if (check(s[i], s[j], i))
                    a[i].push_back(j);
            }
        }
        int ans = -1, p = 0;
        for (int i = 1; i <= n; i++)
        {
            if (f[i] != 15)
            {
                memset(vis, 0, sizeof(vis));
                cnt = 0;
                dfs(i);
                if (cnt > ans)
                {
                    ans = cnt;
                    p = i;
                }
            }
        }
        printf("%d %d\n", ans, p);
        memset(f, 0, sizeof(f));
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}