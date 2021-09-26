/*
题目描述
There is a N×N matrix. Dr.L want to choose N grid from the matrix and number them with different
number from 1 to N. At the same time, he doesn’t like the grid numbered with i locate in the i-th row
or the i-th column. And any two selected grids cannot be in the same row or in the same column. How
many schemes can Dr.L find? Please output the answer modulo M.

输入
There are several test files and each contains one case.
Two positive initegers N and M (N ≤ 1015, M ≤ 106)

输出
The number of schemes modulo M.
样例输入 Copy
2 1000
样例输出 Copy
1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
ll f[maxn];
int main()
{
    ll n, m;
    cin >> n >> m;
    n %= m;
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= m; i++)
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % m;
    ll ans = f[n] * f[n] % m;
    printf("%lld\n", ans);
    return 0;
}