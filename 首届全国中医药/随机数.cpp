/*
Description
有一个rand(n)的函数，它的作用是产生一个在[0,n)的随机整数。现在有另外一个函数，它的代码如下：

int random(int n, int m)

{

         return rand(n)+m;

}

显而易见的是函数random(n,m)可以产生任意范围的随机数。现在问题来了，如果我想要产生范围在[a,b)内的一个随机数，那么对应的n，m分别为多少？

Input
输入的第一行为一个正整数T (T<=1000)，表示一共有T组测试数据。

对于每组测试数据包含两个整数a，b (a<=b)。

Output
对于每组测试数据，输出一行包含两个整数n和m，两个整数中间有一个空格分隔。

Sample Input
2
0 5
1 4
Sample Output
5 0
3 1
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x, y, z;
    cin >> x;
    while (x--)
    {
        cin >> y >> z;
        cout << z - y << ' ' << y << endl;
    }
    return 0;
}
