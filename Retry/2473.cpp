#include <iostream>
#include <algorithm>
#define MAX 5000
#define INF 3000000005

using namespace std;

int N;
long long arr[MAX];
long long ans_sum = INF;

struct ans_set
{
    long long ans1;
    long long ans2;
    long long ans3;
};

ans_set result;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);
}

void search()
{
    for (int i = 0; i < N - 2; i++)
    {
        long long first = i;

        long long start = i + 1;
        long long end = N - 1;

        while (start < end)
        {
            long long sum = arr[first] + arr[start] + arr[end];
            // cout << arr[first] << " " << arr[start] << " " << arr[end] << '\n';
            if (sum == 0)
            {
                result = {first, start, end};
                return;
            }

            if (abs(sum) < ans_sum)
            {
                ans_sum = abs(sum);
                result = {first, start, end};
            }
            if (sum < 0)
            {
                start += 1;
            }
            else
            {
                end -= 1;
            }
        }
    }
}

int main()
{
    input();
    search();

    cout << arr[result.ans1] << " " << arr[result.ans2] << " " << arr[result.ans3];
}