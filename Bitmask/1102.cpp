#include <iostream>
#include <string>
#include <cstring>
#define N_MAX 16
#define COST_MAX 36
#define INF 987654321

using namespace std;

int N, P, Ans = INF;
int FACTORY[N_MAX][N_MAX];
int Cost[1 << N_MAX];
string S;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j =0 ; j < N; j++){
            cin >> FACTORY[i][j];
        }
    }

    cin >> S;

    cin >> P;
}

int Bit_Count(int B){
    int cnt = 0;
    while(B != 0){
        cnt = cnt + ( B & 1);
        B = B >> 1;
    }
    return cnt;
}

int DFS(int state){
    if(Bit_Count(state) >= P) return 0;
    if(Cost[state] != -1) return Cost[state];

    Cost[state] = INF;
    for(int i = 0; i < N; i++){
        if((state & (1 << i)) == 0) continue;
        for(int j = 0; j < N; j++){
            if((state & (1 << j)) == 0){
                int next_state = state | (1 << j);
                Cost[state] = min(Cost[state], FACTORY[i][j] + DFS(next_state));
            }
        } 
    }
    return Cost[state];
}

void solve(){
    int bit_state = 0;
    for(int i = 0; i < S.length(); i++){
        if(S[i] == 'Y') bit_state = bit_state | (1 << i);
    }
    memset(Cost, -1, sizeof(Cost));
    Ans = DFS(bit_state);

    if(Ans == INF) cout << -1;
    else cout << Ans;
}

int main(){
    input();
    solve();
}