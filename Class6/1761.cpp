#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

#define MAX 40001
#define BIT_MAX 17

using namespace std;

struct node{
    int goal;
    int dist;
};

int N;
int M;
vector<node> edges[MAX];
vector<pair<int, int> > cmd;
int bit_move[MAX][BIT_MAX];
int depth[MAX];
int dist[MAX];
int parent[MAX];
bool vis[MAX];
int MAX_K;

void make_tree(int here, int level){
    vis[here] = true;
    depth[here] = level;
    
    for(int i = 0; i < edges[here].size(); i++){
        node selected = edges[here][i];

        if(vis[selected.goal]) continue;

        dist[selected.goal] = dist[here] + selected.dist;
        bit_move[selected.goal][0] = here;

        // cout << "selected: " << selected.goal << " move: " << bit_move[selected.goal][0] << '\n';

        make_tree(selected.goal, level + 1);
    }
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    memset(depth, -1, sizeof(depth));

    int start, end, dist;
    for(int i = 0; i < N - 1; i++){
        cin >> start >> end >> dist;
        edges[start].push_back({end, dist});
        edges[end].push_back({start, dist});
    }

    make_tree(1, 0);

    MAX_K = (int)floor(log2(N));

    // cout << "test: " << bit_move[6][0] << '\n';

    for(int j = 1; j <= MAX_K; j++){
        for(int i = 1; i <= N; i++){
            bit_move[i][j] = bit_move[bit_move[i][j - 1]][j - 1];
            // cout << "i: " << i << " j: " << j << " bit: " << bit_move[i][j] << '\n';
        }
    }

    cin >> M;

    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        cmd.push_back(make_pair(a, b));
    }
}

int find_lca(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);

    int dep_a = depth[a];
    int dep_b = depth[b];

    for(int i = MAX_K; i >= 0; i--){
        // cout << depth[b] << '\n';
        int diff = depth[b] - depth[a];
        if( diff >= (1 << i)){
            b = bit_move[b][i];
        }
    }

    if(b == a) return b;
    // cout << "a: " << a << " b: " << b << '\n';

    for(int k = MAX_K; k >= 0; k--){
        if(bit_move[b][k] != bit_move[a][k]){
            // cout << "a: " << a << " b: " << b << '\n';
            b = bit_move[b][k];
            a = bit_move[a][k];
        }
    }
    return bit_move[b][0];
}

void solve(){
    for(int i = 0; i < cmd.size(); i++){
        int a = cmd[i].first;
        int b = cmd[i].second;
        int lca = find_lca(a, b);
        int std = dist[lca];
        int dist_a = dist[a] - std;
        int dist_b = dist[b] - std;

        cout << dist_a + dist_b << '\n';
    }
}

int main(){
    input();
    solve();
}