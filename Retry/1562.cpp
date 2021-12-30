#include <iostream>
#define DIVIDER 1000000000
#define MAX 101
#define BIT_MAX ((1 << 10 ) - 1)

using namespace std;

int N;
int DP[MAX][10][BIT_MAX + 1];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i <= 9; i++){
        DP[1][i][1 << i] = 1;
    }
}

void makeDP(){
    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= 9; j++){
            for(int bit = 0; bit <= BIT_MAX; bit++){
                if(j == 0)
                    DP[i][0][bit | (1 << 0)] = (DP[i][0][bit | (1 << 0)] + DP[i - 1][1][bit]) % DIVIDER;
                else if(j == 9)
                    DP[i][9][bit | (1 << 9)] = (DP[i][9][bit | (1 << 9)] + DP[i - 1][8][bit]) % DIVIDER;
                else{
                    DP[i][j][bit | (1 << j)] = (DP[i][j][bit | (1 << j)] + DP[i - 1][j-1][bit]) % DIVIDER;
                    DP[i][j][bit | (1 << j)] = (DP[i][j][bit | (1 << j)] + DP[i - 1][j+1][bit]) % DIVIDER;
                }
            }
        }
    }
}

int makeAns(){
    int result = 0;

    for(int i = 1; i <= 9; i++){
        result += DP[N][i][BIT_MAX];
        result %= DIVIDER;
    }

    return result;
}

int main(){
    input();
    makeDP();
    cout << makeAns();
}