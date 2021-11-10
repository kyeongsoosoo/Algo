#include <iostream>
#include <cstring>
#define MAX 1005

using namespace std;

typedef pair<int, int> p;

int T;
int N;

int DP[MAX][MAX][2];

int cost[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

void caseInput(){
    memset(DP, -1, sizeof(DP));
    cin >> N;

    for(int i = 1; i <= N; i++) cin >> cost[i];
}

int makeDFS(int start, int end, int flag){
    int &cur = DP[start][end][flag];
    if(cur != -1) return cur;

    if(start >= end){
        if(!flag) return cur = cost[start];
        else return cur = 0;
    }

    if(!flag){
        return cur = max(makeDFS(start + 1, end, !flag) + cost[start], makeDFS(start, end - 1, !flag) + cost[end]);
    }
    else{
        return cur = min(makeDFS(start + 1, end, !flag), makeDFS(start, end - 1, !flag));
    }
}

int main(){
    input();
    while(T--){
        caseInput();
        int result = makeDFS(1, N, 0);
        cout << result << '\n';
    }
}