/*
Description
在天赋系统中，一共有n个技能，编号依次为1到n，每个技能可以学习很多级，也可以不学习。


一共有m点技能点，第i个技能每往上多点一级需要消耗c_i点技能点。


有些技能存在前置技能，一共有k对前置关系，第i对关系为：学习技能v_i需要前置技能u_i。如果u_i学习了0级，那么不能学习v_i。一个技能可以学习当且仅当它的所有前置技能都学习了至少一级。


请对于每个k=1,2,3,...,m计算，有多少种点技能的方式满足刚好消耗了k点技能点。两个方案不同当且仅当某个技能的学习等级在两个方案中不同。
Input
第一行包含一个正整数T(1 <= T <= 10)，表示测试数据的组数。


每组测试数据第一行包含三个正整数n,m,k(1 <= n <= 15, 1 <= m <= 1000, 1 <= k <= n * (n-1) / 2)，分别表示技能的数量、技能点的数量以及前置关系的数量。


第二行包含n个正整数c_1,c_2,...,c_n(1 <= c_i <= m)，依次表示每个技能所需的技能点。


接下来k行，每行包含两个正整数u_i,v_i(1 <= u_i < v_i <= n)，描述一对前置关系。输入数据保证同一对关系不会被输入多次。
Output
对于每组数据，输出一行m个整数ans_1,ans_2,...,ans_m，其中ans_i表示恰好消耗i点技能点的方案数。因为答案可能很大，请对10^9+7取模输出。
Sample Input
1
3 8 1
2 4 3
1 3
Sample Output
0 1 0 2 1 2 1 4
*/

//https://acm.zcmu.edu.cn/JudgeOnline/problem.php?id=5078

#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
vector<long long> ans;
map<int, int> mp;
map<string, long long> status;
int n, m, k, a, b;
void dfs(vector<int> &point, int used, vector<int> &skills)
{
    for (int i = 0; i < n; i++)
    {
        if (mp[i + 1] > 0 && skills[mp[i + 1] - 1] <= 0)
        {
            continue;
        }
        used += point[i];

        if (used > m)
        {
            used -= point[i];
            continue;
        }
        skills[i]++;
        stringstream sts;
        reverse_copy(skills.begin(), skills.end(), ostream_iterator<int>(sts, ""));
        if (!(status[sts.str()] > 0))
        {
            status[sts.str()]++;
            ans[used]++;
            ans[used] = ans[used] % mod;
            dfs(point, used, skills);
        }
        used -= point[i];
        skills[i]--;
    }
}

int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    while (x--)
    {
        status.clear();
        cin >> n >> m >> k;
        vector<int> point(n);
        vector<int> skills(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            point[i] = a;
        }
        for (int i = 0; i < k; i++)
        {
            cin >> a >> b;
            mp[b] = a;
        }
        ans.resize(m + 1);
        dfs(point, 0, skills);
        for (int i = 1; i <= m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
        ans.clear();
        mp.clear();
    }
    return 0;
}