#include <iostream>
#include <vector>
#define MAX 40000

using namespace std;

int n;
int arr[MAX];
vector<int> line;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int findDirection(int to)
{
    int start = 0;
    int end = line.size() - 1;

    while (start < end)
    {
        int mid = (start + end) / 2;

        if (line[mid] < to)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

void handleLine(int idx)
{
    int to = arr[idx];

    if (line.empty())
    {
        line.push_back(to);
        return;
    }

    int last = line[line.size() - 1];

    if (to > last)
    {
        line.push_back(to);
        return;
    }

    int insert_direction = findDirection(to);
    line[insert_direction] = to;
}

int countLine()
{
    for (int i = 0; i < n; i++)
    {
        handleLine(i);
    }

    return line.size();
}

int main()
{
    input();
    int ans = countLine();

    cout << ans;
}