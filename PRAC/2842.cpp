#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>

#define MAX 51
#define INF 987654321

using namespace std;

int N;
int k_count = 0;
char map[MAX][MAX];
int cost_map[MAX][MAX];
bool visited[MAX][MAX];
int p_y, p_x;

set<int> cost_vector;

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, -1, 0, 1, -1, 0, 1};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    string tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        for(int j = 0; j < N; j++){
            map[i][j] = tmp[j];


            if(tmp[j] == 'P'){
                p_y = i;
                p_x = j;
            }
            if(tmp[j] == 'K'){
                k_count += 1;
            }
        }
    }

    int cost;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> cost;
            cost_map[i][j] = cost;
            cost_vector.insert(cost);
        }
    }
}

bool can_move(int y, int x, int lower, int upper){
    if(y < 0 || y >= N || x < 0 || x >= N) return false;
    if(visited[y][x]) return false;
    if(cost_map[y][x] < lower || cost_map[y][x] > upper) return false;
    // cout << cost_map[y][x] << " " << lower  << " " << upper << '\n';
    return true;
}

bool bfs_check(int lower, int upper){
    queue<pair<int, int> > Q;
    memset(visited, false, sizeof(visited));

    if(!can_move(p_y, p_x, lower, upper)) return false;

    Q.push(make_pair(p_y, p_x));

    int counter = 0;

    while(!Q.empty()){
        pair<int, int> P = Q.front(); Q.pop();

        if(map[P.first][P.second] == 'K'){
            counter += 1;
        }
        if(counter == k_count){
            break;
        }

        for(int i = 0; i < 8; i++){
            int next_y = P.first + dy[i];
            int next_x = P.second + dx[i];

            if(!can_move(next_y, next_x, lower, upper)) continue;

            Q.push(make_pair(next_y, next_x));
            visited[next_y][next_x] = true;
        }
    }

    if(counter == k_count) return true;
    return false;
}

void solve(){
    auto start = cost_vector.begin();
    auto end = cost_vector.begin();

    int min_ans = INF;

    while(start != cost_vector.end()){
        bool can_move = bfs_check(*start, *end);

        if(can_move){
            min_ans = min(min_ans, *end - *start);
            start++;

            if(min_ans == 0) break;
        }
        else if(end != cost_vector.end()){
            end++;
        }
        else{
            break;
        }
    }

    cout << min_ans;
}

int main(){
    input();
    solve();
}
