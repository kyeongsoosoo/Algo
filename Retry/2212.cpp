#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> sensors;
vector<int> dist;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        sensors.push_back(tmp);
    }

    sort(sensors.begin(), sensors.end());
}

void calcDist()
{
    for (int i = 1; i < sensors.size(); i++)
    {
        dist.push_back(sensors[i] - sensors[i - 1]);
    }

    sort(dist.begin(), dist.end(), greater<int>());
}

int solve()
{
    int totalDist = sensors.back() - sensors.front();
    calcDist();

    for (int i = 0; (i < K - 1) && i < dist.size(); i++)
    {
        totalDist -= dist[i];
    }

    return totalDist;
}

int main()
{
    input();
    int ans = solve();

    cout << ans;
}