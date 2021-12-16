#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
#define V_MAX 1001

using namespace std;

int N, M, X;
vector<pair<int, int>> Edges[V_MAX];

int from_goal[V_MAX];
int to_goal[V_MAX];
int Ans = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;

    for(int i = 0; i < M; i++){
        int start, end, cost;
        cin >> start >> end >> cost;

        Edges[start].push_back(make_pair(end, cost));
    }

    for(int i = 1; i <= N; i++){
        from_goal[i] = INF;
    }
}

void makeDi(int start, int* di){
    priority_queue<pair<int, int>> PQ;
    di[start] = 0;

    PQ.push({0, start});

    while(!PQ.empty()){
        pair<int, int> elem = PQ.top(); PQ.pop();
        int cost = -elem.first;
        int pos = elem.second;

        if(di[pos] < cost) continue;

        for(int i = 0; i < Edges[pos].size(); i++){
            pair<int, int> next = Edges[pos][i];
            int next_pos = next.first;
            int next_cost = next.second;

            int total = cost + next_cost;

            if(di[next_pos] > total){
                di[next_pos] = total;
                PQ.push({-total, next_pos});
            }
        }
    }
}

void initDi(){
    for(int i = 1; i <= N; i++){
        to_goal[i] = INF;
    }
}

void findAns(){
    for(int i = 1; i <= N; i++){
        if(i == X) continue;
        int back_time = from_goal[i];

        initDi();
        makeDi(i, to_goal);

        int go_time = to_goal[X];

        if(Ans < back_time + go_time){
            Ans = back_time + go_time;
        }
    }
}

int main(){
    input();
    makeDi(X, from_goal);
    findAns();
    cout << Ans;
}