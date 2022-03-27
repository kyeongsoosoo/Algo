#include <iostream>
#include <cstring>

#define N_MAX 110
#define W_MAX 100005

using namespace std;

int N, K;
int W[N_MAX];
int V[N_MAX];
int DP[W_MAX][N_MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> W[i] >> V[i];
    }
}

void make_dp(){
    memset(DP, 0, sizeof(DP));

    for(int weight = 0; weight <= K; weight++){
        for(int i = 0; i <= N; i++){
            if(weight == 0 || i ==0) continue;

            if(weight < W[i]) {
                DP[weight][i] = DP[weight][i - 1];
                continue;
            }
            DP[weight][i] = max(DP[weight][i - 1], DP[weight - W[i]][i - 1] + V[i]);
        }
    }
}

int main(){
    input();
    make_dp();

    cout << DP[K][N];
}