#include <iostream>
#define APP_LIMIT 101
#define COST_TOTAL_LIMIT 10001

using namespace std;

int N,M;
int memory[APP_LIMIT];
int cost[APP_LIMIT];
int DP[COST_TOTAL_LIMIT];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> memory[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> cost[i];
    }
}

void makeDP(){
    for(int level = 1; level <= N; level++){

        int cur_cost = cost[level];

        for(int c = COST_TOTAL_LIMIT - 1; c >= cur_cost; c--){
             DP[c] = max(DP[c], DP[c - cur_cost] + memory[level]);
        }
    }
}

int main(){
    input();

    makeDP();

    int c = 1;
    while(c++ < COST_TOTAL_LIMIT){
            if(DP[c] >= M){
                cout << c << '\n';
                break;
            }
    }
}