#include <iostream>
#include <cstring>
#define MAX 10

using namespace std;

int n;
int board[MAX][MAX];
bool visit_board[MAX][MAX];

int WHITE = 0;
int BLACK = 1;

int max_counter = 0;
int ans_counter = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
}

int make_color(int y, int x){
    if((y + x ) % 2) return BLACK;
    return WHITE;
}

bool onLine(int y, int x, int y2, int x2){
    if(abs(y2 - y) == abs(x2 -x)) return true;
    return false;
}

bool check_bishop(int y, int x){
    for(int i = y - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(onLine(y, x, i, j)){
                if(visit_board[i][j]){
                    return false;
                }
            }
        }
    }
    return true;
}

void resetBoard(){
    memset(visit_board, 0, sizeof(visit_board));
    max_counter = 0;
}

void backTrackBoard(int y, int x, int color, int count){
    // cout << count << '\n';
    for(int row = y; row < n; row++){
        for(int col = 0; col < n; col++){
            int next_color = make_color(row, col);

            // if(row == 2 && col == 0) cout << board[row][col] << '\n';
            if(row == y && col < x) continue;
            if(color != next_color) continue;
            if(board[row][col] == 0) continue;
            if(visit_board[row][col]) continue;
            if(!check_bishop(row, col)) continue;

            visit_board[row][col] = true;
            if(count + 1 > max_counter) max_counter = count + 1;
            // cout << "row: " << row << " col: " << col << " counter: " << count << '\n';
            backTrackBoard(row, col, color, count + 1);
            visit_board[row][col] = false;
        }
    }
    // cout << "done" << '\n';
}

int main(){
    input();

    // visit_board[0][0] = true;
    backTrackBoard(0, 0, WHITE, 0);
    ans_counter += max_counter;

    resetBoard();

    backTrackBoard(0, 1, BLACK, 0);
    ans_counter += max_counter;

    cout << ans_counter;

}

// 비숍은 흑백으로 나뉨
// 백트래킹으로 진행
// 대각선으로 올라가면서 검사