#include <iostream>
#define N_MAX 16
#define INF 987654321

using namespace std;

int N;
int W[N_MAX][N_MAX];
int DP[N_MAX][(1 << N_MAX)];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> W[i][j];
        }
    }
}

int makeDFS(int curBit, int curNode, int goal){
    if(curBit == goal){
        if(W[curNode][0]){
            return W[curNode][0];
        }
        return INF;
    }

    if(DP[curNode][curBit]) return DP[curNode][curBit];

    DP[curNode][curBit] = INF;

    for(int i = 0; i < N; i++){
        if(i == curNode) continue;
        if(curBit & (1 << i)) continue;
        if(W[curNode][i] == 0) continue;

        int nextNode = i;
        int nextBit = curBit | (1 << i);

        DP[curNode][curBit] = min(DP[curNode][curBit], makeDFS(nextBit, nextNode, goal) + W[curNode][nextNode]);
    }

    return DP[curNode][curBit];
}

int main(){
    input();
    cout << makeDFS(1, 0, (1 << N) - 1);
}