#include <iostream>
#include <cstring>
#define MAX 16
#define MAX_DP ((1 << 16 )- 1)
#define INF 987654321

using namespace std;

int N;
int arr[MAX][MAX];
int DP[MAX][MAX_DP + 1];
int ans_dp;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    ans_dp = (1 << N) - 1;

    memset(DP, -1, sizeof(DP));
}

int makeRoute(int idx, int cur_bit){
    if(cur_bit == ans_dp){
        if(arr[idx][0]) return arr[idx][0];
        else return INF;
    }

    if(DP[idx][cur_bit] != -1) return DP[idx][cur_bit];

    DP[idx][cur_bit] = INF;

    for(int i = 0; i < N; i++){
        if(((1 << i) & cur_bit)) continue;
        if(arr[idx][i] == 0) continue;
        int next_bit = cur_bit | (1 << i);

        DP[idx][cur_bit] = min(DP[idx][cur_bit], makeRoute(i, next_bit) + arr[idx][i]);
    }

    // cout << DP[idx][cur_bit] << '\n';
    return DP[idx][cur_bit];
}

int main(){
    input();
    int ans = makeRoute(0, 1);
    cout << ans;
}