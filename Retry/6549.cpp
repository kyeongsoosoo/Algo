#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n';
#define MAX 100000
typedef long long ll;
using namespace std;

int N;
int Arr[MAX];
vector<int> Segment_Tree;
bool Inp_Flag;

void initialize(){
    Segment_Tree.clear();
}

void input(){
    cin >> N;
    if(N == 0){
        Inp_Flag = true;
        return;
    }
    for(int i = 0; i < N; i++) cin >> Arr[i];
}

void make_seg(int node, int start, int end){
    if(start == end){
        Segment_Tree[node] = start;
        return;
    }

    int mid = (start + end) / 2;
    make_seg(node * 2, start, mid);
    make_seg(node * 2 + 1, mid + 1, end);

    if(Arr[Segment_Tree[node * 2]] <= Arr[Segment_Tree[node * 2 + 1]]) Segment_Tree[node] = Segment_Tree[node * 2];
    else Segment_Tree[node] = Segment_Tree[node * 2 + 1];
}

int find_idx(int node, int start, int end, int left, int right){
    if(right < start || left > end) return -1;
    if(left <= start && end <= right) return Segment_Tree[node];

    int mid = (start + end) / 2;
    int left_idx = find_idx(node * 2, start, mid, left, right);
    int right_idx = find_idx(node * 2 + 1, mid + 1, end, left, right);

    if(left_idx == -1) return right_idx;
    if(right_idx == - 1) return left_idx;
    if(Arr[left_idx] <= Arr[right_idx]) return left_idx;
    return right_idx;
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
    make_seg(1, 0 , N - 1);
    ll result = find_area(0, N - 1);
    cout << result << endl;
}

void solve(){
    while(1){
        initialize();
        input();
        if(Inp_Flag == true) return;
        solution();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}