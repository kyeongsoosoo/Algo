#include <iostream>

#define MAX 40000

using namespace std;

int N;
int DP[MAX][5];


void make_dp(){
    for(int i = 1; i * i < MAX; i++){
        DP[i * i][1] = 1;

        for(int j = i * i; j < MAX; j++){
            DP[j][2] += DP[j - (i * i)][1];
            DP[j][3] += DP[j - (i * i)][2];
            DP[j][4] += DP[j - (i * i)][3];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    make_dp();

    while(true){
        cin >> N;

        if(N == 0) return 0;

        int ans = 0;

        for(int i = 1; i <= 4; i++){
            ans += DP[N][i];
        }

        cout << ans << '\n';
    }

    return 0;
}