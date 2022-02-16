#include <iostream>
#define C_MAX 101
#define N_MAX 1000000001

using namespace std;

int N, M;
long long K;
long long DP[C_MAX][C_MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for(int i = 0; i < C_MAX; i++){
        DP[i][0] = 1;
        DP[0][i] = 1;
    }

    for(int i = 1; i < C_MAX; i++){
        for(int j = 1; j < C_MAX; j++){
            DP[i][j] = DP[i][j - 1] + DP[i - 1][j];

            if(DP[i][j] > N_MAX) DP[i][j] = N_MAX;
        }
    }
}

void calcDP(int a_count, int z_count, long long total){
    // cout << '\n';
    // cout << "a: " << a_count << " z: " << z_count << " total: " << total << '\n';
    if(a_count == 0 && z_count == 0){
        return;
    }
    if(z_count == 0){
        cout << "a";
        calcDP(a_count - 1, z_count, total);
        return;
    }
    if(a_count == 0){
        cout << "z";
        calcDP(a_count, z_count - 1, total);
        return;
    }

    long long max_without_a = DP[a_count - 1][z_count];

    if(total <= max_without_a){
        cout << "a";
        calcDP(a_count - 1, z_count, total);
        return;
    }
    else{
        cout << "z";
        calcDP(a_count, z_count - 1, total - max_without_a);
        return;
    }
}

int main(){
    input();

    if(DP[N][M] < K){
        cout << -1;
        return 0;
    }

    calcDP(N, M, K);
}
