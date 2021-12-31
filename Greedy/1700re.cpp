#include <iostream>
#define TURN_MAX 101

using namespace std;

int N, K;
int turn[TURN_MAX];
int plug[TURN_MAX];
int result = 0;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> turn[i];
    }
}

void makeGreedy()
{
    for (int i = 0; i < K; i++)
    {
        bool plugged = false;

        for (int j = 0; j < N; j++)
        {
            if (plug[j] == turn[i])
            {
                plugged = true;
                break;
            }
        }

        if (plugged)
        {
            continue;
        }

        for (int j = 0; j < N; j++)
        {
            if (!plug[j])
            {
                plug[j] = turn[i];
                plugged = true;
                break;
            }
        }
        if (plugged)
        {
            continue;
        }

        int idx, deviceIdx = -1;
        for (int j = 0; j < N; j++)
        {
            int lastIdx = 0;
            for (int k = i + 1; k < K; k++)
            {
                if (plug[j] == turn[k])
                    break;
                lastIdx++;
            }

            if (lastIdx > deviceIdx)
            {
                idx = j;
                deviceIdx = lastIdx;
            }
        }

        result++;
        plug[idx] = turn[i];
    }
    cout << result;
}

int main()
{
    input();
    makeGreedy();
}