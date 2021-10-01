#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000];
int DP[1000];
int reversed_dp[1000];

void input(){
    cin >> N;
    int inp;
    for(int i=0; i<N; i++){
        cin >> inp;
        arr[i] = inp;
    }
}

void setReverseDP(){
    for(int i = N - 1; i>=0; i--){
        reversed_dp[i] = 1;
        for(int j = i + 1; j <= N - 1; j++){
            if(arr[i] > arr[j]){
                reversed_dp[i] = max(reversed_dp[i], reversed_dp[j] + 1);
            }
        }
    }
}

void setDP(){
    for(int i = 0; i < N; i++){
        DP[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(arr[i] > arr[j]){
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }
}

int findMaxBitonic(){
    int max_n = -1;
    for(int i = 0; i < N; i++){
        max_n = max(max_n, DP[i] + reversed_dp[i] - 1);
    }

    return max_n;
}



int main(){
    input();
    setReverseDP();
    setDP();

    cout << findMaxBitonic();
}