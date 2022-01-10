#include <iostream>
#include <cstring>
#include <string>
#include <queue>

#define endl "\n"
#define MAX 111

using namespace std;

int H, W, Answer;
char MAP[MAX][MAX];
bool Visit[MAX][MAX];
bool Key[26];

int TC;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

string First_Key;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
}

void initialize()
{
    memset(MAP, 0, sizeof(MAP));
    memset(Visit, false, sizeof(Visit));
    memset(Key, false, sizeof(Key));
    First_Key.clear();
    Answer = 0;
}

void caseInput()
{
    cin >> H >> W;

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> MAP[i][j];
        }
    }

    cin >> First_Key;

    for (int i = 0; i < First_Key.length(); i++)
    {
        if (First_Key[i] == '0')
            continue;
        Key[First_Key[i] - 'a'] = true;
    }
}

void BFS(int a, int b)
{
    queue<pair<int, int>> Q;
    queue<pair<int, int>> Door[26];
    Q.push(make_pair(a, b));
    Visit[a][b] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx <= H + 1 && ny <= W + 1)
            {
                if (MAP[nx][ny] == '*' || Visit[nx][ny] == true)
                    continue;
                Visit[nx][ny] = true;

                if ('A' <= MAP[nx][ny] && MAP[nx][ny] <= 'Z')
                {
                    if (Key[MAP[nx][ny] - 'A'] == true)
                    {
                        Q.push(make_pair(nx, ny));
                    }
                    else
                    {
                        Door[MAP[nx][ny] - 'A'].push(make_pair(nx, ny));
                    }
                }
                else if ('a' <= MAP[nx][ny] && MAP[nx][ny] <= 'z')
                {
                    Q.push(make_pair(nx, ny));

                    if (Key[MAP[nx][ny] - 'a'] == false)
                    {
                        Key[MAP[nx][ny] - 'a'] = true;

                        while (Door[MAP[nx][ny] - 'a'].empty() == 0)
                        {
                            Q.push(Door[MAP[nx][ny] - 'a'].front());
                            Door[MAP[nx][ny] - 'a'].pop();
                        }
                    }
                }
                else
                {
                    Q.push(make_pair(nx, ny));
                    if (MAP[nx][ny] == '$')
                        Answer++;
                }
            }
        }
    }
}

int main()
{
    input();

    while (TC--)
    {
        initialize();
        caseInput();
        BFS(0, 0);
        cout << Answer << '\n';
    }
}