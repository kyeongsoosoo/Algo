#include <iostream>
#include <cstring>
#include <vector>

#define endl '\n'
#define MAX 10

using namespace std;

int N, Answer[2];
int MAP[MAX][MAX], MAP_Color[MAX][MAX];
bool Select[MAX][MAX];

int Bishop_PosNum;

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

void input()
{
    memset(MAP_Color, 0, sizeof(MAP_Color));

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                    MAP_Color[i][j] = 1;
            }
            else
            {
                if (j % 2 == 1)
                    MAP_Color[i][j] = 1;
            }
        }
    }
}

bool Can_Position(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x;
        int ny = y;
        while (1)
        {
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                break;
            if (Select[nx][ny] == true)
                return false;
            nx = nx + dx[i];
            ny = ny + dy[i];
        }
    }
    return true;
}

void DFS(int Idx, int Cnt, int Color)
{
    if (Answer[Color] < Cnt)
        Answer[Color] = Cnt;

    for (int i = Idx + 1; i < N * N; i++)
    {
        int x = i / N;
        int y = i % N;

        if (MAP_Color[x][y] != Color || MAP[x][y] == 0 || Can_Position(x, y) == false)
            continue;
        Select[x][y] = true;
        DFS(i, Cnt + 1, Color);
        Select[x][y] = false;
    }
}

int main()
{
    input();
    DFS(-1, 0, 0);
    DFS(-1, 0, 1);
    cout << Answer[0] + Answer[1] << endl;
}