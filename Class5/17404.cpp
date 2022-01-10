#include <iostream>
#include <algorithm>
#define MAX 987654321

using namespace std;

int cost[1001][3];
int dp[1001][3];
int num;
int result = MAX;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
}

void makeDP()
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (i == k)
                dp[1][k] = cost[1][k];
            else
                dp[1][k] = MAX;
        }

        for (int k = 2; k <= num; k++)
        {
            dp[k][0] = cost[k][0] + min(dp[k - 1][1], dp[k - 1][2]);
            dp[k][1] = cost[k][1] + min(dp[k - 1][0], dp[k - 1][2]);
            dp[k][2] = cost[k][2] + min(dp[k - 1][1], dp[k - 1][0]);
        }
        for (int k = 0; k < 3; k++)
        {
            if (i != k)
                result = min(result, dp[num][k]);
        }
    }

    cout << result;
}

int main()
{
    input();
    makeDP();
}