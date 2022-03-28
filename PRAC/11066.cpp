#include <iostream>
#include <cstring>

#define MAX 505
#define INF 987654321

using namespace std;

int TC;
int K;
int pages[MAX];
int DP[MAX][MAX];
int SUM[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
}

void case_input(){
    memset(pages, 0, sizeof(pages));
    memset(SUM, 0, sizeof(SUM));

    cin >> K;

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            DP[i][j] = INF;
        }
    }

    for(int i = 1; i <= K; i++){
        cin >> pages[i];
    }
}

void range_sum(){
    for(int i = 1; i <= K; i++){
            SUM[i] = SUM[i - 1] + pages[i];
    }
}

int make_dp(int left, int right){
    if(DP[left][right] != INF) return DP[left][right];
    if(left == right) return 0;

    int diff = SUM[right] - SUM[left - 1];

    for(int i = left; i < right; i++){
        DP[left][right] = min(DP[left][right], make_dp(left, i) + make_dp(i + 1, right) + diff);
    }

    return DP[left][right];
}

int main(){
    input();

    while(TC--){
        case_input();
        range_sum();
        int ans = make_dp(1, K);
        cout << ans << '\n';
    }
}