#include <iostream>
#include <cstring>
#define LIMIT 21
#define INF 987654321

using namespace std;

int N;
int arr[LIMIT][LIMIT];
int D[LIMIT][(1 << LIMIT)];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    memset(D, -1, sizeof(D));
}

int DFS(int level, int visited){
    if(visited == (1 << N) - 1) return 0;

    if(D[level][visited] != -1) return D[level][visited];

    D[level][visited] = INF;

    for(int flag = 0; flag < N; flag++){
        if(visited & (1 << flag)) continue;

        D[level][visited] = min(D[level][visited], DFS(level + 1, visited | (1 << flag)) + arr[level][flag]);
    }

    return D[level][visited];
}


int main(){
    input();

    cout << DFS(0,0);
}