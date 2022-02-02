#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 1001

using namespace std;

int N, M;
int map[MAX][MAX];
int mark[MAX][MAX];
int counter[MAX * MAX];
int max_size = 1;

int y_move[4] = {0, 0, -1, 1};
int x_move[4] = {1, -1, 0, 0};

bool checkCondition(int y, int x)
{
    if (y < 0 || y >= N || x < 0 || x >= M)
        return false;
    if (map[y][x] == 1 || mark[y][x])
        return false;
    return true;
}

void markAndCountMap()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {

            if (map[i][j] == 1 || mark[i][j])
                continue;

            queue<pair<int, int> > Q;
            int total = 1;

            Q.push(make_pair(i, j));
            mark[i][j] = max_size;

            while (!Q.empty())
            {
                int y = Q.front().first;
                int x = Q.front().second;
                Q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int next_x = x_move[i] + x;
                    int next_y = y_move[i] + y;

                    if (checkCondition(next_y, next_x))
                    {
                        // cout << "y: " << next_y << " x: " << next_x << '\n';
                        total += 1;
                        mark[next_y][next_x] = max_size;
                        Q.push(make_pair(next_y, next_x));
                    }
                }
            }

            // cout << max_size << " " << total << '\n';
            counter[max_size] = total;
            max_size += 1;
        }
    }
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    // memset(mark, -1, sizeof(mark));
    markAndCountMap();
}

bool checkVisited(vector<int> V, int marking)
{
    for (int i = 0; i < V.size(); i++)
    {
        if (V[i] == marking)
            return true;
    }
    return false;
}

int sumCount(int y, int x)
{
    int total = 0;
    vector<int> Q;

    for (int i = 0; i < 4; i++)
    {
        int next_y = y + y_move[i];
        int next_x = x + x_move[i];

        if (y < 0 || y >= N || x < 0 || x >= M)
            continue;

        int marking = mark[next_y][next_x];

        if (checkVisited(Q, marking))
            continue;

        // cout << y << " x:  " << x << " count:  " << counter[marking] << '\n';
        Q.push_back(marking);
        total += counter[marking];
    }

    return (total + 1) % 10;
}

void solve()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
                cout << 0;
            else
                cout << sumCount(i, j);
        }
        cout << '\n';
    }
}

int main()
{
    input();
    solve();
}