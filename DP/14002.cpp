#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int N;
int arr[MAX];
int DP[MAX];
int PAR[MAX];
vector<int> TMP;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        PAR[i] = i;
    }
}

void makeDP(){
    for(int i = 0; i < N; i++){
        DP[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                DP[i] = max(DP[i], DP[j] + 1);
                if(DP[i] == DP[j] + 1){
                    PAR[i] = j;
                }
            }
        }
    }
}

void printAns(){
    int max_val = -1;
    int max_idx = -1;

    for(int i = 0; i < N; i++){
        int cur_val = DP[i];
        if(DP[i] > max_val){
            max_val = cur_val;
            max_idx = i;
        }
    }

    cout << max_val << '\n';

    while(PAR[max_idx] != max_idx){
        TMP.push_back(max_idx);
        max_idx = PAR[max_idx];
    }
    TMP.push_back(max_idx);

    for(int i = TMP.size() - 1; i >= 0; i--){
        cout << arr[TMP[i]] << " ";
    }
}

int main(){
    input();
    makeDP();

    printAns();
}