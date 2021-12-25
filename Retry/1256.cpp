#include <iostream>
#include <math.h>
#define MAX 201
#define LIMIT (long long)3000000001

using namespace std;

int N, M;
long long DP[MAX][MAX];
long long K;
long long max_idx;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    DP[1][0] = 1;
    DP[1][1] = 1;

    for(int i = 2; i < MAX; i++){
        for(int j = 0; j <= i; j++){
            DP[i][j] = min(LIMIT, DP[i - 1][j - 1] + DP[i - 1][j]);
        }
    }
}

long long avail(int a, int b){
    return DP[a + b][b];
}

void makeString(int a_index, int z_index, int cnt, int total_index){
    if(total_index <= 0) return;
    if(a_index == 0){
        cout << 'z';
        makeString(a_index, z_index - 1, cnt - avail(a_index - 1, z_index), total_index - 1);
    }
    else if(z_index == 0){
        cout << 'a';
        makeString(a_index - 1, z_index, cnt, total_index - 1);
    }
    else if(avail(a_index - 1, z_index) >= cnt){
        cout << 'a';
        makeString(a_index - 1, z_index, cnt, total_index - 1);
    }
    else{
        cout << 'z';
        makeString(a_index, z_index - 1, cnt - avail(a_index - 1, z_index), total_index - 1);
    }
}



int main(){
    input();
    max_idx = DP[N + M][M];

    if(max_idx < K){
        cout << -1;
        return 0;
    }

    makeString(N, M, K, N + M);
}