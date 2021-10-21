#include <iostream>
#define mod 1000000000

using namespace std;

int N;
int DP[101][10][1 << 10];
int MAX = (1 << 10) - 1;

void input(){
    cin >> N;

    for(int i = 1; i <= 9; i++){
        DP[1][i][1 << i] = 1;
    }
}

void makeDP(){
    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= 9; j++){
            for(int bit = 0; bit <= MAX; bit++){
                if(j == 0)
                    DP[i][0][bit | (1 << 0)] = (DP[i][0][bit | (1 << 0)] + DP[i - 1][1][bit]) % mod;
                else if(j == 9)
                    DP[i][9][bit | (1 << 9)] = (DP[i][9][bit | (1 << 9)] + DP[i - 1][8][bit]) % mod;
                else{
                    DP[i][j][bit | (1 << j)] = (DP[i][j][bit | (1 << j)] + DP[i - 1][j-1][bit]) % mod;
                    DP[i][j][bit | (1 << j)] = (DP[i][j][bit | (1 << j)] + DP[i - 1][j+1][bit]) % mod;
                }

            }
        }
    }
}

int main(){
    input();
    makeDP();

    int ans = 0;
    for(int i = 0; i <= 9; i++){
        ans = (ans + DP[N][i][MAX]) % mod;
    }

    cout << ans;
}


