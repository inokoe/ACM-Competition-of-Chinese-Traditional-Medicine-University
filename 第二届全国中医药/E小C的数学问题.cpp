/*
Description
小C是个云南中医学院的大一新生，在某个星期二，他的高数老师扔给了他一个问题。
让他在1天的时间内给出答案。
但是小C不会这问题，现在他来请教你。
请你帮他解决这个问题。
有n个数，每个数有权值。
数学老师定义了区间价值为区间和乘上区间内的最小值。
现在要你找出有最大区间价值的区间是什么，并输出区间价值。
Input
每个输入文件只包含单组数据。
第一行一个整数n。(1 <= n <= 100000)
第二行n个整数a_1,a_2,...,a_n。(0 <= a_i <= 1000000)

Output
第一行输出一个整数，表示最大的区间价值。
第二行输出两个整数，表示区间的起点和终点。
保证答案唯一。

Sample Input
6
10 1 9 4 5 9
Sample Output
108
3 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn], sum[maxn];
int L[maxn], R[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int l = i;
        while (a[i] <= a[l - 1] && l > 1)
            l = L[l - 1];
        L[i] = l;
    }
    for (int i = n; i >= 1; i--)
    {
        int r = i;
        while (a[i] <= a[r + 1] && r < n)
            r = R[r + 1];
        R[i] = r;
    }
    ll ans = -1;
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        ll val = (sum[R[i]] - sum[L[i] - 1]) * a[i];
        if (ans < val)
        {
            ans = val;
            l = L[i];
            r = R[i];
        }
    }
    printf("%lld\n", ans);
    printf("%d %d\n", l, r);
    return 0;
}