#include <iostream>
#define MAX 1000
#define INF 987654321

using namespace std;

int N;
int cost[MAX][3];
int DP[MAX][3][3];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> cost[i][j];
        }
    }
}

int makeDP(int start_color, int used_color, int idx){
    if(DP[idx][used_color][start_color]) return DP[idx][used_color][start_color];
    if(idx == N - 1) {
        if(start_color == used_color) return INF;
        return cost[idx][used_color];
    }

    int next_color1 = (used_color + 1) % 3;
    int next_color2 = (used_color + 2) % 3;

    DP[idx][used_color][start_color] = min(
        makeDP(start_color, next_color1, idx + 1) + cost[idx][used_color], 
        makeDP(start_color, next_color2, idx + 1) + cost[idx][used_color]
    );

    // cout << "idx: " << idx << " used: " << used_color << " dp: " << DP[idx][used_color][start_color] << '\n';

    return DP[idx][used_color][start_color];
}

void solve(){
    int ans = INF;
    for(int i = 0; i < 3; i++){
        ans = min(ans, makeDP(i, i, 0));
    }

    cout << ans;
}

int main(){
    input();
    solve();
}