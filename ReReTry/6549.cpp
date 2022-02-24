#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n';
#define MAX 100000
#define INF 1000000001
typedef long long ll;

using namespace std;

int N;
int Arr[MAX];
vector<int> Segment_Tree;
bool Inp_flag;

void initialize(){
    Segment_Tree.clear();
}

void input(){
    cin >> N;
    if(N == 0){
        Inp_flag = true;
        return;
    }
    for(int i = 0; i < N; i++) cin >> Arr[i];
}

int make_seg(int node, int start, int end){
    if(start == end){
        return Segment_Tree[node] = start;
    }

    int mid = (start + end) / 2;
    int left = make_seg(2 * node, start, mid);
    int right = make_seg(2 * node + 1, mid + 1, end);

    return Segment_Tree[node] = Arr[left] <= Arr[right] ? left : right;
}

int find_idx(int node, int start, int end, int left, int right){
    if(right < start || left > end) return -1;
    if(left <= start && end <= right) return Segment_Tree[node];

    int mid = (start + end) / 2;
    int left_idx = find_idx(node * 2, start, mid, left, right);
    int right_idx = find_idx(node * 2 + 1, mid + 1, end, left, right);

    if(left_idx == -1) return right_idx;
    if(right_idx == -1) return left_idx;
    return Arr[left_idx] <= Arr[right_idx] ? left_idx : right_idx;
}

ll find_area(int start, int end){
    int min_idx = find_idx(1, 0, N - 1, start, end);
    ll result = (ll)(end - start + 1) * (ll)Arr[min_idx];

    if(start <= min_idx - 1){
        ll left_result = find_area(start, min_idx - 1);
        result = max(result, left_result);
    }

    if(min_idx + 1 <= end){
        ll right_result = find_area(min_idx + 1, end);
        result = max(result, right_result);
    }

    return result;
}

void solution(){
    int tree_height = (int)ceil(log2(N));
    int Tree_size = (1 << (tree_height + 1));
    Segment_Tree.resize(Tree_size);
    make_seg(1, 0, N - 1);
    ll result = find_area(0, N - 1);
    cout << result << endl;
}

void solve(){
    while(1){
        initialize();
        input();
        if(Inp_flag) return;
        solution(); 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}