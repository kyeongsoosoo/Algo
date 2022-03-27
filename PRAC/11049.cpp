#include <iostream>
#include <cstring>

#define MAX 501
#define INF (1 << 30)

using namespace std;

int N;
int R[MAX];
int C[MAX];
int DP[MAX][MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            DP[a][b] = INF;
        }
    }


    for(int i = 0; i < N; i++){
        cin >> R[i] >> C[i];
        DP[i][i] = 0;    
    }
}

int make_dp(int left, int right){
    if(DP[left][right] != INF) return DP[left][right];

    for(int i = left; i < right; i++){
        DP[left][right] = min(DP[left][right], make_dp(left, i) + make_dp(i + 1, right) + (R[left] * C[i] * C[right]));
    }

    return DP[left][right];
}

int main(){
    input();
    int ans = make_dp(0, N - 1);
    cout << ans;
}