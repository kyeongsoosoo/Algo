#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1001

using namespace std;

struct wish_list
{
    int start;
    int end;
};

struct cmp
{
    bool operator()(wish_list a, wish_list b)
    {
        if (a.start == b.start)
        {
            return a.end < b.end;
        }
        return a.start < b.start;
    }
};

int T;
int arr[MAX];
int N,
    M;
bool book[MAX];

priority_queue<wish_list, vector<wish_list>, cmp> PQ;

int find(int idx)
{
    int par_idx = arr[idx];
    if (idx == par_idx)
        return idx;
    else
        return arr[idx] = find(par_idx);
}

bool merge(int idx1, int idx2)
{
    int root1 = find(idx1);
    int root2 = find(idx2);

    if (root1 == root2)
        return false;
    else
    {
        if (root1 < root2)
            arr[root2] = root1;
        else
            arr[root1] = root2;

        return true;
    }
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

void caseInput()
{
    memset(book, false, sizeof(book));
    while (!PQ.empty())
    {
        PQ.pop();
    }
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = i;
    }

    cin >> N >> M;

    int s, e;
    for (int i = 0; i < M; i++)
    {
        cin >> s >> e;
        PQ.push({s, e});
    }
}

int findAns()
{
    int counter = 0;

    while (!PQ.empty())
    {
        wish_list tmp = PQ.top();
        PQ.pop();

        // int end = range.end;
        // int start = range.start;

        // cout << "start: " << tmp.start << " end: " << tmp.end << '\n';

        // while (start <= end)
        // {
        //     if (book[start] == false)
        //     {
        //         book[start] = true;
        //         counter += 1;
        //         break;
        //     }
        //     start += 1;
        // }
        int possible_idx = find(tmp.end);

        // cout << possible_idx << '\n';

        if (possible_idx >= tmp.start)
        {
            merge(possible_idx - 1, possible_idx);
            counter += 1;
        }
    }
    return counter;
}

int main()
{
    input();

    while (T--)
    {
        caseInput();
        int ans = findAns();
        cout << ans << '\n';
    }
}