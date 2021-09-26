/*
题目描述
湖南中医药大学坐落于中国历史文化名城长沙，是湖南省重点建设本科院校，是全国首批设立国家级重
点学科的高校，也是首批招收博士研究生、留学生及港澳台学生的中医药院校。学校现有 2 个校区，占
地面积 1393 亩，建筑面积 52 万平方米，主校区依岳麓南坡，临湘江西岸，环境幽雅，风光秀丽，是求
学成才的理想之地。
校园景观设计师小 W 的主要工作就是植被环境的设计维护，他有一个 N×N 的模板图，他创作景观的步
骤如下：
1、将当前的绿地分成 N×N 小块，再按照模板图添加装饰（黑色表示有装饰，白色表示没有）；
2、对于每个白色（未被装饰）的地块，递归操作 1，应用模板图，即分成更小的 N×N 块，继续进行装
饰，而黑色（已装饰）的地块则不必操作。
下图是某次装饰过程的示意图。



现在你的任务是求出 K 次递归后的绿地状态。

输入
单组数据。
第一行两个数 N,K，如题意中的描述。
接下来是一个 N×N 的模板图，’ . ’ 表示白色，’ * ’ 表示黑色。
2 ≤ n ≤ 3
1 ≤ k ≤ 5

输出
输出一个 N K×N K 的矩阵表示答案，不允许有多余的空行或空格。
样例输入 Copy
2 3
.*
..
样例输出 Copy
.*******
..******
.*.*****
....****
.***.***
..**..**
.*.*.*.*
........
*/

#include <bits/stdc++.h>
using namespace std;
vector<string> Origin;
vector<string> Next;
vector<string>rec;
int x, y;
string s;
int main()
{
    cin >> x >> y;
    while (cin >> s){
                Origin.push_back(s);
                rec.push_back(s);
    }
    y--;
    while (y--)
    {

        for (int i = 0; i < Origin.size(); i++)
        {
            string lineA = "", lineB = "",lineC="";
            for (int z = 0; z < Origin[i].size(); z++)
            {
                if (Origin[i][z] == '.')
                {
                    lineA += rec[0];
                    lineB += rec[1];
                    if(rec.size()==3)lineC+=rec[2];
                }
                else
                {
                    for(int q = 0 ; q < rec.size(); q++)lineA+="*";
                    for(int q = 0 ; q < rec.size(); q++)lineB+="*";
                    if(rec.size()==3)for(int q = 0 ; q < rec.size(); q++)lineC+="*";
                }
            }
            Next.push_back(lineA);
            Next.push_back(lineB);
            if(rec.size()==3)Next.push_back(lineC);
        }
        swap(Origin,Next);
        Next.clear();
    }
    for(auto i : Origin)cout<<i<<endl;
    return 0;
}