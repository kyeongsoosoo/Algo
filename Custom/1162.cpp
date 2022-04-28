#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define INF INT64_MAX

using namespace std;
typedef long long ll;

int N, M, K;

struct Distance{
    ll cost;
    ll idx;
    ll paved;

    bool operator<(const Distance& a) const{
        return cost > a.cost;
    }
};

vector<pair<ll, ll>> adj[10001];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    ll u, v, cost;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> cost;
        adj[u].push_back(make_pair(cost, v));
        adj[v].push_back(make_pair(cost, u));
    }
}

ll di(){
    ll dist[10001][21];
    memset(dist, 0x3f, sizeof(dist));

    priority_queue<Distance> PQ;

    PQ.push({0, 1, 0});
    dist[1][0] = 0;


    ll now_node, next_node, paved;
    ll cost, next_cost;

    while(!PQ.empty()){
        now_node = PQ.top().idx;
        cost = PQ.top().cost;
        paved = PQ.top().paved;
        PQ.pop();

        if(dist[now_node][paved] < cost) continue;

        for(int i = 0; i < adj[now_node].size(); i++){
            next_node = adj[now_node][i].second;
            next_cost = cost + adj[now_node][i].first;

            if(next_cost < dist[next_node][paved]){
                PQ.push({next_cost, next_node, paved});
                dist[next_node][paved] = next_cost;
            }

            if(paved < K && cost < dist[next_node][paved + 1]){
                PQ.push({cost, next_node, paved + 1});
                dist[next_node][paved + 1] = cost;
            }
        }
    }

    ll min_cost = INF;

    for(int i = 1; i <= K; i++){
        min_cost = min(min_cost, dist[N][i]);
    }

    return min_cost;
}

int main(){
    input();

    ll ans = di();

    cout << ans;
}
