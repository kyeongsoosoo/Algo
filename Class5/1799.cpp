#include <iostream>
#include <cstring>
#include <vector>

#define MAX 10
using namespace std;

int N, Answer[2];
int MAP[MAX][MAX], MAP_Color[MAX][MAX];
bool Select[MAX][MAX];

int Bishop_PosNum;

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

void input(){
    memset(MAP_Color, 0, sizeof(MAP_Color));
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
            if(i % 2 == 0){
                if(j % 2 == 0) MAP_Color[i][j] = 1;
            }
            else {
                if(j % 2 == 1) MAP_Color[i][j] = 1;
            }
        }
    }
}

bool Can_position(int x, int y){
    for(int i = 0; i < 4; i++){
        int nx = x;
        int ny = y;

        while(1){
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) break;
            if(Select[nx][ny] == true) return false;
            nx = nx + dx[i];
            ny = ny + dy[i];
        }
    }
    return true;
}

void DFS(int idx, int cnt, int color){
    if(Answer[color] < cnt) Answer[color] = cnt;

    for(int i = idx + 1; i < N * N; i++){
        int x = i / N;
        int y = i % N;

        if(MAP_Color[x][y] != color || MAP[x][y] == 0 || Can_position(x, y) == false) continue;
        Select[x][y] = true;
        DFS(i, cnt + 1, color);
        Select[x][y] = false;
    }
}

void solution(){
    DFS(-1, 0, 0);
    DFS(-1, 0, 1);
    cout << Answer[0] + Answer[1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();
}