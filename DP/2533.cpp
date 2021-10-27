// 해당 지점에서 노드의 자식을 보고 판단하는데, 흰/검일 경우를 나눈다.
// 노드에 연결된 자식들에 대해 가능한 최소들만 모으면서 위로 올라감.
// 따라서 포문을 역순으로 돌려야할듯?!

#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int WHITE = 0;
int BLACK = 1;

int N;
int DP[MAX][2];
vector<int> Edge[MAX];
bool visited[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int start;
    int to;
    for(int i = 0; i < N - 1; i++){
        cin >> start;
        cin >> to;

        Edge[start].push_back(to);
        Edge[to].push_back(start);
    }
}

void makeDFS(int idx){
    visited[idx] = true;
    DP[idx][BLACK] = 1;

    for(int i = 0; i < Edge[idx].size(); i++){
        int child = Edge[idx][i];
        if(visited[child]) continue;
        makeDFS(child);
        DP[idx][WHITE] += DP[child][BLACK];
        DP[idx][BLACK] += min(DP[child][WHITE], DP[child][BLACK]);
    }
}


int main(){
    input();

    makeDFS(1);

    cout << min(DP[1][BLACK], DP[1][WHITE]) << '\n';

}