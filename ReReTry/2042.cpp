#include <iostream>
#include <vector>
#include <cmath>
#define N_MAX 1000001

using namespace std;

int N, M, K;
vector<long long> map;
vector<pair<int, pair<int, long long> > > cmd;
long long *tree;
int height;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    long long tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        map.push_back(tmp);
    }

    int a, b;
    long long c;
    for(int i = 0; i < M + K; i++){
        cin >> a >> b >> c;
        cmd.push_back(make_pair(a, make_pair(b, c)));
    }

    height = ceil(log2(N));
    tree = new long long[1 << (height + 1)];
}

long long init(int node, int start, int end){
    if(start == end){
        return tree[node] = map[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

long long sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff){
    if(idx < start || idx > end) return;
    tree[node] += diff;
    if(start == end) return;

    int mid = (start + end) / 2;

    update(node * 2, start, mid, idx, diff);
    update(node * 2 + 1, mid + 1, end, idx, diff);
}

void solve(){
    init(1, 0, N - 1);

    for(int i = 0; i < cmd.size(); i++){
        int a, b;
        long long c;
        a = cmd[i].first;
        b = cmd[i].second.first;
        c = cmd[i].second.second;

        if(a == 1){
            long long diff = c - map[b - 1];
            map[b - 1] = c;
            update(1, 0, N - 1, b - 1, diff);
        }
        else{
            cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }
}

int main(){
    input();
    solve();
}