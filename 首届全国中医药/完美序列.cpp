/*
Description
已知一个长度为l的序列：b1，b2，b3，…，bl (1<=b1<=b2<=b3<=…<=bl<=n)。若这个序列满足每个元素是它后续元素的因子，换句话说就是对于任意的i (2<=i<=l)都满足bi%bi-1=0 (其中“%”代表求余)，则称这个序列是完美的。你的任务是对于给定的n和l，计算出一共有多少序列是完美序列。由于答案很大，所有输出答案对1000000007取余后的结果。

Input
输入的第一行为一个正整数T (T<=1000)，代表一共有T组测试数据。

每组测试数据包含两个正整数n，l (1<=n, l<=2000)，分别代表序列中元素大小的最大值和序列的长度。

Output
对于每组测试数据，输出一行包含一个整数，代表答案对1000000007取余后的结果。

Sample Input
3
3 2
6 4
2 1
Sample Output
5
39
2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll f[2005][2005] = {0};
void init()
{
    for (int i = 1; i <= 2000; i++)
        f[1][i] = 1;
    for (int i = 1; i <= 2000; i++)
    {
        for (int j = 1; j <= 2000; j++)
        {
            for (int k = j; k <= 2000; k += j) //可以保证被前一个数整除
            {
                f[i + 1][k] = (f[i + 1][k] + f[i][j]) % MOD;
            }
        }
    }
}
int main()
{
    int T;
    init();
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        ll sum = 0;
        for (int i = 1; i <= n; i++)
            sum = (sum + f[m][i]) % MOD;
        printf("%lld\n", sum);
    }
    return 0;
}