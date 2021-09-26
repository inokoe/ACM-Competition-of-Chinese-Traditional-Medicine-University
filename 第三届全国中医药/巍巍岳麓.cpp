/*
题目描述
岳麓山风景区位于湖南省长沙市岳麓区，占地面积 35.20 平方公里，是南岳衡山 72 峰的最后一峰，位于
橘子洲旅游景区内，为城市山岳型风景名胜区，是中国四大赏枫胜地之一。
岳麓山位于首批国家历史文化名城长沙市湘江西岸，依江面市，现有岳麓山、橘子洲、岳麓书院、新民学
会四个核心景区，为世界罕见的集“山、水、洲、城”于一体的国家 AAAAA 级旅游景区、国家重点风
景名胜区、湖湘文化传播基地和爱国主义教育的示范基地。
岳麓山因南朝宋时《南岳记》中“南岳周围八百里，回燕为首，岳麓为足”而得名，融中国古文化精华的
儒、佛、道为一体，包容了历史上思想巨子、高僧名道、骚人墨客共同开拓的岳麓山文化内涵。景区内有
岳麓书院、爱晚亭、麓山寺、云麓宫、新民学会旧址、黄兴墓、蔡锷墓、第九战区司令部战时指挥部旧址
等景点。
为了改善岳麓山周边的旅游环境，市长决定对道路进行改造，城市中有 n 个路口，有些交叉路口之间有
道路直接相连；两个交叉路口之间最多有一条道路相连接。这些道路是双向的，且能把所有的交叉路口直
接或间接连接起来。每条道路都有一个分值，分值越小表示这个道路越繁忙，越需要改造。但是市政府的
资金有限，市长希望进行改造的道路越少越好，于是提出了下面的要求，需要同时满足：
1、改造的那些道路能把所有的交叉路口直接或间接地连通起来；
2、改造的道路尽量少且改造的那些道路中分值最大的道路的分值尽量小；
3、紧邻岳麓山的麓山南路必须改造。
请你做出规划设计，选择哪些道路应当改造。
输入
单组数据。
输入第一行有两个正整数 n 和 m，分别表示城市有 n 个交叉路口，m 条道路 (n <= 3000，m<=4000)。
接下来 m 行是对每条道路的描述，u，v，c 表示交叉路口 u 和 v 之间有道路相连，分值为 c(分值不会超
过 int)。最后一行两个正整数 s 和 t，表示麓山南路在交叉路口 s 和 t 相连的路上。
输出
输出两个整数 tot，max，表示你选出了几条道路，分值最大的那条的道路的分值是多少。
*/
#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 4e5 + 10;
typedef long long ll;

struct node
{
    int l, r, w;
} a[maxn];
int pre[maxn];
int n, m, s, t, ans;

bool cmp(node a, node b) { return a.w < b.w; }
int findd(int x) { return x == pre[x] ? x : findd(pre[x]); }

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].w);
    sort(a + 1, a + 1 + m, cmp);
    int index, maxx;
    scanf("%d%d", &s, &t);
    for (int i = 1; i <= m; i++)
        if ((a[i].l == s && a[i].r == t) || (a[i].l == t && a[i].r == s))
        {
            index = i;
            break;
        }
    ans = inf;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            pre[j] = j;
        pre[s] = t; //必须连通的路，先加进去
        maxx = a[index].w;
        int k = 1;
        for (int j = i; j <= m; j++)
        {
            int xx = findd(a[j].l), yy = findd(a[j].r);
            if (xx != yy)
            {
                pre[yy] = xx;
                k++;
                maxx = max(maxx, a[j].w);
                if (k == n - 1)
                    break;
            }
        }
        if (k == n - 1) //能够形成生成树
            ans = min(ans, maxx);
    }
    printf("%d %d\n", n - 1, ans);
    return 0;
}
