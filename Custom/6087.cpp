#include <iostream>
#include <cstring>
#include <queue>

#define endl "\n"
#define MAX 100
#define INF 987654321

using namespace std;

int W, H;
char MAP[MAX][MAX];
int visit[MAX][MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

pair<int, int> start, map_end;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tmp = 0;

    cin >> W >> H;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 'C'){
                if(tmp == 0){
                    start.first = i;
                    start.second = j;
                    tmp++;
                }
                else{
                    map_end.first = i;
                    map_end.second = j;
                }
            }
            visit[i][j] = INF;
        }
    }
}

int bfs(int a, int b){
    queue<pair<pair<int, int>, pair<int, int>>> Q;

    for(int i = 0; i < 4; i++){
        Q.push(make_pair(make_pair(a, b), make_pair(i, 0)));
    }
    visit[a][b] = 0;

    while(!Q.empty()){
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int dir = Q.front().second.first;
        int cnt = Q.front().second.second;

        Q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nCnt = cnt;

            if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if(MAP[nx][ny] == '*') continue;
            if(dir != i) nCnt += 1;
            if(visit[nx][ny] >= nCnt){
                visit[nx][ny] = nCnt;
                Q.push(make_pair(make_pair(nx, ny), make_pair(i, nCnt)));
            }
        }
    }
    return visit[map_end.first][map_end.second];
}

void solve(){
    int ans = bfs(start.first, start.second);
    cout << ans;
}

int main(){
    input();
    solve();
}