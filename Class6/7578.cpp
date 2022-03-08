#include <iostream>
#include <cmath>
#define MAX 1000001

using namespace std;

int N;
int A[MAX];
int idx[MAX];
int B[MAX];

int height;
int size;
long long *seg;

long long find(int node, int start, int end, int left, int right){
    // cout << node << " start: " << start << " end: " << end << " left: " << left <<  '\n';
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[node];

    int mid = (start + end) / 2;

    return find(node * 2, start, mid, left, right) + find(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int target, int left, int right, long long diff){
    if(target < left || right < target) return;
    
    seg[node] += diff;

    if(left == right) return;

    int mid = (left + right) / 2;
    update(node * 2, target, left, mid, diff);
    update(node * 2 + 1, target, mid + 1, right, diff);
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int i = 0; i < N; i++){
        cin >> B[i];
        idx[B[i]] = i;
    }

    height = (ceil)(log2(N));
    seg = new long long[2000000];
}

void solve(){
    long long ans = 0;

    for(int i = 0; i < N; i++){
        int selected = A[i];
        int end_idx = idx[selected];

        // cout << end_idx << '\n';
        long long crossed = find(1, 0, N - 1, end_idx, N - 1);
        ans += crossed;

        update(1, end_idx, 0, N - 1, (long long)1);
    }

    cout << ans;
}

int main(){
    input();
    solve();
}

// 깔아놓는 리프 노드는 B열로.
// A열에서 처음부터 출발하면서 자신보다 큰 리프노드 카운트
// 한번 find 수행한 후에는 자기 자리에 +1 업데이트.