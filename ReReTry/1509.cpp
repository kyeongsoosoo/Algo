#include <iostream>
#define MAX 2501
#define INF 987654321

using namespace std;

string S;
int max_size;
char arr[MAX];
bool palin[MAX][MAX];
int palin_set[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S;

    max_size = S.size();

    for(int i = 0; i < S.size(); i++){
        arr[i] = S[i];
    }

    for(int i = 1; i < MAX; i++){
        palin[i][i] = true;

        if(i < max_size){
            if(S[i - 1] == S[i]){
                palin[i][i + 1] = true;
            }
        }
    }

    for(int i = 1; i < MAX; i++){
        palin_set[i] = INF;
    }
}

void findPalin(){
    for(int len = 3; len <= max_size; len++){
        for(int start = 1; start <= max_size - len + 1; start++){
            int end = start + len - 1;
            if(palin[start + 1][end - 1] && S[start - 1] == S[end - 1]){
                palin[start][end] = true;
            }
        }
    }
}

void findPalinSet(){
    for(int i =1; i <= max_size; i++){
        for(int j = 1; j <= i; j++){
            if(palin[j][i]){
                palin_set[i] = min(palin_set[i], palin_set[j - 1] + 1);
                // cout << j << " " << i << " idx: " << palin_set[i] << '\n';
            }
        }
    }
}

int main(){
    input();
    findPalin();
    findPalinSet();

    cout << palin_set[max_size];
}