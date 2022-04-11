#include <iostream>
#include <cstring>

#define MAX 128

using namespace std;

int K;
int x, y;

int map[MAX][MAX];

int mark_counter = 1;

int move_r[4] = {0, 0, 1, 1};
int move_c[4] = {0, 1, 0, 1};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    cin >> x >> y;
}

void parsing(){
    memset(map, 0, sizeof(map));

    x -= 1;
    y = (1 << K) - y;

    // cout << y << " " << x << '\n';

    map[y][x] = -1;
}

// 0 | 1
// -----
// 2 | 3

int marked_zone(int size, int r_s, int c_s, int marked_r, int marked_c){
    int len = size / 2;

    int r_sum = r_s + len;
    int c_sum = c_s + len;

    if(marked_r < r_sum && marked_c < c_sum) return 0;
    if(marked_r < r_sum && marked_c >= c_sum) return 1;
    if(marked_r >= r_sum && marked_c < c_sum) return 2;
    return 3;
}

void build_center_tile(int marked_zone, int size, int r_s, int c_s){
    int len = size / 2;

    int x, y;
    for(int i = 0; i < 4; i++){
        if(marked_zone == i) continue;

        if(i == 0){
            y = r_s + len - 1;
            x = c_s + len - 1;
        }
        if(i == 1){
            y = r_s + len - 1;
            x = c_s + len;
        }
        if(i == 2){
            y = r_s + len;
            x = c_s + len - 1;
        }
        if(i == 3){
            y = r_s + len;
            x = c_s + len;
        }
        map[y][x] = mark_counter;
    }

    mark_counter += 1;
}

void solve(int size, int r_s, int c_s, int marked_r, int marked_c){
    
    if(size == 1) return;

    int len = size / 2;

    int marked = marked_zone(size, r_s, c_s, marked_r, marked_c);

    build_center_tile(marked, size, r_s, c_s);

    int x, y;

    for(int i = 0; i < 4; i++){
        int next_y = r_s + (move_r[i] * len);
        int next_x = c_s + (move_c[i] * len);

        if(marked == i) {
            solve(len, next_y, next_x, marked_r, marked_c);
            continue;
        }

        if(i == 0){
            y = r_s + len - 1;
            x = c_s + len - 1;
        }
        if(i == 1){
            y = r_s + len - 1;
            x = c_s + len;
        }
        if(i == 2){
            y = r_s + len;
            x = c_s + len - 1;
        }
        if(i == 3){
            y = r_s + len;
            x = c_s + len;
        }
        solve(len, next_y, next_x, y, x);
    }
}

void print_ans(){
    for(int i = 0; i < (1 << K); i++){
        for(int j = 0; j < (1 << K); j++){
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

// 4개로 쪼갠다
// 이미 선택된 노드가 있는 구역을 찾는다
// 나머지 구역의 꼭짓점을 모아 기역자 파이프를 설치한다
// 각 구역에서 해당 작업을 반복한다
// size가 2까지 내려왔다면 마지막으로 아닌 구역에 기역자를 깔아주고 종료

int main(){
    input();
    parsing();
    solve(1 << K, 0, 0, y, x);
    print_ans();
}