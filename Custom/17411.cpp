#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define LEN 1 << 21

using namespace std;

using P = pair<int, int>;

const int mod = 1e9 + 7;

int tree_height;
int total_num = 0;
P *seg;

int N;
vector<P> arr;

bool compareByValue(P p1, P p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

bool compareByIndex(P p1, P p2){
    return p1.second < p2.second;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(make_pair(tmp, i));
    }

    tree_height = (int)(ceil)(log2(N));
    total_num = 1 << (tree_height + 1);
    seg = new P[total_num];

    sort(arr.begin(), arr.end(), compareByValue);

    int val = 0;
    int prev;
    for(int i = 0; i < N; i++){
        // cout << arr[i].first << '\n';

        if(i != 0 && arr[i].first == prev){
            prev = arr[i].first;
            arr[i].first = arr[i - 1].first;
            continue;
        }
        prev = arr[i].first;
        arr[i].first = val;
        val += 1;
    }

    sort(arr.begin(), arr.end(), compareByIndex);
}

P update_unit(P origin, P new_p){
    // LIS 길이가 같은 경우
    if(origin.first == new_p.first) return make_pair(origin.first, (origin.second + new_p.second) % mod);

    if(origin.first > new_p.first) return origin;

    return new_p;
}

void update(int node, int target, P p, int left, int right){
    if(target < left || target > right) return;

    seg[node] = update_unit(p, seg[node]);

    if(left == right) {
        return;
    };

    int mid = (left + right) / 2;

    update(node * 2, target, p, left, mid);
    update(node * 2 + 1, target, p, mid + 1, right);
}

P find(int node, int left, int right, int start, int end){
    if(end < left || start > right) return make_pair(0, 0);
    if(left <= start && end <= right) return seg[node];

    int mid = (start + end) / 2;

    P left_result = find(node * 2, left, right, start, mid);
    P right_result = find(node * 2 + 1, left, right, mid + 1, end);

    return update_unit(left_result, right_result);
}

void solve(){
    for(int i = 0; i < total_num; i++){
        seg[i] = make_pair(0, 1);
    }

    for(int i = 0; i < N; i++){
        if(arr[i].first == 0){
            P lis = make_pair(1, 1);
            update(1, 0, lis, 0, N - 1);
            continue;
        }

        P lis = find(1, 0, arr[i].first - 1, 0, N - 1);

        lis.first += 1;
        update(1, arr[i].first, lis, 0, N - 1);
    }

    P ans = find(1, 0, N - 1, 0, N - 1);

    cout << ans.first << " " << ans.second << '\n';
}

int main(){
    input();
    solve();
}