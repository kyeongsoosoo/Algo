#include <iostream>
#include <cstring>
#include <vector>
#define MAX 1001
#define INF 987654321

using namespace std;

int T;
int N,K;
int Cost[MAX];
int End;
vector<int> Edges[MAX];
int DP[MAX];
bool visited[MAX];


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

void caseInput(){
    cin >> N;
    cin >> K;

    memset(Cost, 0, sizeof(Cost));
    memset(DP, 0, sizeof(DP));
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < MAX; i++){
        Edges[i].clear();
    }

    for(int i = 1; i <= N; i++){
        cin >> Cost[i];
    }

    for(int i = 0; i < K; i++){
        int start, to;
        cin >> start >> to;
        Edges[to].push_back(start);
    }

    cin >> End;
}

void makeDFS(int idx){
    visited[idx] = true;

    for(int i = 0; i < Edges[idx].size(); i++){

        int child = Edges[idx][i];
        if(!visited[child]) {
            makeDFS(child);
        };

        DP[idx] = max(DP[idx],DP[child]);
    }

        DP[idx] += Cost[idx];

}

int main(){
    input();

    while(T--){
        caseInput();
        makeDFS(End);

        cout << DP[End] << '\n';
    }
}