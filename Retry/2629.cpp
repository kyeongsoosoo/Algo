#include <iostream>
#define CH_MAX 31
#define BID_MAX 8
#define W_MAX 15001

using namespace std;

int CH_NUM;
int CHS[CH_MAX];
int BID_NUM;
int BIDS[BID_MAX];
int DP[CH_MAX][W_MAX];


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> CH_NUM;
    for(int i = 0; i < CH_NUM; i++){
        cin >> CHS[i];
    }

    cin >> BID_NUM;
    for(int i = 0; i < BID_NUM; i++){
        cin >> BIDS[i];
    }

    int first = CHS[0];
    DP[0][first] = 1;

    for(int i = 0; i < CH_NUM; i++){
        DP[i][0] = 1;
    }
}

void makeDP(){
    for(int i = 1; i < CH_NUM; i++){
        int selected = CHS[i];

        for(int j = 0; j < W_MAX; j++){
            if(!DP[i - 1][j]) continue;

            DP[i][j] = 1;

            if(j - selected > 0) DP[i][j - selected] = 1;
            if(selected - j > 0) DP[i][selected - j] = 1;
            DP[i][selected + j] = 1;
        }
    }
}

void printAns(){
    for(int i = 0; i < BID_NUM; i++){
        int selected = BIDS[i];


        if(selected >= W_MAX) cout << "N ";
        else if(DP[CH_NUM - 1][selected]) cout << "Y ";
        else cout << "N ";
    }
}

int main(){
    input();
    makeDP();
    printAns();
}