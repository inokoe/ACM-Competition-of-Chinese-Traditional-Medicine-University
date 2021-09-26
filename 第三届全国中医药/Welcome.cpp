/*
题目描述
”How happy we are, To meet friends from afar!”
Welcome to Hunan University of Chinese Medicine!
Hope all of you can enjoy the competition ^ v ^
Now your task is to read an integer w and output the character painting of ”HNUCM”, there are w
space(s) (space are represented by dot) between two letters. Please refer to the sample for the specific
format.
输入
There are several test files and each contains one case.
The input contains only 1 integer w (1 ≤ w ≤ 2018).
输出
The output has 5 lines, each line has 25+4w characters which only contains ’o’(lowercase letter ’o’) and
’.’(English period ’.’)
样例输入 Copy
1
样例输出 Copy
o...o.o...o.o...o.ooooo.o...o
o...o.oo..o.o...o.o.....oo.oo
ooooo.o.o.o.o...o.o.....o.o.o
o...o.o..oo.o...o.o.....o...o
o...o.o...o.ooooo.ooooo.o...o
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    vector<string> vec(5);
    vec[0] = "o...o*o...o*o...o*ooooo*o...o";
    vec[1] = "o...o*oo..o*o...o*o....*oo.oo";
    vec[2] = "ooooo*o.o.o*o...o*o....*o.o.o";
    vec[3] = "o...o*o..oo*o...o*o....*o...o";
    vec[4] = "o...o*o...o*ooooo*ooooo*o...o";
    string supply = "";
    while(x--)supply+=".";
    for (int i = 0; i < vec.size(); i++)
    {
        string tp = "";
        for(int z = 0 ; z < vec[i].size(); z++){
            if(vec[i][z] != '*')tp+=vec[i][z];
            else{
                cout<<tp<<supply;
                tp="";
            }
        }
        cout<<tp<<endl;
    }
    return 0;
}