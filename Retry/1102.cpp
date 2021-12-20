#include <iostream>
#include <cstring>
#define MAX 16
#define INF 987654321

using namespace std;

int N;
int P;
int arr[MAX][MAX];
int DP[MAX][1 << MAX];
string default_state;
int default_bit = 0;
int level = 0;
int Ans = INF;

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

    cin >> default_state;

    for(int i = 0; i < default_state.size(); i++){
        if(default_state[i] == 'Y'){
            default_bit = default_bit | (1 << i);
            level += 1;
        }
    }

    cin >> P;

    memset(DP, -1, sizeof(DP));
}

int makeDP(int cur_level, int cur_bit){
    if(cur_level >= P) return 0;
    if(DP[cur_level][cur_bit] != -1) return DP[cur_level][cur_bit];

    DP[cur_level][cur_bit] = INF;

    for(int factory = 0; factory < N; factory++){
        if(!(cur_bit & (1 << factory))) continue;

        for(int next_fac = 0; next_fac < N; next_fac++){
            if(cur_bit & (1 << next_fac)) continue;
            int next_bit = cur_bit | 1 << next_fac;

            DP[cur_level][cur_bit] = min(DP[cur_level][cur_bit], arr[factory][next_fac] + makeDP(cur_level + 1, next_bit));
        }
    }
    return DP[cur_level][cur_bit];
}

int main(){
    input();
    Ans = makeDP(level, default_bit);
    cout << (Ans == INF ? -1 : Ans);
}