#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 987654321

using namespace std;

int N, M;
vector<pair<int, int>> Edges[MAX];
int S, E;
int di[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int start, to, cost;
        cin >> start >> to >> cost;
        Edges[start].push_back({cost, to});
    }

    for(int i = 1; i <= N; i++){
        di[i] = INF;
    }

    cin >> S >> E;
}

void makeDI(){
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, S});

    di[S] = 0;

    while(!PQ.empty()){
        pair<int, int> P = PQ.top(); PQ.pop();
        int cur_node = P.second;
        int cur_cost = -P.first;

        if(di[cur_node] < cur_cost) continue;

        for(int i = 0; i < Edges[cur_node].size(); i++){
            pair<int, int> N = Edges[cur_node][i];
            int next_node = N.second;
            int next_cost = N.first;
            int total_cost = cur_cost + next_cost;

            if(di[next_node] > total_cost){
                di[next_node] = total_cost;
                PQ.push({-total_cost, next_node});
            }
        }
    }
}

int main(){
    input();
    makeDI();
    cout << di[E];
}