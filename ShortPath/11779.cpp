#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define V_MAX 1001
#define E_MAX 100001
#define INF 987654321

using namespace std;

int N, M;
int S, E;
int di[V_MAX];
int pre[V_MAX];
vector<pair<int, int>> edges[V_MAX];
vector<int> ans;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        di[i] = INF;
        pre[i] = i;
    }

    for(int i = 0; i < M; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        edges[start].push_back({cost, end});
    }

    cin >> S >> E;
}

void makeDi(){
    priority_queue<pair<int, int>> PQ;

    di[S] = 0;
    PQ.push({0, S});

    while(!PQ.empty()){
        pair<int, int> cur = PQ.top(); PQ.pop();
        int cur_cost = -cur.first;
        int cur_pos = cur.second;

        if(di[cur_pos] < cur_cost) continue;

        for(int i = 0; i < edges[cur_pos].size(); i++){
            pair<int,int> next = edges[cur_pos][i];
            int next_cost = next.first;
            int next_pos = next.second;

            int total_cost = next_cost + cur_cost;

            if(di[next_pos] > total_cost){
                pre[next_pos] = cur_pos;
                di[next_pos] = total_cost;

                PQ.push({-total_cost, next_pos});
            }
        }
    }
}

void trackAns(int cur_node){
    if(cur_node == S){
        ans.push_back(cur_node);
        return;
    }
    trackAns(pre[cur_node]);
    ans.push_back(cur_node);
}

void printAns(){
    cout << di[E] << '\n';
    cout << ans.size() << '\n';
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}

int main(){
    input();
    makeDi();
    trackAns(E);
    printAns();
}