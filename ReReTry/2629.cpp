#include <iostream>
#define MAX_NUM 30
#define MAX_WEIGHT 15001

using namespace std;

bool DP[MAX_NUM][MAX_WEIGHT];

int N, TC;
int arr[MAX_NUM];
int TC_ARR[7];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    cin >> TC;

    for(int i = 0; i < TC; i++){
        cin >> TC_ARR[i];
    }
}

void makeDP(){
    DP[0][0] = true;
    DP[0][arr[0]] = true;

    for(int i = 1; i < N; i++){
        int selected = arr[i];
        DP[i][0] = true;

        for(int j = 0; j < MAX_WEIGHT; j++){
            if(DP[i - 1][j]){
                DP[i][j] = true;

                if(j > selected){
                    DP[i][j - selected] = true;
                }
                if(selected > j){
                    DP[i][selected - j] = true;
                }
                if(selected + j < MAX_WEIGHT){
                    DP[i][selected + j] = true;
                }
            }
        }
    }
}

void printAns(){
    for(int i = 0; i < TC; i++){
        int num = TC_ARR[i];
        bool canWeight = num >= MAX_WEIGHT ? false : DP[N - 1][num];
        cout << (canWeight ? "Y " : "N ");
    }
}

int main(){
    input();
    makeDP();
    printAns();
}