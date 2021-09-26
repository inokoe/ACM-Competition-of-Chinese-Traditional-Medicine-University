/*
Description
DongDong is fond of numbers, and he has a positive integer P. Meanwhile, there is a rule that is:

A positive integer D that satisfies the following rules:

1.       D is one of the factors of P

2.       D and P have a same bit at least under the binary system.

So DongDong wants to know how many positive integers D there are.

Input
The first line contains a positive integer T (T<=1000), which means the number of test cases. Then comes T lines, each line contains a positive integer P (1<=P<=1000000000).

Output
For each test case, print the number of positive integers D that satisfies the rules.

Sample Input
2
1
10
Sample Output
1
2
*/
#include <bits/stdc++.h>
using namespace std;
long long x, d, y, z;
bool judge(long long aa, long long bb)
{
    //cout<< aa << ' '<<bb<<endl;
    while (aa > 0 && bb > 0)
    {
        //cout << aa << ' ' << bb << endl;
        if (aa & 1 && bb & 1)
        {
            //cout << "yes" << endl;
            return true;
        }
        if (!(aa & 1) && !(bb & 1))
        {
            //cout << "yes" << endl;
            return true;
        }
        aa >>= 1;
        bb >>= 1;
    }
    return false;
}
int main()
{

    cin >> x;
    while (x--)
    {
        cin >> d;
        int ans = 0;
        if (d == 0)
        {
            cout << ans << endl;
            continue;
        }
        if (d % 2 != 0 && d >= 2)
            ans = 2;
        else
            ans = 1;
        for (long long i = 2; i <= sqrt(d); i++)
        {
            if (d % i == 0)
            {
                if (judge(i, d))
                    ans++;
                if (judge(d / i, d))
                    ans++;
            }
            if(i == sqrt(d))ans--;
        }
        cout << ans << endl;
    }
    return 0;
}
