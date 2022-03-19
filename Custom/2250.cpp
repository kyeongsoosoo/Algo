#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>

#define MAX 10002

using namespace std;

int N;

bool is_child[MAX];
int tree[MAX][2];
int depth[MAX];
int max_depth = 0;
priority_queue<int, vector<int>, greater<int> > SMALLEST[MAX];
priority_queue<int, vector<int>, less<int> > BIGGEST[MAX];

int root_node = 0;
int pos = 0;

int ans = 0;
int ans_level = 0;

int find_root(){
    for(int i = 1; i <= N; i++){
        if(!is_child[i]) {
            return i;
        }
    }
    return 1;
}

void find_level(int node, int level){
    depth[node] = level;

    max_depth = max(max_depth, level);

    if(tree[node][0]) find_level(tree[node][0], level + 1);
    if(tree[node][1]) find_level(tree[node][1], level + 1);
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N;

    int root, left, right;
    for(int i = 0; i < N; i++){
        cin >> root >> left >> right;
        if(left != -1) {
            tree[root][0] = left;
            is_child[left] = true;
        }

        if(right != -1) {
            tree[root][1] = right;
            is_child[right] = true;
        }
    }

    root_node = find_root();

    find_level(root_node, 1);
}

void make_inorder(int node){
    int left = tree[node][0];
    int right = tree[node][1];

    int dep = depth[node];

    if(left) make_inorder(left);

    pos += 1;
    SMALLEST[dep].push(pos);
    BIGGEST[dep].push(pos);

    if(right) make_inorder(right);
}

void solve(){
    make_inorder(root_node);

    for(int i = 1; i <= max_depth; i++){
        int s = SMALLEST[i].top();
        int b = BIGGEST[i].top();

        int diff = b - s + 1;

        if(diff > ans){
            ans = diff;
            ans_level = i;
        }
    }

    cout << ans_level << " " << ans << '\n';
}

int main(){
    input();
    solve();
}