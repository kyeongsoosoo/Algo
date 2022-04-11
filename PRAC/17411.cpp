#include <iostream>
#include <vector>
#include <algorithm>

#define LEN 1 << 21

using namespace std;

using P = pair<int,int>;

const int mod = 1e9 + 7;
P seg[LEN];

int N;
vector<P> arr;
int origin[LEN];

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
        origin[i] = tmp;
    }

    sort(arr.begin(), arr.end(), compareByValue);

    int val = 1;
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
    if(origin.first == new_p.first) return make_pair(origin.first, origin.second + new_p.second);

    if(origin.first > new_p.first) return origin;

    return new_p;
}

void update(int node, int target, P p, int left, int right){
    if(left == right) {
        seg[node] = update_unit(p, seg[node]);
        return;
    };

    if(target < left || target > right) return;

    seg[node] = update_unit(p, seg[node]);

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
    for(int i = 0; i < LEN; i++){
        seg[i] = make_pair(0, 1);
    }

    for(int i = 0; i < N; i++){
        // cout << "a: " << arr[i].first - 1 << '\n';

        P lis = find(1, 0, arr[i].first - 1, 0, N);

        lis.first += 1;
        update(1, arr[i].first, lis, 0, N);

        cout << lis.first << " " << lis.second << '\n';
    }

    cout << seg[1].first << " " << seg[1].second;
}

int main(){
    input();
    solve();
}