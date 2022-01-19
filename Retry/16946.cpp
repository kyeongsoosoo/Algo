#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1001
#define LABEL_MAX 1000001

using namespace std;

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int group[MAX][MAX];
int label[LABEL_MAX];
vector<int> used;

int block_idx = 1;

int x_move[4] = {0, 0, -1, 1};
int y_move[4] = {1, -1, 0, 0};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    string s;
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < M; j++){
            map[i][j] = s[j] - '0';
        }
    }
}

bool checkCondition(int y, int x){
    if(y < 0 || y >= N || x < 0 || x >= M){
        return false;
    }
    if(map[y][x] == 1) return false;
    if(visited[y][x]) return false;
    return true;
}

void labelling(int y, int x, int label_idx){
    if(!checkCondition(y, x)) return;

//     cout << "y: " << y << " x: " << x << " idx: " << label_idx
//  << '\n';
    visited[y][x] = true;
    group[y][x] = label_idx;
    label[label_idx] += 1;
    label[label_idx] %= 10;

    for(int i = 0; i < 4; i++){
        int next_y = y + y_move[i];
        int next_x = x + x_move[i];

        labelling(next_y, next_x, label_idx);
    }
}

bool hasLabel(int idx){
    for(int i = 0; i < used.size(); i++){
        if(used[i] == idx) return true;
    }
    return false;
}

int countBlock(int y, int x){
    used.clear();
    int sum = 0;

    for(int i = 0; i < 4; i++){
        int next_y = y + y_move[i];
        int next_x = x + x_move[i];

        int move_label = group[next_y][next_x];

        if(move_label != 0 && !hasLabel(move_label)) {
//             cout << "y: " << next_y << " x: " << next_x << " idx: " << label[move_label]
//  << '\n';
            used.push_back(move_label);
            sum += label[move_label];
        }
    }

    return (sum + 1) % 10;
}

void solve(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(checkCondition(i, j)){
                labelling(i, j, block_idx);
                block_idx += 1;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 1){
                // cout << i << " " << j << '\n';
                int res = countBlock(i, j);
                cout << res;
            }
            else{
                cout << 0;
            }
        }
        cout << '\n';
    }
}

int main(){
    input();
    solve();
}