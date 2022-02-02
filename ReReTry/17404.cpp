#include <iostream>
#define INF 987654321
#define MAX 1001

using namespace std;

int N;
int map[MAX][3];
int DP[MAX][3][3];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
        }
    }
}

void solve()
{
    for (int start = 0; start < 3; start++)
    {
        for (int depth = 0; depth < N; depth++)
        {
            for (int house = 0; house < 3; house++)
            {
                if (depth == 0)
                {
                    if (house == start)
                    {
                        DP[depth][house][start] = map[depth][house];
                        continue;
                    }
                    DP[depth][house][start] = INF;
                    continue;
                }

                int option1 = (house + 1) % 3;
                int option2 = (house + 2) % 3;

                if (depth == N - 1 && house == start)
                {
                    // cout << "depth: " << depth << " house: " << house << " color: " << start << '\n';
                    DP[depth][house][start] = INF;
                    continue;
                }
                DP[depth][house][start] = min(DP[depth - 1][option1][start] + map[depth][house], DP[depth - 1][option2][start] + map[depth][house]);
            }
        }
    }
}

void printAns()
{
    int min_cost = INF;

    for (int start = 0; start < 3; start++)
    {
        for (int house = 0; house < 3; house++)
        {
            // cout << "cost: " << DP[N - 1][house][start] << " house: " << house << " color: " << start << '\n';
            min_cost = min(min_cost, DP[N - 1][house][start]);
        }
    }

    cout << min_cost;
}

int main()
{
    input();
    solve();
    printAns();
}