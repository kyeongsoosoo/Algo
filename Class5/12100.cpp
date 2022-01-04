#include <iostream>
#include <cstring>

#define endl "\n"
#define MAX 20

using namespace std;

int N, Answer;
int MAP[MAX][MAX];
int C_MAP[MAX][MAX];
int Select[5];
bool Visit[MAX][MAX];

int Bigger(int A, int B)
{
    if (A > B)
        return A;
    return B;
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}

void Move_left()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            bool check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = j + 1;
                while (k <= N - 1)
                {
                    if (C_MAP[i][k] != 0)
                    {
                        check = true;
                        break;
                    }
                    k++;
                }
                if (check == true)
                {
                    C_MAP[i][j] = C_MAP[i][k];
                    C_MAP[i][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (C_MAP[i][j] == C_MAP[i][j + 1])
            {
                C_MAP[i][j] = C_MAP[i][j] * 2;
                C_MAP[i][j + 1] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            bool check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = j + 1;
                while (k <= N - 1)
                {
                    if (C_MAP[i][k] != 0)
                    {
                        check = true;
                        break;
                    }
                    k++;
                }
                if (check == true)
                {
                    C_MAP[i][j] = C_MAP[i][k];
                    C_MAP[i][k] = 0;
                }
            }
        }
    }
}

void Move_right()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > 0; j--)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = j - 1;
                while (k >= 0)
                {
                    if (C_MAP[i][k] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k--;
                }
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[i][k];
                    C_MAP[i][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > 0; j--)
        {
            if (C_MAP[i][j] == C_MAP[i][j - 1])
            {
                C_MAP[i][j] = C_MAP[i][j] * 2;
                C_MAP[i][j - 1] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > 0; j--)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = j - 1;
                while (k >= 0)
                {
                    if (C_MAP[i][k] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k--;
                }
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[i][k];
                    C_MAP[i][k] = 0;
                }
            }
        }
    }
}

void Move_up()
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = i + 1;
                while (k <= N - 1)
                {
                    if (C_MAP[k][j] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k++;
                }

                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[k][j];
                    C_MAP[k][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (C_MAP[i][j] == C_MAP[i + 1][j])
            {
                C_MAP[i][j] = C_MAP[i][j] * 2;
                C_MAP[i + 1][j] = 0;
            }
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = i + 1;
                while (k <= N - 1)
                {
                    if (C_MAP[k][j] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k++;
                }

                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[k][j];
                    C_MAP[k][j] = 0;
                }
            }
        }
    }
}

void Move_down()
{
    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = i - 1;
                while (k >= 0)
                {
                    if (C_MAP[k][j] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k--;
                }
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[k][j];
                    C_MAP[k][j] = 0;
                }
            }
        }
    }

    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            if (C_MAP[i - 1][j] == C_MAP[i][j])
            {
                C_MAP[i][j] = C_MAP[i][j] * 2;
                C_MAP[i - 1][j] = 0;
            }
        }
    }
    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = i - 1;
                while (k >= 0)
                {
                    if (C_MAP[k][j] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k--;
                }
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[k][j];
                    C_MAP[k][j] = 0;
                }
            }
        }
    }
}

void copy_map()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C_MAP[i][j] = MAP[i][j];
        }
    }
}

int Find_max()
{
    int max = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (C_MAP[i][j] > max)
            {
                max = C_MAP[i][j];
            }
        }
    }

    return max;
}

void play_game()
{
    for (int i = 0; i < 5; i++)
    {
        int dir = Select[i];
        if (dir == 0)
            Move_right();
        else if (dir == 1)
            Move_left();
        else if (dir == 2)
            Move_down();
        else if (dir == 3)
            Move_up();
    }

    Answer = Bigger(Answer, Find_max());
}

void Select_Direction(int idx, int cnt)
{
    if (cnt == 5)
    {
        copy_map();
        play_game();
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        Select[cnt] = i;
        Select_Direction(i, cnt + 1);
    }
}

void Solution()
{
    Select_Direction(0, 0);
    cout << Answer << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Solve();
}