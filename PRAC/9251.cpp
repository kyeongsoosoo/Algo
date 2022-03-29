#include <iostream>
#include <algorithm>

#define MAX 1005

using namespace std;

string A, B;
int len_a, len_b;
int DP[MAX][MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A;
    cin >> B;

    len_a = A.length();
    len_b = B.length();
}

void set_dp(){
    for(int i = 1; i <= len_a; i++){
        for(int j = 1; j <= len_b; j++){
            if(A[i - 1] == B[j - 1]){
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else{
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }
}

int main(){
    input();
    set_dp();

    cout << DP[len_a][len_b];
} 