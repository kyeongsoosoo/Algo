#include <iostream>
#include <cstring>

#define endl "\n"
#define MAX 2510
#define INF 987654321

using namespace std;

int N;
int DP[MAX];
string S;
bool Palindrome[MAX][MAX];

int Min(int A, int B){
    return A < B ? A : B;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S;

    for(int i = 0; i <= S.size() - 1; i++){
        Palindrome[i][i] = true;
    }

    for(int i = 0; i <= S.size() - 1; i++){
        if(S[i] == S[i + 1]){
            Palindrome[i][i + 1] = true;
        }
    }
}

void make_palin(){
    for(int len = 3; len <= S.size(); len++){
        for(int start = 0; start <= S.size() - len; start++){
            int end = start + len - 1;

            int left = start + 1;
            int right = end - 1;
            if(Palindrome[left][right] && S[start] == S[end]){
                Palindrome[start][end] = true;
            }
        }
    }
}

void makeDP(){
    for(int end = 1; end <= S.size(); end++){
        DP[end] = INF;
        for(int start = 1; start <= end; start++){
            if(Palindrome[start - 1][end - 1]){
                DP[end] = min(DP[end], DP[start - 1] + 1);
            }
        }
    }
}

int main(){
    input();
    make_palin();
    makeDP();
    cout << DP[S.size()];
}