#include <iostream>
#include <cmath>

#define LIMIT 400
#define MAX 100010
#define INF 987654321

using namespace std;

int N;
int DP[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

void make_dp(){
    DP[1] = 1;

    for(int i = 2; i < MAX; i++){
        DP[i] = INF;
        for(int j = 1; j <= (int)(sqrt(i)); j++){
            // cout << "i: " << i << " j: " << j << '\n';
            DP[i] = min(DP[i], DP[i - (j * j)] + 1);
        }
    }
}

int main(){
    input();
    make_dp();
    cout << DP[N];
}