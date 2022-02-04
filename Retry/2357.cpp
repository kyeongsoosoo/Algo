#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 100001
#define INF 1987654321

using namespace std;

int N, M;
int arr[MAX];
vector<pair<int, int> > set;
int height;
int *min_tree;
int *max_tree;

int init(int node, int start, int end, bool isMin)
{
    if (start == end)
    {
        if (isMin)
            return min_tree[node] = arr[start];
        return max_tree[node] = arr[start];
    }
    int mid = (start + end) / 2;

    if (isMin)
        return min_tree[node] = min(init(node * 2, start, mid, true), init(node * 2 + 1, mid + 1, end, true));
    return max_tree[node] = max(init(node * 2, start, mid, false), init(node * 2 + 1, mid + 1, end, false));
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;
        set.push_back(make_pair(start, end));
    }

    height = ceil(log2(N));
    min_tree = new int[1 << (height + 1)];
    max_tree = new int[1 << (height + 1)];

    init(1, 0, N - 1, true);
    init(1, 0, N - 1, false);
}

int findFigure(int node, int start, int end, int left, int right, bool isMin)
{
    // cout << "start: " << left << " end: " << right << '\n';
    if (left > end || right < start)
    {
        if (isMin)
            return INF;
        return -INF;
    }
    if (start <= left && right <= end)
    {
        if (isMin)
            return min_tree[node];
        return max_tree[node];
    }

    int mid = (left + right) / 2;
    if (isMin)
        return min(findFigure(node * 2, start, end, left, mid, true), findFigure(node * 2 + 1, start, end, mid + 1, right, true));
    return max(findFigure(node * 2, start, end, left, mid, false), findFigure(node * 2 + 1, start, end, mid + 1, right, false));
}

void solve()
{
    for (int i = 0; i < set.size(); i++)
    {
        pair<int, int> p = set[i];
        int start = p.first - 1;
        int end = p.second - 1;

        cout << findFigure(1, start, end, 0, N - 1, true) << " " << findFigure(1, start, end, 0, N - 1, false) << '\n';
    }
}

int main()
{
    input();
    solve();
}