#include <iostream>
#include <vector>
#include <cstring>
#define N_MAX 2001
#define M_MAX 1000001

using namespace std;

int N, M;
int arr[N_MAX];
vector<pair<int, int>> query;
int palin[N_MAX][N_MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    cin >> M;

    for(int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;
        query.push_back(make_pair(start, end));
    }

    memset(palin, -1, sizeof(palin));

    for(int i = 1; i <= N; i++){
        palin[i][i] = 1;
    }

    for(int i = 1; i <= N - 1; i++){
        if(arr[i] == arr[i + 1]){
            palin[i][i + 1] = 1;
        }
    }
}

void checkPalin(){
    for(int len = 2; len < N; len++){
        for(int start = 1; start <= N - len; start++){
            int end = start + len;
            if((arr[start] == arr[end]) && (palin[start + 1][end - 1] == 1)){
                palin[start][end] = 1;
            }
        }
    }
}

void printAns(){
    for(int i = 0; i < query.size(); i++){
        pair<int, int> q = query[i];
        int start = q.first;
        int end = q.second;

        if(palin[start][end] == 1) cout << "1\n";
        else cout << "0\n";
    }
    // for(int i = 1; i <= N; i++){
    //     for(int j = i; j <= N; j++){
    //         cout << palin[i][j] <<'\n';
    //     }
    // }
}

int main(){
    input();
    checkPalin();
    printAns();
}