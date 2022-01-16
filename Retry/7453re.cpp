#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 4000

using namespace std;

int n;
int A[MAX];
int B[MAX];
int C[MAX];
int D[MAX];

vector<int> arr1;
vector<int> arr2;

long long counter = 0;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum1 = A[i] + B[j];
            int sum2 = C[i] + D[j];

            // cout << sum1 << " sum " << sum2 << '\n';

            arr1.push_back(sum1);
            arr2.push_back(sum2);
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

void search()
{
    int max_size = arr1.size() - 1;
    int start = 0;
    int end = max_size;

    while ((start <= max_size) || (end >= 0))
    {
        // cout << arr1[start] << " " << arr2[end] << '\n';
        if (start > max_size)
        {
            int sum = arr1[max_size] + arr2[end];
            if (sum == 0)
            {
                counter += (long long)1;
            }
            end -= 1;
            continue;
        }

        if (end < 0)
        {
            int sum = arr1[start] + arr2[0];
            if (sum == 0)
            {
                counter += (long long)1;
            }
            start += 1;
            continue;
        }

        int sum = arr1[start] + arr2[end];
        if (sum < 0)
        {
            start += 1;
            continue;
        }

        if (sum == 0)
        {
            int origin_start = start;
            int origin_end = end;

            int arr1_count = 0;
            int arr2_count = 0;

            while (start <= max_size && arr1[start] == arr1[origin_start])
            {
                arr1_count += 1;
                start += 1;
            }
            while (end >= 0 && arr2[end] == arr2[origin_end])
            {
                arr2_count += 1;
                end -= 1;
            }

            counter += (long long)arr1_count * arr2_count;

            continue;
        }

        if (sum > 0)
        {
            end -= 1;
            continue;
        }
    }
}

int main()
{
    input();
    search();
    cout << counter;
}