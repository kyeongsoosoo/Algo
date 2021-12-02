#include <iostream>
#include <vector>
#define MAX 20

using namespace std;

int R, C;
int matrix[MAX][MAX];
bool visited[MAX][MAX];
bool checked[100];
vector<int> ST;
int ans_count = 1;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    string tmp;

    for(int i = 0; i < R; i++){
        cin >> tmp;
        for(int j = 0; j < C; j++){
            matrix[i][j] = tmp[j];
        }
    }
}

bool passCondition(int y, int x){
    if(y >= R || y < 0 || x >= C || x < 0) return false;

    int num = matrix[y][x];
    if(checked[matrix[y][x] - 64]) return false;
    return true;
}

void makeDFS(int y, int x, int count){
    if(visited[y][x]) return;
    if(!passCondition(y, x)) return;

    visited[y][x] = true;
    checked[matrix[y][x] - 64] = true;
    ans_count = max(ans_count, count);

    for(int i = 0; i < 4; i++){
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        makeDFS(next_y, next_x, count + 1);
    }
    visited[y][x] = false;
    checked[matrix[y][x] - 64] = false;
}


int main(){
    input();
    makeDFS(0, 0, 1);
    cout << ans_count;
}