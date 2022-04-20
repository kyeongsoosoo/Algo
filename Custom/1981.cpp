#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>

#define MAX 110
#define LIMIT 201
#define INF 987654321

using namespace std;

typedef pair<int, int> P;

int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
set<int> num_arr;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            num_arr.insert(map[i][j]);
        }
    }
}

bool can_move(int y, int x, int lower, int upper){
    if(y < 0 || y >= N || x < 0 || x >= N) return false;
    if(map[y][x] < lower || map[y][x] > upper) return false;
    if(visited[y][x]) return false;
    return true;
}

bool check_bfs(int lower, int upper){
    memset(visited, false, sizeof(visited));

    queue<P> Q;

    if(!can_move(0, 0, lower, upper)) return false;

    Q.push(make_pair(0, 0));
    visited[0][0] = true;

    while(!Q.empty()){
        P cur = Q.front(); Q.pop();

        if(cur.first == N - 1 && cur.second == N - 1) return true;

        for(int i = 0; i < 4; i++){
            int next_y = cur.first + dy[i];
            int next_x = cur.second + dx[i];

            if(!can_move(next_y, next_x, lower, upper)) continue;

            visited[next_y][next_x] = true;
            Q.push(make_pair(next_y, next_x));
        }
    }

    return false;
}

void solve(){
    auto start = num_arr.begin();
    auto end = num_arr.begin();

    int ans = INF;

    while(start != num_arr.end()){
        bool can_reach = check_bfs(*start, *end);

        if(can_reach){
            int diff = *end - *start;

            ans = min(ans, diff);
            start++;

            if(diff == 0) break;
        }
        else if(end != num_arr.end()){
            end++;
        }
        else{
            break;
        }
    }

    cout << ans;
}

int main(){
    input();
    solve();
}