#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


#define N_MAX 500001
#define LEN_MAX 1000000005

using namespace std;

int N;
int arr[N_MAX];
int test_arr[N_MAX];
int new_arr[N_MAX];
vector<int> compressed;
long long *seg;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        test_arr[i] = arr[i];
    }
    
    sort(test_arr, test_arr + N);

    for(int i = 0; i < N; i++){
        int new_idx = lower_bound(test_arr, test_arr + N, arr[i]) - test_arr;
        new_arr[i] = new_idx;
    }

    int height = (int)(ceil)(log2(N));

    seg = new long long[(1 << (height + 1))];
}

void update(int node, int left, int right, int target, int diff){
    if(right < target || left > target) return;

    seg[node] += diff;

    if(left == right) return;

    int mid = (left + right) / 2;

    update(node * 2, left, mid, target, diff);
    update(node * 2 + 1, mid + 1, right, target, diff);
}

long long find(int target, int start, int end, int left, int right){
    if(end < left || start > right) return 0;
    if(start >= left && end <= right) return seg[target];

    int mid = (start + end) / 2;

    return find(target * 2, start, mid, left, right) + find(target * 2 + 1, mid + 1, end, left, right);
}

void make_ans(){
    long long ans = 0;

    for(int i = 0; i < N; i++){
        int cur = new_arr[i];

        long long count = find(1, 0, N - 1, cur + 1, N - 1);

        ans += count;

        update(1, 0, N - 1, cur, 1);
    }

    cout << ans;
}

int main(){
    input();
    
    make_ans();
}