/*
题目描述
如果一个字符串可以由某个长度为k的字符串重复多次得到，我们说该串以k为周期。例如abcabcabcabc以3为周期（当然他也以6，12为周期）。输入一个长度不超过100000的串，输出他的最小周期。

输入
多组测试数据,每组仅一行为一个仅有大写字母组成的字符串。

输出
对于每组数据输出该字符串的最小周期。

样例输入 Copy
HOHO
样例输出 Copy
2
*/

//字符串的周期必然可整除其的长度，对一个周期，在每个周期内的各个位置必然相等

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
char str[N];
int main()
{
    while (~scanf("%s", str))
    {
        bool flag = false;
        int l = strlen(str);
        for (int i = 1; i <= l; i++)
        {
            if (l % i == 0)
            {
                flag = true;
                for (int j = i; j < l; j++)
                {
                    if (str[j] != str[j % i])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}