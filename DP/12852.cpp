#include <iostream>
#include <algorithm>
#define MAX 1000001
#define INF 987654321

using namespace std;

int N;
int DP[MAX];
int PAR[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    DP[0] = INF;
}

void makeDP(){
    for(int i = 2; i <= N; i++){
        int three = 0;
        int second = 0;
        int minus = i - 1;

        if(i % 3 == 0)
            three = i / 3;
        if(i % 2 == 0)
            second = i / 2;

        int min_val = min(DP[three], min(DP[second], DP[minus]));

        DP[i] = min_val + 1;

        int min_idx = 
            min_val == DP[three] 
                ? three
                : min_val == DP[second]
                    ? second
                    : minus;
        PAR[i] = min_idx;
    }
}

void printOrder(){
    int cur_idx = N;
    while(PAR[cur_idx] != 0){
        cout << cur_idx << " ";
        cur_idx = PAR[cur_idx];
    }

    cout << "1";
}

void printAns(){
    cout << DP[N] << '\n';

    printOrder();
}


int main(){
    input();
    makeDP();

    printAns();
}