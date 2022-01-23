#include <iostream>
#define MAX 1000
#define INF 987654321

using namespace std;

int N, M;
int map[MAX][MAX];
int DP[MAX][MAX][3];
bool visit[MAX][MAX];

int x_move[3] = {-1, 0, 1};
int y_move[3] = {0, 1, 0};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
}

bool checkCondition(int y, int x){
    if(visit[y][x]) return false;
    if(y < 0 || y >= N || x < 0 || x >= M) return false;
    return true;
}

int makeRoute(int y, int x, int route){
    if(DP[y][x][route]) return DP[y][x][route];

    if(y == N - 1 && x == M - 1) return map[N - 1][M - 1];
    
    visit[y][x] = true;

    DP[y][x][route] = -INF;

    for(int i = 0; i < 3; i++){
        int next_x = x + x_move[i];
        int next_y = y + y_move[i];

        if(!checkCondition(next_y, next_x)) continue;

        DP[y][x][route] = max(DP[y][x][route], makeRoute(next_y, next_x, i) + map[y][x]);
    }

    visit[y][x] = false;

    return DP[y][x][route];
}

int main(){
    input();
    cout << makeRoute(0, 0, 0);
}