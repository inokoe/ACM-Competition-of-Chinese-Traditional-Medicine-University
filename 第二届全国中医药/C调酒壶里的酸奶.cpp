/*
Description
最近小w学了一手调酒的技巧，这么帅的操作，说不定能靠这个俘获女神的芳心，为了在女神面前露一手，他想在学校里建一个"pub"，但是显然学校不可能让他真的建一个"pub"，那么他退而求次，想建一个"Yogurt shop"，不能用酒，那用酸奶也行啊！
今天女神终于来光顾小w的酸奶店了！兴奋的小w拿出自己准备已久每天都仔细擦干净的装备——调酒壶、果汁机、隔冰器和计量杯、砧板、小刀....准备露一手给女神看看
但是女神却没有那么多耐心，女神只是觉得，自己买一瓶大酸奶喝不完，小瓶酸奶不够喝，所以在小w的酸奶店，说不定她可以想买多少就买多少。
于是女神告诉了小w她想要多少体积的酸奶，而小w却依旧想秀一下自己的操作，于是他决定用仅有的两个调酒壶为女神倒出女神想要的酸奶....
小w的两个调酒壶体积是不同的(一开始都是空的)，小w每次可以选择一个调酒壶倒入另一个调酒壶（若A倒入B，A倒完或B倒满则停止），或者选择一个调酒壶倒光，或者选择一个调酒壶去接满酸奶.....
满心失望的小w想找一朵花，一瓣一瓣的撕下来，问问花朵女神到底喜不喜欢他...虽然这个答案是显而易见的，但是他还是想找一朵花...然而找花未果，反正花瓣不是偶数就是奇数，那他索性就用自己的操作次数作为花瓣个数吧！（找不到花我还不能脑补一朵吗...）
但是小w已经没有心情去想答案了...那么你能告诉他，需要多少步操作才能倒出女神想要的酸奶吗？

Input
输入包含多组数据，每行三个正整数a,b,c分别表示两个调酒壶的容量以及女神想要的酸奶体积,a,b的范围都在[0,100]，c<=max(a,b)   

Output
一行包含一个整数表示完成要求的最少操作次数，若达不到则输出"impossible"（没有双引号）

Sample Input
10 15 11
6 5 4
Sample Output
impossible
4
*/

#include <bits/stdc++.h>
using namespace std;
int a, b, c, ans;
const int inf = 0x3f3f3f3f;
bool vis[105][105];
void dfs(int na, int nb, int cur)
{
    if (vis[na][nb])
        return;
    if (cur > ans)
        return;
    if (na == c || nb == c)
    {
        ans = min(ans, cur);
        return;
    }
    vis[na][nb] = true;
    dfs(a, nb, cur + 1);
    dfs(na, b, cur + 1);
    dfs(0, nb, cur + 1);
    dfs(na, 0, cur + 1);
    dfs(max(0, na - (b - nb)), min(b, na + nb), cur + 1);
    dfs(min(a, nb + na), max(0, nb - (a - na)), cur + 1);
    vis[na][nb] = false;
}
int main()
{
    while (scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        if (c % __gcd(a, b) != 0)
        {
            puts("impossible");
            continue;
        }
        ans = inf;
        dfs(0, 0, 0);
        printf("%d\n", ans);
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}

/*
//方法二
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 105;

int A, B, C;
int dis[maxn][maxn], vis[maxn][maxn];

struct node
{
    int a, b;
    node(int a, int b) : a(a), b(b){};
};

int bfs()
{
    queue<node> q;
    dis[0][0] = 0;
    vis[0][0] = 1;
    q.push(node(0, 0));
    while (!q.empty())
    {
        node x = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++)
        {
            int X, Y;
            if (i == 1)
            {
                X = A;
                Y = x.b;
            }
            if (i == 2)
            {
                X = x.a;
                Y = B;
            }
            if (i == 3)
            {
                X = 0;
                Y = x.b;
            }
            if (i == 4)
            {
                X = x.a;
                Y = 0;
            }
            if (i == 5)
            {
                if (x.a + x.b > B)
                {
                    X = x.a + x.b - B;
                    Y = B;
                }
                else
                {
                    X = 0;
                    Y = x.a + x.b;
                }
            }
            if (i == 6)
            {
                if (x.a + x.b > A)
                {
                    X = A;
                    Y = x.a + x.b - A;
                }
                else
                {
                    X = x.a + x.b;
                    Y = 0;
                }
            }
            if (!vis[X][Y])
            {
                vis[X][Y] = 1;
                dis[X][Y] = dis[x.a][x.b] + 1;
                if (X == C || Y == C)
                    return dis[X][Y];
                q.push(node(X, Y));
            }
        }
    }
    return -1;
}

int main()
{
    int ans;
    while (~scanf("%d%d%d", &A, &B, &C))
    {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        ans = bfs();
        if (ans != -1)
            cout << ans << endl;
        else
        {
            cout << "impossible" << endl;
        }
    }
    return 0;
}
*/
