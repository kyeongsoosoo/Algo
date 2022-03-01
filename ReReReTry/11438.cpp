#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX 100001
#define MAX_BIT 15

using namespace std;

int N, M;
vector<int> edges[MAX];
vector<pair<int, int>> cmd;
int parent[MAX][20];
int depth[MAX];
int MAX_K = 17;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int a, b;
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    cin >> M;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        cmd.push_back(make_pair(a, b));
    }

    // MAX_K = (int)floor(log2(N));
}

void make_tree(int node, int level){
    depth[node] = level;

    for(int i = 0; i < edges[node].size(); i++){
        int next_node = edges[node][i];
        if(depth[next_node]) continue;

        parent[next_node][0] = node;
        make_tree(next_node, level + 1);
    }

}

int find_lca(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);

    int depth_a = depth[a];
    int depth_b = depth[b];

    for(int i = MAX_K - 1; i >= 0; i--){
        // cout << depth_b - depth_a << '\n';
        if(depth_b - depth_a >= (1 << i)){
            b = parent[b][i];
            depth_b = depth[b];
        }
    }

    if(a == b) return a;

    for(int i = MAX_K - 1; i >= 0; i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    int ans = parent[a][0];

    return ans;
}

void solve(){
    make_tree(1, 1);

    for(int i = 1; i < MAX_K; i++){
        for(int j = 1; j <= N; j++){
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }

    for(int i = 0; i < cmd.size(); i++){
        pair<int, int> c = cmd[i];

        int ans = find_lca(c.first, c.second);
        cout << ans << '\n';
    }
}

int main(){
    input();
    solve();
}