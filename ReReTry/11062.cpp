#include <iostream>
#include <cstring>
#include <vector>
#define MAX 1001


using namespace std;

int TC;
int N;
vector<int> cards;
int DP[MAX][MAX][2];

const bool TURN_K = false;
const bool TURN_M = true;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
}

void caseInput(){
    cards.clear();
    memset(DP, 0, sizeof(DP));

    cin >> N;

    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        cards.push_back(tmp);
    }
}

int makeDP(bool turn, int left, int right){
    if(left == right){
        if(turn == TURN_K) return cards[left];
        return 0;
    }

    if(DP[left][right][turn]) return DP[left][right][turn];

    if(turn == TURN_K){
        DP[left][right][turn] = max(makeDP(!turn, left + 1, right) + cards[left], makeDP(!turn, left, right - 1) + cards[right]);
    }
    else{
        DP[left][right][turn] = min(makeDP(!turn, left + 1, right), makeDP(!turn, left, right - 1));
    }

    return DP[left][right][turn];
    
}

int main(){
    input();
    while(TC--){
        caseInput();
        cout << makeDP(TURN_K, 0, N - 1) << '\n';   
    }
}