#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define INF 1000000005

using namespace std;

int N, M;
vector<int> map;
vector<pair<int, int> > cmd;
int *seg;
int height;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        map.push_back(tmp);
    }

    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        cmd.push_back(make_pair(a, b));
    }

    height = (int)(ceil)(log2(N));
    seg = new int[1 << (height + 1)];
}

int construct(int node, int start, int end){
    if(start == end) return seg[node] = map[start];

    int mid = (start + end) / 2;

    return seg[node] = min(construct(node * 2, start, mid), construct(node * 2 + 1, mid + 1, end));
}

int find(int node, int start, int end, int left, int right){
    if(end < left || right < start) return INF;
    if(left <= start && end <= right) return seg[node];

    int mid = (start + end) / 2;

    return min(find(node * 2, start, mid, left, right), find(node * 2 + 1, mid + 1, end, left, right));
}

void solve(){
    for(int i = 0; i < M; i++){
        pair<int, int> c = cmd[i];
        int start = c.first - 1;
        int end = c.second - 1;

        int ans = find(1, 0, N - 1, start, end);
        cout << ans << '\n';
    }
}

int main(){
    input();
    construct(1, 0, N - 1);
    solve();
}