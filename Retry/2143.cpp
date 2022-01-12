#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 1000

using namespace std;

long long T;
int N, M;
long long result = 0;
vector<long long> A(MAX_SIZE);
vector<long long> B(MAX_SIZE);
vector<long long> v, v2;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    for (int i = 0; i < N; i++)
    {
        long long sum = A[i];
        v.push_back(sum);
        for (int j = i + 1; j < N; j++)
        {
            sum += A[j];
            v.push_back(sum);
        }
    }

    for (int i = 0; i < M; i++)
    {
        long long sum = B[i];
        v2.push_back(sum);
        for (int j = i + 1; j < M; j++)
        {
            sum += B[j];
            v2.push_back(sum);
        }
    }
}

void solve()
{
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < v.size(); i++)
    {
        int low = lower_bound(v2.begin(), v2.end(), T - v[i]) - v2.begin();
        int high = upper_bound(v2.begin(), v2.end(), T - v[i]) - v2.begin();

        result += high - low;
    }
}

int main()
{
    input();
    solve();
    cout << result;
}