/*
Description
有一个长度为n的正整数序列，一个序列的混乱程度定义为这个序列的最大值和最小值之差。请编写一个程序，计算一个序列的混乱程度。

Input
输入的第一行为一个正整数T (T<=1000)，表示一共有T组测试数据。

每组测试数据的第一行为一个正整数n (1<=n<=1000)，代表这个序列的长度。第二行为n个正整数，代表这个序列。序列中元素的大小不会超过1000。

Output
对于每个测试数据，输出一行包含一个整数，代表对应序列的混乱程度。

Sample Input
2
5
1 2 3 4 5
5
1 9 2 4 8
Sample Output
4
8
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x, y, z;
    cin >> x;
    while (x--)
    {
        vector<long long> vec;
        cin >> y;
        while (cin >> z)
        {
            y--;
            vec.push_back(z);
            if (y == 0)
                break;
        }
        cout << *max_element(vec.begin(), vec.end()) - *min_element(vec.begin(), vec.end()) << endl;
    }
    return 0;
}
