#include <iostream>
#include <cstring>
#define MAX 1001

using namespace std;

int TC;
int N;
int* arr;
int DP[MAX][MAX][2];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
}

void caseInput(){
    arr = new int[MAX];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    memset(DP, -1, sizeof(DP));
}

int solve(int start, int end, int flag){
    int &ret = DP[start][end][flag];
    if(ret != -1) return ret;
    if(start >= end){
        if(!flag) return ret = arr[start];
        else return 0;
    }

    if(!flag){
        return ret = max(solve(start + 1, end, !flag) + arr[start], solve(start, end - 1, !flag) + arr[end]);
    }
    else{
        return ret = min(solve(start + 1, end, !flag), solve(start, end - 1, !flag));
    }
}

int main(){
    input();

    while(TC--){
        caseInput();
        cout << solve(0, N - 1, 0) << '\n';
    }
}