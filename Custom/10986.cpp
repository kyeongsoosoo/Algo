#include <iostream>

#define LIMIT 1005
#define MAX 1000005

using namespace std;

int N, M;
long long rest[LIMIT];
int arr[MAX];
long long ans_count = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void solve(){
    long long sum = 0;

    for(int i = 0; i < N; i++){
        sum += arr[i];

        int r = sum % M;

        ans_count += rest[r];
        if(r == 0) ans_count += 1;

        rest[r] += 1;

        // cout << sum << " " << rest[r] << " " << " " << r <<  '\n';
    }

    cout << ans_count;
}

int main(){
    input();
    solve();
}