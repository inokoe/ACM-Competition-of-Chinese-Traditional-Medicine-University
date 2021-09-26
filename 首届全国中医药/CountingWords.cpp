/*
Description
DongDong prefers English words to English sentences, so he wants to count the words of a sentence. Could you help him?

Input
The first line contains a positive integer T (T<=1000), which means T test cases. Then comes T lines, each line contains a string which combines with several words separated by spaces. Note that there may be more than one space to separate two words.

Output
For each test case, please print the number of words of the sentence.

Sample Input
3
 Every night in my dreams
   I see you  I feel you   
That  is  how I know you go on
Sample Output
5
6
8
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    cin.ignore();
    while (x--)
    {
        string s;
        getline(cin, s);
        int ans = 0;
        bool flag = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                flag = false;
            if (s[i] != ' ')
            {
                if (flag == false)
                    ans++;
                flag = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
