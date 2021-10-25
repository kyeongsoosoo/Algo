#include <iostream>
#include <cstring>
#define INF 987654321
#define LIMIT 21

using namespace std;

int N, num[LIMIT][LIMIT];
int DP[LIMIT][1 << LIMIT];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num[i][j];
        }
    }

    memset(DP, -1, sizeof(DP));
}

int DFS(int x, int visited){
    if(visited == (1 << N) - 1) 
        return 0;
    if(DP[x][visited] != -1)
        return DP[x][visited];

    DP[x][visited] = INF;

    for(int i = 0; i < N; i++){
        if(visited & (1 << i)) continue;

        DP[x][visited] = 
            min(DP[x][visited], DFS(x + 1, visited | (1 << i)) + num[x][i]);
    }
    
    return DP[x][visited];
}

int main(){
    input();

    cout << DFS(0, 0);
}
