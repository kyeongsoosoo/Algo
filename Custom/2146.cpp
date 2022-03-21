#include <iostream>
#include <cstring>
#include <queue>

#define MAX 101
#define INF 987654321

using namespace std;

int N;
int map[MAX][MAX];
int mark[MAX][MAX];
bool visit[MAX][MAX];
int zone = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int min_cost = INF;


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
   }
}

bool can_move(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= N) return false;
    if(visit[y][x]) return false;
    if(map[y][x] == 0) return false;
    return true;
}

void mark_zone(int x, int y){
    visit[y][x] = true;
    mark[y][x] = zone;

    for(int i = 0; i < 4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(!can_move(next_x, next_y)) continue;

        mark_zone(next_x, next_y);
    }
}

void mark_all(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visit[i][j] && map[i][j]){
                zone += 1;
                mark_zone(j, i);
            }
        }
    }
}

bool can_construct(int x, int y, int origin){
    if(x < 0 || x >= N || y < 0 || y >= N) return false;
    if(visit[y][x]) return false;
    if(mark[y][x] == origin) return false;
    return true;
}

void find_by_bfs(int x, int y){
    memset(visit, false, sizeof(visit));
    queue<pair<int, pair<int, int>>> Q;
    Q.push(make_pair(0, make_pair(x, y)));
    int origin = mark[y][x];

    while(!Q.empty()){
        pair<int, pair<int, int>> cur = Q.front(); Q.pop();

        int cur_cost = cur.first;
        int cur_x = cur.second.first;
        int cur_y = cur.second.second;

        for(int i = 0; i < 4; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            int next_cost = cur_cost + 1;

            if(!can_construct(next_x, next_y, origin)) continue;

                // cout << "x: " << next_x << " y: " << next_y << " zone: " << mark[next_y][next_x] << " origin: " << origin << '\n'; 
            if(map[next_y][next_x] && mark[next_y][next_x] != origin){
                min_cost = min(min_cost, cur_cost);
                return;
            }

            if(map[next_y][next_x] != 0) continue;

            visit[next_y][next_x] = true;
            Q.push(make_pair(next_cost, make_pair(next_x, next_y)));
        }
    }
}

void solve(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j]) find_by_bfs(j, i);
        }
    }

    cout << min_cost;
}

int main(){
    input();
    mark_all();
    solve();
}