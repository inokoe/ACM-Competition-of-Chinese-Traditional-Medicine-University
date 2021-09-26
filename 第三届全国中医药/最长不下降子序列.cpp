/*
题目描述
给定一个序列 a，求去除 a 中一段连续长度为 L 的序列后，a 的最长不下降子序列的长度的最大值。
输入
单组数据。
第一行两个整数 n,L 表示序列的长度为 n，L 如题意所示。
第二行 n 个数表示序列 a
n ≤ 105, 0 ≤ L ≤ n
输出
输出一个整数表示最长不下降子序列长度的最大值
样例输入 Copy
6 3
2 1 3 6 4 5
样例输出 Copy
3
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int n, l, ans = 0, cnt = 0;
struct A
{
    int val, id;
} a[maxn];
int b[2][maxn], c[2][maxn], id[maxn];
bool cmp(A x, A y) { return x.val < y.val; }
int lowbit(int x) { return x & (-x); }
void add(int k, int x, int d)
{
    while (x <= cnt)
    {
        c[k][x] = max(c[k][x], d);
        x += lowbit(x);
    }
}
int sum(int k, int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret = max(c[k][x], ret);
        x -= lowbit(x);
    }
    return ret;
}
int main()
{
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].val), a[i].id = i;
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (a[i].val == a[i - 1].val)
            id[a[i].id] = cnt;
        else
            id[a[i].id] = ++cnt;
    }

    for (int i = 1; i <= n; i++)
    {
        b[0][i] = sum(0, id[i]) + 1;
        add(0, id[i], b[0][i]);
        if (i > l)
        {
            b[1][i] = sum(1, id[i]) + 1;
            add(1, id[i], b[1][i]);
            add(1, id[i - l], b[0][i - l]);
        }
        ans = max(ans, b[1][i]);
    }
    for (int i = 1; i <= n - l; i++)
        ans = max(ans, b[0][i]);
    printf("%d\n", ans);
    return 0;
}