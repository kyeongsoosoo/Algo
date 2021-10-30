#include <iostream>
#include <cstring>
#include <vector>
#define MAX 10001

using namespace std;

int N;
int num[MAX];
bool visited[MAX];
vector<int> Edges[MAX];
int DP[MAX][2];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> num[i];
    }

    for(int i = 0; i < N - 1; i++){
        int start, to;
        cin >> start >> to;

        Edges[start].push_back(to);
        Edges[to].push_back(start);
    }
}

void makeDFS(int cur_node){
    visited[cur_node] = true;

    DP[cur_node][0] = 0;
    DP[cur_node][1] = num[cur_node];

    for(int next: Edges[cur_node]){
        if(!visited[next]){
            makeDFS(next);

            DP[cur_node][0] += max(DP[next][0], DP[next][1]);
            DP[cur_node][1] += DP[next][0];
        }
    }
}

int main(){
    input();
    makeDFS(1);

    cout << max(DP[1][0], DP[1][1]);
}