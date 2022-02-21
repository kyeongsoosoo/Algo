#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 2000000000

using namespace std;

int N, M;
int *tree;
int *max_tree;
int height;
vector<int> map;
vector<pair<int, int> > range;

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
        range.push_back(make_pair(a, b));
    }

    height = (int)ceil(log2(N));
    tree = new int[1 << (height + 1)];
    max_tree = new int[1 << (height + 1)];
}

int init(int node, int start, int end){
    if(start == end) return tree[node] = map[start];

    int mid = (start + end) / 2;
    
    return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int max_init(int node, int start, int end){
    if(start == end) return max_tree[node] = map[start];

    int mid = (start + end) / 2;
    
    return max_tree[node] = max(max_init(node * 2, start, mid), max_init(node * 2 + 1, mid + 1, end));
}

int findMin(int node, int start, int end, int left, int right){
    if(end < left || right < start) return INF;

    if(left<= start && end <= right) return tree[node];

    int mid = (start + end) / 2;

    return min(findMin(node * 2, start, mid, left, right), findMin(node * 2 + 1, mid + 1, end, left, right));
}
int findMax(int node, int start, int end, int left, int right){
    if(end < left || right < start) return 0;

    if(left<= start && end <= right) return max_tree[node];

    int mid = (start + end) / 2;

    return max(findMax(node * 2, start, mid, left, right), findMax(node * 2 + 1, mid + 1, end, left, right));
}

void solve(){
    init(1, 0, N - 1);
    max_init(1, 0, N - 1);

    for(int i = 0; i < range.size(); i++){
        pair<int, int> cmd = range[i];
        int left = cmd.first - 1;
        int right = cmd.second - 1;

        int min_ans = findMin(1, 0, N - 1, left, right);
        int max_ans = findMax(1, 0, N - 1, left, right);

        cout << min_ans << " " << max_ans << '\n';
    }
}

int main(){
    input();
    solve();
}