#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#define MAX 1001

using namespace std;

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];

int y_move[4] = {0, 0, 1, -1};
int x_move[4] = {1, -1, 0, 0};

queue<pair<int, int>> Q;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    string rows;
    for(int i = 0; i < N; i++){
        cin >> rows;
        for(int j = 0; j < M; j++){
            map[i][j] = rows[j] - '0';

            if(map[i][j] == 1){
                Q.push(make_pair(i, j));
            }
        }
    }
}

bool passCondition(int y, int x){
    if(y < 0 || y >= N || x < 0 || x >= M) return false;
    return true;
}

int recursion(int y, int x){
    int result = 1;
    if(visited[y][x] || map[y][x] != 0) return 0;
    // cout << y << " " << x << '\n';

    visited[y][x] = true;

    for(int i = 0; i < 4; i++){
        int next_y = y + y_move[i];
        int next_x = x + x_move[i];

        if(passCondition(next_y, next_x)){
            result += recursion(next_y, next_x);
        }
    }

    return result % 10;
}

void makeDFS(){
    while(!Q.empty()){
        memset(visited, false, sizeof(visited));
        pair<int, int> coord = Q.front(); Q.pop();
        int y = coord.first;
        int x = coord.second;

        map[y][x] = 0;

        int result = (recursion(y, x)) % 10;

        // cout << result << '\n';

        map[y][x] = result;
    }
}

void printAns(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
}

int main(){
    input();
    makeDFS();
    printAns();
}