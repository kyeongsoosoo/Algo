#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1001

using namespace std;

int T;
int N;
int arr[MAX];
int DP[MAX][MAX][2];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

void caseInput(){
    memset(arr, 0, sizeof(arr));

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    memset(DP, -1, sizeof(DP));
}

int findDP(int start, int end, int flag){
    int &ret = DP[start][end][flag];
    if(ret != -1) return ret;
    if(start >= end){
        if(!flag) return ret = arr[start];
        else return 0;
    }

    if(!flag){
        return ret = max(findDP(start + 1, end, !flag) + arr[start], findDP(start, end - 1, !flag) + arr[end]);
    }
    else{
        return ret = min(findDP(start + 1, end, !flag), findDP(start, end - 1, !flag));
    }
}

int main(){
    input();

    while(T--){
        caseInput();
        cout << findDP(0, N - 1, 0) << '\n';
    }
}