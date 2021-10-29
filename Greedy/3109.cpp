#include <iostream>
#include <queue>
#define ROW_MAX 10001
#define COL_MAX 501

using namespace std;

struct Dir{
    int y,x;
};

Dir moveDir[3] = {
    {-1, 1},
    {0, 1},
    {1, 1},
};

int R,C;
string PATH[ROW_MAX][COL_MAX];
bool visited[ROW_MAX][COL_MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    for(int r = 0; r < R; r++){
        string s;
        cin >> s;
        for(int c = 0; c < C; c++){
            PATH[r][c] = s[c];
        }
    }
}

bool DFS(int y, int x){
    visited[y][x] = true;
    if(x == C - 1) return true;

    for(int i = 0; i <3; i++){
        int nextY = y + moveDir[i].y;
        int nextX = x + moveDir[i].x;

        if(0 <= nextY && nextY < ROW_MAX){
            if(!visited[nextY][nextX] && PATH[nextY][nextX] == "."){
                bool flag = DFS(nextY, nextX);
                if(flag)
                    return flag;
            }
        }
    }
    return false;
}

int main(){
    input();

    int result = 0;
    for(int i = 0; i < ROW_MAX; i++){
        result += DFS(i, 0);
    }

    cout << result;
}