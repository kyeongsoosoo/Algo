#include <iostream>
#include <cstring>
#define MAX 501
#define INF 987654321

using namespace std;

int T;
int K;
int arr[MAX];
int sum[MAX];
int DP[MAX][MAX];


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

void caseInput(){
    cin >> K;
    memset(arr, 0, sizeof(arr));
    memset(sum, 0, sizeof(sum));
    memset(DP, 0, sizeof(DP));

    for(int i = 1; i <= K; i++){
        cin >> arr[i];
    }
}

void calcCumulativeSum(){
    for(int i = 1; i <= K; i++){
        sum[i] = sum[i-1] + arr[i];
    }
}

void makeDP(){
    for(int page_len = 1; page_len <= K; page_len++){
        for(int start_idx = 1; start_idx <= K - page_len + 1; start_idx++){
            int end_idx = start_idx + page_len - 1;
            int page_total = sum[end_idx] - sum[start_idx - 1];
            if(start_idx == end_idx){
                DP[start_idx][start_idx] = 0;
                continue;
            } 
            DP[start_idx][end_idx] = INF;
            for(int mid_idx = start_idx; mid_idx <= end_idx - 1; mid_idx++){
                DP[start_idx][end_idx] = min(DP[start_idx][end_idx], DP[start_idx][mid_idx] + DP[mid_idx + 1][end_idx] + page_total);
            }
        }
    }
}

int main(){
    input();

    while(T--){
        caseInput();
        calcCumulativeSum();
        makeDP();
        cout << DP[1][K] << '\n';
    }
}