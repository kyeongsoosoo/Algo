#include <iostream>
#define MAX 1000
#define INF 987654321

using namespace std;

int N, M;
int matrix[MAX][MAX];
int DP[MAX][MAX][3];
bool visited[MAX][MAX];

int y_move[3] = {0, 0, 1};
int x_move[3] = {-1, 1, 0};

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
            DP[i][j][0] = -INF;
            DP[i][j][1] = -INF;
            DP[i][j][2] = -INF;
        }
    }
}

bool checkCondition(int y, int x)
{
    if (x < 0 || x >= M)
        return false;
    if (y < 0 || y >= N)
        return false;
    return true;
}

int makeDFS(int y, int x, int Dir)
{
    if (y == N - 1 && x == M - 1)
        return matrix[y][x];
    if (DP[y][x][Dir] != -INF)
        return DP[y][x][Dir];

    visited[y][x] = true;

    int Biggest = -INF;

    for (int move = 0; move < 3; move++)
    {
        int y_cord = y + y_move[move];
        int x_cord = x + x_move[move];

        if (checkCondition(y_cord, x_cord) && !visited[y_cord][x_cord])
            Biggest = max(Biggest, makeDFS(y_cord, x_cord, move));
    }

    visited[y][x] = false;
    DP[y][x][Dir] = matrix[y][x] + Biggest;
    return DP[y][x][Dir];
}

int main()
{
    input();
    int ans = makeDFS(0, 0, 0);

    cout << ans;
}