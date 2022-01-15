#include <iostream>
#define CORD_MAX 501

using namespace std;

int N;
int line[CORD_MAX];
int DP[CORD_MAX];
int max_idx = 0;
int max_result = 0;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int idx, to;
    for (int i = 0; i < N; i++)
    {
        cin >> idx >> to;
        line[idx] = to;

        if (idx > max_idx)
            max_idx = idx;
    }
}

void calcDP()
{
    for (int i = 0; i < CORD_MAX; i++)
    {
        int to = line[i];

        if (to == 0 || i > max_idx)
            continue;

        DP[i] = 1;

        for (int j = 0; j < i; j++)
        {
            int before = line[j];
            if (before < to)
            {
                DP[i] = max(DP[i], DP[j] + 1);
                if (max_result < DP[i])
                    max_result = DP[i];
            }
        }
    }
}

int main()
{
    input();
    calcDP();

    cout << N - max_result;
}