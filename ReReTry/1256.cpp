#include <iostream>
#define MAX 101
#define LIMIT 1000000007

using namespace std;

int N, M, K;
long long dict[MAX][MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
}

void makeDP(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(i == 0 || j == 0){
                dict[i][j] = 1;
                continue;
            }
            dict[i][j] = dict[i - 1][j] + dict[i][j - 1];
            if(dict[i][j] > LIMIT) dict[i][j] = LIMIT;
        }
    }
}

void findMatchString(long long idx, int rest_a, int rest_z, int len){
    // cout << "idx : " << idx << " a: " << rest_a << " z: " << rest_z << '\n';
    if(len == 0) return;
    if(rest_a == 0){
        // cout << 1 << '\n';
        cout << 'z';
        findMatchString(idx, rest_a, rest_z - 1, len - 1);
    }
    else if(rest_z == 0){
        // cout << 2 << '\n';
        cout << 'a';
        findMatchString(idx, rest_a - 1, rest_z, len - 1);
    }
    // cout << "used: " << a_used << '\n';
    else if(idx > dict[rest_a - 1][rest_z]){
        // cout << 3 << '\n';
        cout << 'z';
        findMatchString(idx - dict[rest_a - 1][rest_z], rest_a, rest_z - 1, len - 1);
    }
    else{
        // cout << 4 << '\n';
        cout << 'a';
        findMatchString(idx, rest_a - 1, rest_z, len - 1);
    }
}

int main(){
    input();
    makeDP();

    if(K > dict[N][M]){
        cout << -1;
        return 0;
    }
    findMatchString((long long)K, N, M, N + M);
}