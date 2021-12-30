#include <iostream>
#define DIVIDER 1000000000
#define MAX 101

using namespace std;

int N;
int DP[MAX][10];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i <= 9; i++){
        DP[1][i] = 1;
    }
}

void makeDP(){
    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= 9; j++){
            if(j == 9) DP[i][9] = DP[i - 1][8] % DIVIDER;
            else if(j == 0) DP[i][0] = DP[i - 1][1] % DIVIDER;
            else{
                DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % DIVIDER;
            }
        }
    }
}

int makeAns(){
    int ans = 0;

    for(int i = 1; i <= 9; i ++){
        ans += DP[N][i];
        ans %= DIVIDER;
    }

    return ans;
}

int main(){
    input();
    makeDP();
    cout << makeAns();
}