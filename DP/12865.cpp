#include <iostream>
#include <algorithm>

using namespace std;

int N;
int K;
int W[100];
int V[100];
int DP[100001][101];

void input(){
    cin >> N;
    cin >> K;
    for(int i = 0; i < N; i++){
        cin >> W[i];
        cin >> V[i];
    }
}

void setDP(){
    for(int weight = 0; weight <= K; weight++){
        for(int num = 0; num <= N; num++){
            if( num == 0 || weight == 0){
                DP[weight][num] = 0;
            }
            else if( weight < W[num-1])
                DP[weight][num] = DP[weight][num-1];
            else
                DP[weight][num] = max(DP[weight][num-1], DP[weight - W[num - 1]][num-1] + V[num - 1]);
        }
    }
}

int main(){
    input();
    setDP();

    cout << DP[K][N];
}