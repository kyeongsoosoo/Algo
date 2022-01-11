#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define NODE_MAX 100001
#define MAX 1000000000

using namespace std;

int N, M;
vector<pair<int, int>> Edges[NODE_MAX];
bool visited[NODE_MAX];
int Start, End;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        Edges[a].push_back(make_pair(b, c));
        Edges[b].push_back(make_pair(a, c));
    }

    cin >> Start >> End;
}

bool hasPath(int weight)
{
    memset(visited, false, sizeof(visited));
    queue<int> Q;

    visited[Start] = true;
    Q.push(Start);

    while (!Q.empty())
    {
        int cur_node = Q.front();
        Q.pop();

        for (int i = 0; i < Edges[cur_node].size(); i++)
        {
            pair<int, int> next = Edges[cur_node][i];
            int next_weight = next.second;
            int next_node = next.first;

            if (next_weight < weight)
                continue;

            if (visited[next_node])
                continue;
            visited[next_node] = true;

            if (next_node == End)
            {
                return true;
            }
            Q.push(next_node);
        }
    }

    return false;
}

int binarySearch()
{
    int S = 0;
    int E = MAX;

    while (S <= E)
    {
        // cout << S << " " << E << '\n';
        int mid = (S + E) / 2;

        if (hasPath(mid))
        {
            S = mid + 1;
        }
        else
        {
            E = mid - 1;
        }
    }

    return E;
}

int main()
{
    input();
    int ans = binarySearch();

    cout << ans;
}