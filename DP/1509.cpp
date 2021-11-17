#include <iostream>
#define MAX 2501
#define INF 987654321

using namespace std;

string S;

bool Palin[MAX][MAX];
int DP[MAX] = {0, };

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S;

    for(int i = 0; i <= S.size() - 1; i++){
        Palin[i][i] = true;
    }

    for(int i = 0; i <= S.size() - 1; i++){
        if(S[i] == S[i + 1]){
            Palin[i][i + 1] = true;
        }
    }
}

void findPalin(){
    for(int len = 3; len <= S.size(); len++){
        for(int start = 0; start <= S.size() - len; start++){
            int end = start + len - 1;

            int left = start + 1;
            int right = end - 1;
            if(Palin[left][right] && S[start] == S[end]){
                Palin[start][end] = true;
            }
        }
    }
}

void makeDP(){
    for(int end = 1; end <= S.size(); end++){
        DP[end] = INF;
        for(int start = 1; start <= end; start++){
            if(Palin[start - 1][end - 1]){
                DP[end] = min(DP[end], DP[start - 1] + 1);
            }
        }
    }
}


int main(){
    input();
    findPalin();
    makeDP();
    cout << DP[S.size()];
}