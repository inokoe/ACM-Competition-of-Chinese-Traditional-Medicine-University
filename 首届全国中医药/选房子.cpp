/*
Description
栋栋和李剑已经大四了，想要出去找房子住。他们一共看中了n套房子。其中第i套房子已经住了ai个人了，它最多能住bi个人。栋栋和李剑想要住在一起，那么请问他们有几套可以选择的房子？

Input
输入的第一行为一个正整数T (T<=1000)，代表一共有T组测试数据。

每组测试数据的第一行有一个正整数n (1<=n<=100)，代表一共有n套房子。接下来n行，每行有两个正整数ai，bi (1<=ai<=bi<=100)，分别代表现在已经住了ai个人和最多能住bi个人。

Output
对于每组测试数据，输出一行包含一个整数，代表他们可以选择房子的数量。

Sample Input
2
2
1 2
1 3
3
1 10
2 10
3 10
Sample Output
1
3
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, d, y, z;
    cin >> x;
    while (x--)
    {
        cin >> d;
        int ans = 0;
        while (d--)
        {
            cin >> y >> z;
            if (z - y >= 2)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
