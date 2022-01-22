#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
#define INF 987654321

using namespace std;

int n, m;
int prev_route[MAX];
vector<int> route;
vector<pair<int, int>> map[MAX];
vector<int> reverse_map[MAX];
bool inRoute[MAX];
int dist[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        map[u].push_back(make_pair(v, -w));
        reverse_map[v].push_back(u);
    }

    for(int i = 1; i < MAX; i++){
        dist[i] = INF;
    }
}

void markRoute(){
    queue<int> Q;

    Q.push(n);
    inRoute[n] = true;

    while(!Q.empty()){
        int top = Q.front(); Q.pop();

        for(int i = 0; i < reverse_map[top].size(); i++){
            int start= reverse_map[top][i];

            if(inRoute[start]) continue;

            // cout << "inRoute: " << start << '\n';

            inRoute[start] = true;
            Q.push(start);
        }
    }
}

bool bell(){
    dist[1] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 0; k < map[j].size(); k++){
                int end = map[j][k].first;
                int cost = map[j][k].second;

                if(dist[j] + cost < dist[end]){
                    dist[end] = dist[j] + cost;
                    prev_route[end] = j;
                }
            }
        }
    }

    for(int j = 1; j <= n; j++){
        for(int k = 0; k < map[j].size(); k++){
            int end = map[j][k].first;
            int cost = map[j][k].second;

            if(dist[j] + cost < dist[end]){
                // cout << '?' << j << '\n';
                if(inRoute[j]) return true;
            }
        }
    }

    return false;
}

void printRoute(){
    int start = n;

    while(start != 1){
        route.push_back(start);
        start = prev_route[start];
    }

    route.push_back(1);

    for(int i = route.size() - 1; i >= 0; i--){
        cout << route[i] << " ";
    }
}

int main(){
    input();
    markRoute();
    bool hasCycle = bell();

    if(hasCycle){
        cout << -1;
    }
    else{
        printRoute();
    }
}

