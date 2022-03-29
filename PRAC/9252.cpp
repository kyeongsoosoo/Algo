#include <iostream>
#include <algorithm>

#define MAX 1005

using namespace std;

string A, B;
int len_a, len_b;
int DP[MAX][MAX];
string S = "";

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

void set_string(){
    int a = len_a;
    int b = len_b;

    while(a > 0 && b > 0){
        if(A[a - 1] == B[b - 1]){
            S += A[a - 1];
            a -= 1;
            b -= 1;
        }
        else{
            if(DP[a][b] == DP[a - 1][b]){
                a -= 1;
            }
            else{
                b -= 1;
            }
        }
    }
}

void print_ans(){
    for(int i = S.length() - 1; i >= 0; i--){
        cout << S[i];
    }
}

int main(){
    input();
    set_dp();
    set_string();

    cout << DP[len_a][len_b] << '\n';
    print_ans();
    
} 