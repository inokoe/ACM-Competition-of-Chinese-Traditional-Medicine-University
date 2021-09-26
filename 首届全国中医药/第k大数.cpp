/*
Description
有两个序列a，b，它们的长度分别为n和m，那么将两个序列中的元素对应相乘后得到的n*m个元素从大到小排列后的第k个元素是什么？

Input
输入的第一行为一个正整数T (T<=10)，代表一共有T组测试数据。

每组测试数据的第一行有三个正整数n，m和k(1<=n, m<=100000,1<=k<=n*m)，分别代表a序列的长度，b序列的长度，以及所求元素的下标。第二行为n个正整数代表序列a。第三行为m个正整数代表序列b。序列中所有元素的大小满足[1,100000]。

Output
对于每组测试数据，输出一行包含一个整数代表第k大的元素是多少。

Sample Input
3
3 2 3
1 2 3
1 2
2 2 1
1 1
1 1
2 2 4
1 1
1 1
Sample Output
3
1
1
*/

//二分

#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    int ct = 0;
    cin >> ct;
    while (ct--)
    {
        cin >> n >> m >> k;
        long long va[n];
        long long vb[m];
        for (long long i = 0; i < n; i++)
            cin >> va[i];
        for (long long i = 0; i < m; i++)
            cin >> vb[i];
        sort(va, va+n);
        sort(vb, vb+m);
        long long l, r, mid, ans;
        l = va[0] * vb[0];
        r = va[n - 1] * vb[m - 1];

        while (l <= r)
        {
            mid = (l + r) / 2;

            long long sum = 0;
            long long j = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                for (; j <= m - 1; j++)
                {
                    if (va[i] * vb[j] >= mid)
                    {
                        sum += (m - j);
                        break;
                    }
                }
                if (sum >= k)
                    break;
            }
            if (sum >= k)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}