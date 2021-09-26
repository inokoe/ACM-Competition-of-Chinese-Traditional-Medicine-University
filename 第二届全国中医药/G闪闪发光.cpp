/*
给出一组数，表示2的多少次方，之后将这些分成几组，要求分成的几组依然是2的多少次幂，就是说把其中的几组求和让和依然保持是2的多少次幂。
不难发现这样一个规律，两个2的一次方等于一个2的平方，所以只需要先记录一下每种幂次出现的次数，然后不断向上进位
以样例来说，两个1次方进位成一个平方，然后和已有的一个平方进位成一个三次方，已有的两个三次方进位成一个四次方，所以最后要分成两组。
注意：set超时
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000500];
int main()
{
    int n, x;
    while (cin >> n)
    {
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            a[x]++;
        }
        for (int i = 0; i <= 1000500; i++)
        {
            a[i + 1] += a[i] / 2;
            if (a[i] % 2 == 1)
                ans++;
        }
        printf("%lld\n", ans);
        memset(a, 0, sizeof(a));
    }
    return 0;
}