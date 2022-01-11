#include <iostream>
#include <cstring>
#define NODE_MAX 16
#define INF 987654321

using namespace std;

int N, Answer_Bit;
int city[NODE_MAX][NODE_MAX];
int DP[NODE_MAX][(1 << 16)];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> city[i][j];
        }
    }

    Answer_Bit = (1 << N) - 1;

    memset(DP, -1, sizeof(DP));
}

int makeRoute(int cur_idx, int cur_bit)
{
    if (cur_bit == Answer_Bit)
    {
        if (city[cur_idx][0] == 0)
            return INF;
        else
            return city[cur_idx][0];
    }

    if (DP[cur_idx][cur_bit] != -1)
        return DP[cur_idx][cur_bit];

    DP[cur_idx][cur_bit] = INF;

    for (int next_idx = 0; next_idx < N; next_idx++)
    {
        if ((cur_bit & (1 << next_idx)) == (1 << next_idx))
            continue;
        if (city[cur_idx][next_idx] == 0)
            continue;

        int next_bit = cur_bit | (1 << next_idx);

        DP[cur_idx][cur_bit] = min(DP[cur_idx][cur_bit], makeRoute(next_idx, next_bit) + city[cur_idx][next_idx]);
    }

    // cout << DP[cur_idx][cur_bit] << '\n';
    return DP[cur_idx][cur_bit];
}

int main()
{
    input();
    int ans = makeRoute(0, 1);
    cout << ans;
}