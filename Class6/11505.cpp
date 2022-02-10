#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define DIVIDER 1000000007

using namespace std;

int N, M, K;
vector<long long> map;
vector<long long> seg;

long long make_seg(int node, int left, int right)
{
    if (left == right)
    {
        seg[node] = map[left];
        return seg[node];
    }

    int mid = (left + right) / 2;

    long long left_res = make_seg(node * 2, left, mid);
    long long right_res = make_seg(node * 2 + 1, mid + 1, right);

    return seg[node] = (left_res * right_res) % DIVIDER;
}

long long update(int node, int left, int right, long long before, long long to, int idx)
{
    if (idx < left || right < idx)
        return seg[node];

    if (left == right)
    {
        map[idx] = to;
        seg[node] = to;
        // cout << "done: " << seg[node] << '\n';
        return to;
    }
    int mid = (left + right) / 2;

    long long left_res = update(node * 2, left, mid, before, to, idx);
    long long right_res = update(node * 2 + 1, mid + 1, right, before, to, idx);

    return seg[node] = (left_res * right_res) % DIVIDER;
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        map.push_back(tmp);
    }

    int height = (int)ceil(log2(N));
    int tree_size = (1 << (height + 1));
    seg.resize(tree_size);

    make_seg(1, 0, N - 1);
}

long long find_query(int node, int start, int end, int left, int right)
{
    if (start > right || left > end)
    {
        return 1;
    }

    if (left <= start && end <= right)
    {
        return seg[node];
    }

    int mid = (start + end) / 2;

    long long left_res = find_query(node * 2, start, mid, left, right);
    long long right_res = find_query(node * 2 + 1, mid + 1, end, left, right);

    // cout << "node: " << node << " left: " << left_res << " right: " << right_res << '\n';

    return (left_res * right_res) % DIVIDER;
}

long long calcDiff(int origin_idx, int to_num)
{
    if (map[origin_idx] == 0 || to_num == 0)
    {
        return to_num;
    }
    int d_num = to_num / map[origin_idx];

    return d_num;
}

void solve()
{
    int trial = M + K;
    int cmd, input1, input2;

    while (trial--)
    {
        cin >> cmd >> input1 >> input2;
        if (cmd == 1)
        {
            long long before = map[input1 - 1];
            long long diff = (long long)calcDiff(input1 - 1, input2);
            // cout << "diff: " << diff << '\n';
            update(1, 0, N - 1, before, input2, input1 - 1);
        }
        if (cmd == 2)
        {
            long long ans = (long long)find_query(1, 0, N - 1, input1 - 1, input2 - 1);
            cout << ans << '\n';
        }
    }
}

int main()
{
    input();
    solve();
}