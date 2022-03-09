#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define MAX 1000001

using namespace std;

int N;

struct instruction{
    int A;
    int B;
    int C;
};

vector<instruction> cmd;
int height;
int *seg;


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int a, b, c;
    for(int i = 0; i < N; i++){
        cin >> a;
        if(a == 1){
            cin >> b;
            cmd.push_back({a, b, -1});
            continue;
        }
        cin >> b >> c;
        cmd.push_back({a, b, c});
    }

    height = (int)(ceil)(log2(MAX));
    seg = new int[1 << (height + 1)];
}

void update(int node, int target, int left, int right, int diff){
    if(target < left || right < target) return;

    // cout << node << " left: " << left << " right: " << right << " diff: " << diff << '\n';

    seg[node] += diff;

    if(left == right) return;

    int mid = (left + right) / 2;

    update(node * 2, target, left, mid, diff);
    update(node * 2 + 1, target, mid + 1, right, diff);
}

int find(int node, int left, int right, int start, int end){
    if(right < start || end < left) return 0;
    if(start <= left && right <= end) return seg[node];

    int mid = (left + right) / 2;

    return find(node * 2, left, mid, start, end) + find(node * 2 + 1, mid + 1, right, start, end);
}

void pick_candy(int rank){
    int start = 0;
    int end = MAX - 1;

    while(start < end){
        int mid = (start + end) / 2;
        int result = find(1, 0, MAX - 1, 0, mid);
        // cout << "result: " << result << " rank: " << rank <<" mid: " << mid <<  '\n';

        if(result < rank){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }

    cout << end + 1 << '\n';
    update(1, end, 0, MAX - 1, -1);
}

void solve(){
    for(int i = 0; i < cmd.size(); i++){
        instruction item = cmd[i];
        if(item.A == 1){
            pick_candy(item.B);
            continue;
        }

        int taste = item.B - 1;
        int candy_size = item.C;

        update(1, taste, 0, MAX - 1, candy_size);
    }
}

int main(){
    input();
    solve();
}