#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
struct node
{
    string name;
    int score;
} a[maxn];
int b[maxn] = {0};

bool cmp(node x, node y)
{
    return x.score != y.score ? x.score > y.score : x.name < y.name;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name;
        scanf("%d", &a[i].score);
    }
    int m;
    scanf("%d", &m);
    memset(b, 0, sizeof(b));
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    string s;
    cin >> s;
    int grade, pm = 0;
    sort(a, a + n, cmp);
    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i].name == s)
        {
            grade = a[i].score;
            pm = i;
            break;
        }
    }
    int pm1 = n, pm2 = 1;
    //good
    int grade1 = grade + b[n - 1];
    int now = n - 2;
    for (int i = n - 1; i >= 0 && now >= 0; i--)
    {
        if (i != pm)
        {
            while (now >= 0)
            {
                //cout<<(a[i].score+b[now]<grade1)<<"----1\n";
                //cout<<(a[i].score+b[now]==grade1&&a[i].name>a[pm].name)<<"---\n";
                if (a[i].score + b[now] < grade1 || (a[i].score + b[now] == grade1 && a[i].name > a[pm].name))
                {
                    pm1--;
                    break;
                }
                now--;
            }
            now--;
            if (now < 0)
                break;
        }
    }
    //bad
    int grade2 = grade + b[0];
    now = 1;
    for (int i = 0; i < n && now < n; i++)
    {
        if (i != pm)
        {
            while (now < n)
            {
                if (a[i].score + b[now] > grade2 || (a[i].score + b[now] == grade2 && a[i].name < a[pm].name))
                {
                    pm2++;
                    break;
                }
                now++;
            }
            if (now >= n)
                break;
        }
    }
    printf("%d %d\n", pm1, pm2);
    return 0;
}