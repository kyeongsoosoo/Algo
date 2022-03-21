#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX 100001
#define INF 1000000005

using namespace std;

int N;
int arr[MAX];

int height;
pair<int, int> *seg;

pair<int, int> construct(int node, int start, int end){
    if(start == end) return seg[node] = make_pair(arr[start], start);

    int mid = (start + end) / 2;

    pair<int, int> left_node = construct(node * 2, start, mid);
    pair<int, int> right_node = construct(node * 2 + 1, mid + 1, end);

    if(left_node.first <= right_node.first){
        return seg[node] = left_node;
    }
    return seg[node] = right_node;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    height = (int)(ceil)(log2(N));
    seg = new pair<int, int>[(1 << (height + 1))];

    construct(1, 0, N - 1);
}

pair<int, int> find(int node, int start, int end, int left, int right){
    if(end < left || start > right) return make_pair(INF, INF);
    if(start >= left && end <= right) return seg[node];

    int mid = (start + end) / 2;

    pair<int, int> left_node = find(node * 2, start, mid, left, right);
    pair<int, int> right_node = find(node * 2 + 1, mid + 1, end, left, right);

    if(left_node.first <= right_node.first){
        return left_node;
    }
    return right_node;
}

int find_max(int left, int right){
    pair<int, int> min_pair = find(1, 0, N - 1, left, right);
    int min_height = min_pair.first;
    int min_idx = min_pair.second;
    int len = right - left + 1;
    int size = min_height * len;

    int left_size = 0;
    int right_size = 0;

    if(min_idx > left ){
        left_size = find_max(left, min_idx - 1);
    }
    if(right > min_idx) {
        right_size = find_max(min_idx + 1, right);
    }

    return max(size, max(left_size, right_size));
}

int main(){
    input();

    cout << find_max(0, N - 1);
}