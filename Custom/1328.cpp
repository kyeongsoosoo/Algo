#include <iostream>
#include <cstring>

#define MAX 110
#define DIVIDER 1000000007

using namespace std;

int N, L, R;
long long DP[MAX][MAX][MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R;

    memset(DP, -1, sizeof(DP));
}

long long find(int N, int L, int R){
    if(L == 0 || R == 0 || N == 0) return DP[N][L][R] = 0;
    if(N != 1 && N == L && N == R) return DP[N][L][R] = 0;
    if((N == L && R == 1) || (N == R && L == 1)) return DP[N][L][R] = 1;
    if(DP[N][L][R] != -1) return DP[N][L][R];

    DP[N][L][R] = (find(N - 1, L - 1, R) + find(N - 1, L, R - 1) + (N - 2) * find(N - 1, L, R)) % DIVIDER;

    return DP[N][L][R];
}

int main(){
    input();
    long long ans = find(N, L, R);
    cout << ans;
}