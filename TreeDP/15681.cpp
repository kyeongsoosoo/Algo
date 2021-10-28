#include <iostream>
#include <vector>
#define MAX 100001
#define INF 987654321

using namespace std;

int N,R,Q;
int DP[MAX];
vector<int> Edge[MAX];
bool visited[MAX];


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> R >> Q;

    for(int i = 0; i < N - 1; i++){
        int start, to;
        cin >> start >> to;
        Edge[start].push_back(to);
        Edge[to].push_back(start);
    }
}

int makeDFS(int idx){
    DP[idx] = 1;
    visited[idx] = true;

    for(int i = 0; i < Edge[idx].size(); i++){
        int nextIdx = Edge[idx][i];

        if(visited[nextIdx]) continue;

        DP[idx] += makeDFS(nextIdx);
    }

    return DP[idx];
}

void printAns(){
    while(Q--){
        int tmp_root;
        cin >> tmp_root;

        cout <<DP[tmp_root] << '\n';
    }
}

int main(){
    input();

    makeDFS(R);

    printAns();
}