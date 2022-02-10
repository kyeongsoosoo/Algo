#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 100002

using namespace std;

int n, m, dep[MAX], MAX_K, parent[MAX][20];
bool vis[MAX];
vector<int> e[MAX];

void make_tree(int here, int depth)
{
    vis[here] = true;
    dep[here] = depth;

    for (int i = 0; i < e[here].size(); i++)
    {
        int next = e[here][i];
        if (vis[next])
            continue;
        parent[next][0] = here;
        make_tree(next, depth + 1);
    }
}

void fill_parent()
{
    for (int k = 1; k <= MAX_K; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
        }
    }
}

int lca(int swall, int deep)
{
    if (dep[deep] < dep[swall])
    {
        swap(deep, swall);
    }

    for (int k = MAX_K; k >= 0; k--)
    {
        int diff = dep[deep] - dep[swall];
        if (diff >= (1 << k))
        {
            deep = parent[deep][k];
        }
    }

    if (deep == swall)
        return deep;

    for (int k = MAX_K; k >= 0; k--)
    {
        if (parent[deep][k] != parent[swall][k])
        {
            deep = parent[deep][k];
            swall = parent[swall][k];
        }
    }
    return parent[deep][0];
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int src, dst;
        cin >> src >> dst;
        e[src].push_back(dst);
        e[dst].push_back(src);
    }

    make_tree(1, 0);

    MAX_K = (int)floor(log2(n));

    fill_parent();
}

void solve()
{
    cin >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}

int main()
{
    input();
    solve();
}