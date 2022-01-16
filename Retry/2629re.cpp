#include <iostream>
#define CHOO_MAX 31
#define WEIGHT_MAX 15001

using namespace std;

int N;
int weight[CHOO_MAX];
bool DP[CHOO_MAX][WEIGHT_MAX];

int K;
int check[8];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> weight[i];
    }

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> check[i];
    }
}

void calcDP()
{
    int max_w = 0;
    for (int i = 1; i <= N; i++)
    {
        int w = weight[i];

        DP[i][w] = true;

        for (int j = 1; j < WEIGHT_MAX; j++)
        {
            if (DP[i - 1][j])
            {
                if (j >= w)
                {
                    DP[i][j - w] = true;
                }
                else
                {
                    DP[i][w - j] = true;
                }

                DP[i][j] = true;
                DP[i][w + j] = true;
            }
        }
    }
}

void printAns()
{
    for (int i = 0; i < K; i++)
    {
        if (check[i] >= WEIGHT_MAX)
        {
            cout << "N ";
            continue;
        }

        if (DP[N][check[i]])
        {
            cout << "Y ";
        }
        else
        {
            cout << "N ";
        }
    }
}

int main()
{
    input();
    calcDP();
    printAns();
}