#include <iostream>

using namespace std;

int N;
int* arr;
int M;
int S,E;
bool DP[2001][2001];

void input(){
    cin >> N;
    arr = new int[N+1];

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    cin >> M;
}

void calcPalin(){
    for(int i = 1; i <= N; i++){
        DP[i][i] = true;
    }

    for(int i = 1; i < N; i++){
        if(arr[i] == arr[i+1])
            DP[i][i+1] = true;
    }

    for(int palinLeng = 2; palinLeng < N; palinLeng++){
        for(int start = 1; start <= N - palinLeng; start++){
            if(DP[start+1][start + palinLeng - 1] && arr[start] == arr[start + palinLeng]){
                DP[start][start+palinLeng] = true;
            }
        }
    }
}

void ans(){
    int S,E;

    for(int start = 0; start < M; start++){

        cin >> S >> E;

        cout << DP[S][E] << '\n';

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();

    calcPalin();

    ans();

    return 0;
}