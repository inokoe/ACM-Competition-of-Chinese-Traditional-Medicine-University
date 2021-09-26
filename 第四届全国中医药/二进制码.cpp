/*
Description
在计算机中，对于定点数有三种不同的表示方法。在本题中，假定码的长度固定为8位，从左往右依次编号为第1到8位，第1位为最高位。


x的原码：最高位为符号位，正数符号位为0，负数符号位为1，第2到7位为x的二进制表示。正负0的原码不同。


x的反码：原码符号位除外，其他位按位取反，即1变0，0变1。


x的补码：正数的补码等于原码，负数的补码等于反码+1，因此正负0的补码相同。


给定整数x，请给出它的原码、反码和补码。
Input
第一行包含一个正整数T(1 <= T <= 300)，表示测试数据的组数。


每组测试数据包含一行，首先是一个符号+或-，表示x的正负，然后是一个非负整数y(0 <= y <= 100)，表示x的绝对值为y。
Output
对于每组数据，输出三行，第一行为原码，第二行为反码，第三行为补码。
Sample Input
4
+0
+1
-0
-3
Sample Output
00000000
01111111
00000000
00000001
01111110
00000001
10000000
11111111
00000000
10000011
11111100
11111101
HINT
*/

//https://acm.zcmu.edu.cn/JudgeOnline/problem.php?id=5079

//注意特殊个例 ： -0  ， -0 的补码是 0000 0000

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    while (x--)
    {
        string s, sign = "";
        cin >> s;
        if (s[0] == '+')
            sign = "0";
        else
            sign = "1";
        int num = 0;
        s = s.substr(1, s.size());
        stringstream sts;
        sts << s;
        sts >> num;
        bitset<7> bst1(num);
        bitset<7> bst2(127 - num);
        cout << sign << bst1 << endl;
        if (sign == "0")
        {
            cout << sign << bst2 << endl;
            cout << sign << bst1 << endl;
        }
        else
        {
            bitset<7> bst3(127 - num + 1);
            cout << sign << bst2 << endl;
            if(num == 0)cout<<"00000000"<<endl;
            else cout << sign << bst3 << endl;
        }
    }
    return 0;
}