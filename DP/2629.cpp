#include <iostream>
#define LIMIT 15001

using namespace std;

int pendulum_num;
int *wegiht_arr;
int bid_num;
int *bid_weight_arr;
bool DP[31][LIMIT];


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> pendulum_num;

    wegiht_arr = new int[pendulum_num];

    for(int i = 0; i < pendulum_num; i++){
        cin >> wegiht_arr[i];
    }

    DP[0][0] = true;

    cin >> bid_num;

    bid_weight_arr = new int[bid_num];

    for(int i = 0; i < bid_num; i++){
        cin >> bid_weight_arr[i];
        
    }

    
}

void checkPossiblePoint(int idx){
    int val = wegiht_arr[idx - 1];

    for(int j = 0; j < LIMIT; j++){
        if(DP[idx-1][j] == true){
            DP[idx][j] = true;
            if(j - val >= 0){
                DP[idx][j - val] = true;
            }
            if(val - j >= 0){
                DP[idx][val - j] = true;
            }
            if(j + val < LIMIT){
                DP[idx][j + val] = true;
            }
        }

    }
}

void calcDP(){
    for(int i = 1; i <= pendulum_num; i++){
        checkPossiblePoint(i);
    }
}

void printAns(){
    for(int i = 0; i < bid_num; i++){
        int weight = bid_weight_arr[i];
        if( weight > LIMIT){
            cout << "N ";
            continue;
        }

        if(DP[pendulum_num][weight])
            cout << "Y ";
        else
            cout << "N ";
    }
}


int main(){
    input();

    calcDP();

    printAns();

    return 0;
}