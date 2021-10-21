#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321

using namespace std;

int N;
int matrix[500][2];
int DP[501][501];

int ROW = 0;
int COL = 1;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    fill(&DP[0][0], &DP[500][501], INF);

    for(int i = 0; i < N; i++){
        cin >> matrix[i][0];
        cin >> matrix[i][1];

        DP[i][i] = 0;
    }

}

void makeDP(){
    for(int len = 2; len <= N; len++){
        for(int start = 0; start <= N - len; start++){
            for(int mid = start; mid < start + len - 1; mid++){
                DP[start][start + len - 1] = min(DP[start][start + len - 1], DP[start][mid] + DP[mid + 1][start + len - 1] + (matrix[start][ROW] * matrix[mid][COL] * matrix[start + len - 1][COL]));
            }
        }
    }
}

int main(){
    input();
    makeDP();

    cout << DP[0][N-1];
}    