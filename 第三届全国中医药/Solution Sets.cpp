/*
题目描述
For any positive integer N, there is an integer equation: 1/X1+1/X2···1/Xn = 1 

For a given integer m, find the number of different solution sets of the integer equation when at most one Xi

is allowed to be greater than m. Note that all the Xi(i ∈ [1, n]) should be positive integers
输入
There are several test files and each contains one case.
The input has one line, and there are 2 positive integers separated by space, which are respectively n, m
(n ≤ 20, m ≤ 150)
输出
The output is a single line, which is the total number of different solution sets.
样例输入 Copy
3 6
样例输出 Copy
3
提示
As for the example, there are three solution sets, that is { 2,3,6 } ,{ 3,3,3 } and { 2,4,4 }.
Equality of sets is defined as set A is said to be equal to set B if both sets have the same elements or
members of the sets, i.e. if each element of set A also belongs to each element of set B, and each element
of set B also belongs to each element of set A.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, ans = 0;
const ll mx = 1e15;
void dfs(int cur, int last, ll b, ll a)
{
    if (b * last + (n - cur + 1) * a < a * last)
        return;
    if (b * m + (n - cur) * last >= a * m)
        return;
    if (cur == n)
    {
        if (a % (a - b) == 0)
            ans++;
        return;
    }
    if (b > mx)
    {
        ll k = __gcd(a, b);
        a /= k, b /= k;
    }
    for (int i = last; i <= m; i++)
        dfs(cur + 1, i, b * i + a, a * i);
}
int main()
{
    scanf("%d%d", &n, &m);
    dfs(1, 1, 0, 1);
    printf("%d\n", ans);
    return 0;
}