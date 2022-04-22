#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX 100000

using namespace std;

using P = pair<int, int>;

int m, n, k;
int seg[MAX * 4];
vector<P> pos;

bool compare(P a, P b){
    if(a.first == b.first) return a.second < b.second;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> k;

    for
}

void update(int node, int target, int left, int right, int diff){
    if(target < left || right < target) return;

    seg[node] += 1;

    if(left == right) return;

    int mid = (left + right) / 2;

    update(node * 2, target, left, mid, diff);
    update(node * 2 + 1, target, mid + 1, right, diff);
}

int find(int node, int left, int right, int start, int end){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[node];

    int mid = (start + end) / 2;

    return find(node * 2, left, right, start, mid) + find(node * 2, left, right, mid + 1, end);
}

void solve(){

}

int main(){
    input();
}
