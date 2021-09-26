/*
题目描述
小 Q 是一名出色的药剂师，为了合成新的药剂，他将药材放入了一个 n×m 的网格状药材盒（下标从 1
开始），用 n 个长度为 m 的字符串 (仅由小写字母组成) 代表这个药材盒，一共有 26 种药材，每个字母
代表一种药材。
为了达到最优的疗效，小 Q 需要尝试不同的配比方案，为此他进行了 q 次操作，操作有两种
操作 0：0 x y z ，将下标为 (x,y) 处的药材改为 z 药材
操作 1：1 x1 y1 x2 y2 ，询问矩形 (x1 ≤ x ≤ x2, y1 ≤ y ≤ y2) 区域内不同的药材各出现了多少次
输入
多组数据。
每组数据第一行两个整数 n，m（1 ≤ n, m ≤ 1000）。
接下来 n 行，每行一个长度为 m 的字符串。
接下来一个整数 q (q ≤ 20000)，下面 q 行代表要处理的操作，格式如题意所示。

输出
对于每个操作 1 输出一行，每行 26 个整数，表示 a-z 药材出现的次数，用一个空格分割，行末不允许有
多余空格。
样例输入 Copy
3 3
aaa
bbb
ccc
3
1 2 1 2 2
0 2 2 z
1 1 1 2 3
5 4
abcd
bcda
cdab
dabc
abcd
4
0 4 1 x
1 1 2 2 4
0 2 1 l
1 1 1 3 3
样例输出 Copy
0 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0
3 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1
1 1 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0
2 1 3 2 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0
*/

//超时

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int C[30][maxn][maxn], ans[30];
string mat[maxn];
int n, m;
int lowbit(int y)
{
    return y & (-y);
}
void add(int ch, int x, int y, int d)
{
    while (y <= m)
    {
        C[ch][x][y] += d;
        y += lowbit(y);
    }
}
int sum(int ch, int x, int y)
{
    int ret = 0;
    while (y > 0)
    {
        ret += C[ch][x][y];
        y -= lowbit(y);
    }
    return ret;
}
int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> mat[i];
            mat[i] = "0" + mat[i];
            for (int j = 1; j <= m; j++)
            {
                add(mat[i][j] - 'a', i, j, 1);
            }
        }
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int op;
            scanf("%d", &op);
            if (op == 0)
            {
                int x, y;
                scanf("%d%d", &x, &y);
                getchar();
                char z;
                scanf("%c", &z);
                add(mat[x][y] - 'a', x, y, -1);
                mat[x][y] = z;
                add(mat[x][y] - 'a', x, y, 1);
            }
            else
            {
                memset(ans, 0, sizeof(ans));
                int x1, x2, y1, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                for (int i = x1; i <= x2; i++)
                {
                    for (int ch = 0; ch < 26; ch++)
                    {
                        ans[ch] += sum(ch, i, y2) - sum(ch, i, y1 - 1);
                    }
                }
                printf("%d", ans[0]);
                for (int i = 1; i < 26; i++)
                    printf(" %d", ans[i]);
                printf("\n");
            }
        }
        memset(C, 0, sizeof(C));
    }
    return 0;
}