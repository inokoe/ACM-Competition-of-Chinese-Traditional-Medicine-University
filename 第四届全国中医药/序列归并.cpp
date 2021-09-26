/*
Description
Alice 和Bob 正在对两个序列a1, a2,..., an 和b1, b2,...,bm 进行操作。
Alice 首先需要将它们归并成一个长度为n + m 的序列c1,c2,...,cn+m。即将序列a 和b 合并成一个序列c，但不改变a 和b 的顺序。显然可能有许多许多种不同的归并结果。
Bob 需要在Alice 完成归并之后， 选择一对l,r， 满足1 ≤ l ≤ r ≤ n + m， 并使得score = cl + cl+1 + cl+2 + ...+ cr−1 + cr 尽可能地大。
不同的归并结果以及不同的选择l,r 的方式都会使得最后score 的值不尽相同，请问score 最多能达到多少呢？

Input
第一行包含一个正整数T(1 ≤ T ≤ 10)，表示测试数据的组数。
每组测试数据第一行包含两个正整数n,m(1 ≤ n,m ≤ 100000)，分别表示序列a 和序列b 的长度。
第二行包含n 个整数a1, a2,..., an(−109 ≤ ai ≤ 109)。
第三行包含m 个整数b1,b2,..., bm(−109 ≤ bi ≤ 109)。
输入数据保证a 和b 中至少有一个正数。
Output
对于每组测试数据，输出一行一个整数，即score 的最大值。
Sample Input
1
2 3
1 5
3 -1 -1
Sample Output
9
HINT
一种可能的归并结果是c = [1, 3, 5,−1,−1]，选择l= 1, r = 3，则score = c1 + c2 + c3 = 9。
*/

//https://acm.zcmu.edu.cn/JudgeOnline/problem.php?id=5070

//基础题，不需要分析归并序列，因为总能将两个序列的最大的子序列连续，故分别计算相加即可

#include <bits/stdc++.h>
using namespace std;

long long cal(long long x)
{
    long long tp = 0, tp_sum = 0, tp_ans = 0;
    for (int i = 0; i < x; i++)
    {
        cin >> tp;
        tp_sum += tp;
        if (tp_sum > tp_ans)
        {
            tp_ans = tp_sum;
        }
        else if (tp_sum < 0)
        {
            tp_sum = 0;
        }
    }
    return tp_ans;
}

int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    long long x, n, m;
    cin >> x;
    while (x--)
    {
        cin >> n >> m;
        cout << cal(n) + cal(m) << endl;
    }
    return 0;
}