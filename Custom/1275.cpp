#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define N_MAX 100005
#define INF (1 << 31)

using namespace std;

struct cmd{
    int x;
    int y;
    int a;
    int b;
};

int N, Q;
vector<long long> arr;
vector<cmd> C;

int height;
long long *seg;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;

    int x, y, a, b;
    for(int i = 0; i < N; i++){
        cin >> x;
        arr.push_back((long long)x);
    }

    for(int i = 0; i < Q; i++){
        cin >> x >> y >> a >> b;

        if(x <= y){
            C.push_back({x, y, a, b});
        }
        else{
            C.push_back({y, x, a, b});
        }
    }

    height = (int)(ceil)(log2(N));
    seg = new long long[1 << (height + 1)];
}

long long build_seg(int target, int left, int right){
    if(left == right) return seg[target] = arr[left];

    int mid = (left + right) / 2;

    return seg[target] = build_seg(target * 2, left, mid) + build_seg(target * 2 + 1, mid + 1, right);
}

long long find(int target, int left, int right, int start, int end){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[target];

    int mid = (start + end) / 2;

    return find(target * 2, left, right, start, mid) + find(target * 2 + 1, left, right, mid + 1, end);
}

void update(int node, int goal, int left, int right, long long diff){
    if(right < goal || goal < left) return;

    seg[node] += diff;

    if(left == right) return;

    int mid = (left + right) / 2;

    update(node * 2, goal, left, mid, diff);
    update(node * 2 + 1, goal, mid + 1, right, diff);
}

void solve(){
    for(int i = 0; i < C.size(); i++){
        cmd cur = C[i];

        long long ans = find(1, cur.x - 1, cur.y - 1, 0, N - 1);

        cout << ans << '\n';

        long long diff = cur.b - arr[cur.a - 1];
        arr[cur.a - 1] = cur.b;

        update(1, cur.a - 1, 0, N - 1, diff);
    }
}

int main(){
    input();
    build_seg(1, 0, N - 1);
    solve();
}