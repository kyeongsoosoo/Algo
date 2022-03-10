#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

#define INF 987654321
#define MAX 100001
#define BIT_MAX 20

using namespace std;

int N;
int K;
int MAX_K;
vector<pair<int, int> > edges[MAX];
vector<pair<int, int> > cmd;

int min_dist[MAX][BIT_MAX];
int max_dist[MAX][BIT_MAX];
int depth[MAX];
int parent[MAX][BIT_MAX];

void make_tree(int here, int level){
    depth[here] = level;
    
    for(int i = 0; i < edges[here].size(); i++){
        int next = edges[here][i].first;
        int dist = edges[here][i].second;

        if(depth[next] != -1) continue;

        parent[next][0] = here;
        min_dist[next][0] = dist;
        max_dist[next][0] = dist;

        make_tree(next, level + 1);
    }
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    memset(depth, -1, sizeof(depth));

    cin >> N;

    int a, b, c;
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b >> c;

        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    cin >> K;

    for(int i = 0; i < K; i++){
        cin >> a >> b;
        cmd.push_back(make_pair(a, b));
    }

    make_tree(1, 0);

    MAX_K = (int)floor(log2(N));

    min_dist[1][0] = INF;

    for(int i = 1; i <= MAX_K; i++){
        for(int j = 1; j <= N; j++){
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
    for(int i = 1; i <= MAX_K; i++){
        for(int j = 1; j <= N; j++){
            max_dist[j][i] = max(max_dist[j][i - 1], max_dist[parent[j][i - 1]][i - 1]);
            min_dist[j][i] = min(min_dist[j][i - 1], min_dist[parent[j][i - 1]][i - 1]);
        }
    }

    

}

void find_lca(int shall, int deep){
    if(depth[shall] > depth[deep]) swap(shall, deep);

    int max_road_deep = -1;
    int max_road_shall = -1;
    int min_road_deep = INF;
    int min_road_shall = INF;
    

    for(int i = MAX_K; i >= 0; i--){
        int diff = depth[deep] - depth[shall];

        if(diff >= (1 << i)){


            max_road_deep = max(max_road_deep, max_dist[deep][i]);
            min_road_deep = min(min_road_deep, min_dist[deep][i]);
            deep = parent[deep][i];


        }
    }

    if(shall == deep) {
        int max_final = max(max_road_deep, max_road_shall);
        int min_final = min(min_road_deep, min_road_shall);
        cout << min_final << " " << max_final << '\n';
        return;
    };

    for(int i = MAX_K; i >= 0; i--){
        if(parent[deep][i] != parent[shall][i]){
            max_road_deep = max(max_road_deep, max_dist[deep][i]);
            min_road_deep = min(min_road_deep, min_dist[deep][i]);
            max_road_shall = max(max_road_shall, max_dist[shall][i]);
            min_road_shall = min(min_road_shall, min_dist[shall][i]);

            deep = parent[deep][i];
            shall = parent[shall][i];
        }
    }
    max_road_deep = max(max_road_deep, max_dist[deep][0]);
    min_road_deep = min(min_road_deep, min_dist[deep][0]);
    max_road_shall = max(max_road_shall, max_dist[shall][0]);
    min_road_shall = min(min_road_shall, min_dist[shall][0]);

    int max_final = max(max_road_deep, max_road_shall);
    int min_final = min(min_road_deep, min_road_shall);

    cout << min_final << " " << max_final << '\n';
}

void solve(){
    for(int i = 0; i < K; i++){
        int a = cmd[i].first;
        int b = cmd[i].second;

        find_lca(a, b);
    }
}

int main(){
    input();
    solve();
}