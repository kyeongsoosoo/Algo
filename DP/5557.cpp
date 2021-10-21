#include <iostream>

using namespace std;

int N;
int num[101];
long long DP[101][21];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> num[i];
    }
}

bool checkConstraint(int n){
    if(n < 0) return false;
    if(n > 20) return false;
    return true;
}

void makeDP(){
    DP[1][num[1]] = 1;

    for(int idx = 2; idx <= N; idx++){

        for(int n = 0; n <= 20; n++){
            int idx_num = num[idx];
            int plus = n + idx_num;
            int minus = n - idx_num;

            if(DP[idx-1][n] == 0) continue;
            if(checkConstraint(plus)){
                DP[idx][plus] += DP[idx-1][n];
                // cout << DP[idx][plus] << '\n';
            }
            if(checkConstraint(minus)){
                DP[idx][minus] += DP[idx-1][n];
            }
        }
    }
}

int main(){
    input();

    makeDP();

    cout << DP[N-1][num[N]];
}