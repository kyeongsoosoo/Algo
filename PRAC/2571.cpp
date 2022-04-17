#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500001
#define LIMIT 1000000005

using namespace std;

int N;
vector<int> arr;
vector<int> origin;
vector<int> ans;
// int idx_arr[LIMIT];
int seg[MAX * 4];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        origin.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++){
        int target = origin[i];

        int idx = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

        origin[i] = idx;
    }
}

void update(int node, int target, int diff, int start, int end){
    if(target < start || target > end) return;

    seg[node] += diff;

    if(start == end) return;

    int mid = (start + end) / 2;

    update(node * 2, target, diff, start, mid);
    update(node * 2 + 1, target, diff, mid + 1, end);
}

int find(int node, int start, int end, int left, int right){
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return seg[node];

    int mid = (start + end) / 2;

    return find(node * 2, start, mid, left, right) + find(node * 2 + 1, mid + 1, end, left, right);
}

void solve(){
    for(int i = 0; i < origin.size(); i++){
        int target = origin[i];

        int higher_player = find(1, 0, MAX, target, MAX);
        int expected_rank = higher_player + 1;

        ans.push_back(expected_rank);

        update(1, target, 1, 0, MAX);
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
}

int main(){
    input();
    solve();
}