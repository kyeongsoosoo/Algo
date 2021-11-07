#include <iostream>
#include <cstring>
#define MAX 100001
#define INF 987654321

using namespace std;

int N;
int maxN = -1;
int minN = INF;
int road[MAX][3];
int DP[2][3];


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i= 0; i < N; i++){
        cin >> road[i][0] >> road[i][1] >> road[i][2];
    }

    DP[0][0] = road[0][0];
    DP[0][1] = road[0][1];
    DP[0][2] = road[0][2];

}

bool checkCondition(int pre, int cur){
    int next = cur + pre;
    if(next < 0) return false;
    if(next >= 3) return false;
    return true;
}

void makeDP(){
    for(int i = 1; i < N; i++){
        DP[1][0] = 0;
        DP[1][1] = 0;
        DP[1][2] = 0;
        for(int j = 0; j <= 2; j++){
            for(int pre = -1; pre < 2; pre++){
                if(checkCondition(pre, j)){
                    DP[1][j] = max(DP[1][j], DP[0][j + pre] + road[i][j]);
                }
            }
        }
        DP[0][0] = DP[1][0];
        DP[0][1] = DP[1][1];
        DP[0][2] = DP[1][2];
    }

    for(int i = 0; i <= 2; i++){
        maxN = max(maxN, DP[0][i]);
    }


    DP[0][0] = road[0][0];
    DP[0][1] = road[0][1];
    DP[0][2] = road[0][2];


    for(int i = 1; i < N; i++){
        DP[1][0] = INF;
        DP[1][1] = INF;
        DP[1][2] = INF;
        for(int j = 0; j <= 2; j++){
            for(int pre = -1; pre < 2; pre++){
                if(checkCondition(pre, j)){
                    DP[1][j] = min(DP[1][j], DP[0][j + pre] + road[i][j]);
                    
                }
            }
        }
        DP[0][0] = DP[1][0];
        DP[0][1] = DP[1][1];
        DP[0][2] = DP[1][2];
    }

    for(int i = 0; i <= 2; i++){
        
        minN = min(minN, DP[0][i]);
    }


}

int main(){
    input();
    makeDP();

    cout << maxN << " " << minN;
}