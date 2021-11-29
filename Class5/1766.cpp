#include <iostream>
#include <queue>
#define V_MAX 32001

using namespace std;

int N, M;
vector<int> Edges[V_MAX];
int incoming[V_MAX];
int visited[V_MAX];
vector<int> ans;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int first, after;
        cin >> first >> after;
        incoming[after] += 1;
        Edges[first].push_back(after);
    }
}

void topologySort(){
    priority_queue<int, vector<int>, greater<int>> PQ;

    for(int i = 1; i <= N; i++){
        if(incoming[i] == 0){
            PQ.push(i);
        }
    }

    while(!PQ.empty()){
        int checkNode = PQ.top(); PQ.pop();

        visited[checkNode] = 1;
        ans.push_back(checkNode);

        for(int i = 0; i < Edges[checkNode].size(); i++){
            int nextNode = Edges[checkNode][i];

            if(visited[nextNode] == 1) continue;

            incoming[nextNode] -= 1;

            if(incoming[nextNode] == 0)
                PQ.push(nextNode);
        }
    }
}

void printAns(){
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}

int main(){
    input();
    topologySort();
    printAns();
}