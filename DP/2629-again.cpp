#include <iostream>
#define P_MAX 31
#define BID_MAX 7
#define BID_LIMIT 15001

using namespace std;

int P_N;
int P[P_MAX];

int BID_N;
int BID[BID_MAX];

bool DP[P_MAX][BID_LIMIT];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> P_N;

    for(int i = 0; i < P_N; i++){
        cin >> P[i];
    }

    cin >> BID_N;

    for(int i = 0; i < BID_N; i++){
        cin >> BID[i];
    }
}

void makeDP(){
    int first_p_weight = P[0];

    DP[0][first_p_weight] = true;
    DP[0][0] = true;

    for(int p_idx = 1; p_idx < P_N; p_idx++){
        int p_weight = P[p_idx];
        DP[p_idx][p_weight] = true;

        for(int weight = 0; weight <= BID_LIMIT; weight ++){
            if(DP[p_idx - 1][weight]) DP[p_idx][weight] = true;
            else continue;
            
            int abs_diff = abs(weight - p_weight);

            if(abs_diff >= BID_LIMIT || (weight + p_weight) >= BID_LIMIT) continue;

            DP[p_idx][abs_diff] = true;
            DP[p_idx][weight + p_weight] = true;
        }
    }
}

void printAns(){
    for(int i = 0; i < BID_N; i++){
        int target = BID[i];

        if(DP[P_N - 1][target])
            cout << "Y ";
        else
            cout << "N ";
    }
}

int main(){
    input();
    makeDP();

    printAns();
}