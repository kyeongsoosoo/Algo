#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <functional>

#define INF 987654321
#define MAX 501

using namespace std;

int V, E;
int S, D;

vector< pair<int, int> > edges[MAX];
int map[MAX];
bool marked[MAX][MAX];
bool visited[MAX];
vector<int> prev_pos[MAX];

struct compare{
    bool operator()( pair<int, int> A, pair<int, int> B ){
        return A.first >= B.first;
    }
};

bool case_input(){
    memset(marked, false, sizeof(marked));
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < MAX; i++) {
        map[i] = INF;
        edges[i].clear();
        prev_pos[i].clear();
    }

    cin >> V >> E;

    if(V == 0 && E == 0) return true;

    cin >> S >> D;

    int s, e, c;
    for(int i = 0; i < E; i++){
        cin >> s >> e >> c;
        edges[s].push_back(make_pair(e, c));
    }

    return false;
}

void di(){
    priority_queue< pair<int, int>, vector< pair<int, int> >, compare > PQ;
    
    for(int i = 0; i < MAX; i++) {
        map[i] = INF;
    }

    map[S] = 0;
    PQ.push(make_pair(0, S));

    while(!PQ.empty()){
        pair<int, int> cur = PQ.top(); PQ.pop();
        int cur_cost = cur.first;
        int cur_pos = cur.second;

        for(int i = 0; i < edges[cur_pos].size(); i++){
            pair<int, int> next = edges[cur_pos][i];
            int next_pos = next.first;
            int next_cost = next.second;
            int total_cost = cur_cost + next_cost;

            if(marked[cur_pos][next_pos]) continue;


            if(total_cost < map[next_pos]){
                map[next_pos] = total_cost;
                prev_pos[next_pos].clear();
                prev_pos[next_pos].push_back(cur_pos);
                PQ.push(make_pair(total_cost, next_pos));
            }
            else if(total_cost == map[next_pos]){
                prev_pos[next_pos].push_back(cur_pos);
            }
        }
    }
}

void remove_shortest(int node){
    // cout << "node: " << node << '\n';
    for(int i = 0; i < prev_pos[node].size(); i++){
        int next_node = prev_pos[node][i];


        visited[node] = true;
        marked[next_node][node] = true;
        
        if(visited[next_node]) continue;

        remove_shortest(next_node);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(true){
        bool is_last = case_input();

        if(is_last) return 0;

        di();
        remove_shortest(D);
        di();

        int ans = (map[D] == INF) ? -1 : map[D];
        cout << ans << '\n';
    }
}