#include <iostream>
#include <vector>
#define MAX 11

using namespace std;

int N;
int board[MAX][MAX];
int visited[MAX][MAX];
vector<pair<int, int>> pos_set;
int black_count = 0;
int white_count = 0;

int BLACK = 1;
int WHITE = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
}

bool passCondition(int x1, int y1, int x2, int y2){
    int x_diff = abs(x1 - x2);
    int y_diff = abs(y1 - y2);

    if(x_diff == y_diff) return false;
    return true;
}

bool totalCheckInPosition(int cur_x, int cur_y){
    for(int i = 0; i < pos_set.size(); i++){
        int pos_y = pos_set[i].second;
        int pos_x = pos_set[i].first;

        if(!passCondition(cur_x, cur_y, pos_x, pos_y)){
            return false;
        }
    }
    return true;
}

int getColor(int x_pos, int y_pos){
    if(((x_pos + y_pos) % 2) == 1) return WHITE;
    return BLACK; 
}

void trackBoard(int y_pos, int x_pos, int color){
    if(!totalCheckInPosition(x_pos, y_pos)) return;
    if(board[y_pos][x_pos] == 0) return;
    if(visited[y_pos][x_pos]) return;

    if((color == BLACK) && (pos_set.size() > black_count)){
        // cout << "ans pos: " << y_pos << " " << x_pos << '\n';
        black_count = pos_set.size();
    }
    if((color == WHITE) && (pos_set.size() > white_count)){
        // cout << "ans pos: " << y_pos << " " << x_pos << '\n';
        white_count = pos_set.size();
    }

    pos_set.push_back(make_pair(x_pos, y_pos));
    visited[y_pos][x_pos] = 1;

    for(int next_y = y_pos; next_y < N; next_y++){
        for(int next_x = 0; next_x < N; next_x++){
            int nextColor = getColor(next_x, next_y);
            if(nextColor == color){
                trackBoard(next_y, next_x, color);
            }
        }
    }

    visited[y_pos][x_pos] = 0;
    pos_set.pop_back();
}

void makeAns(){
    for(int i = 0; i < N; i++){
        if(i % 2 == 0) 
            trackBoard(0, i, BLACK);
        else
            trackBoard(0, i, WHITE);
    }
}

int main(){
    input();
    makeAns();

    cout << white_count + black_count + 2;
}