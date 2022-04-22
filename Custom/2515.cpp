#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 300010

using namespace std;
using P = pair<int, int>;

int N, S;
vector<P> V;
int DP[MAX];

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> S;

    for(int i = 0; i < N; i++){
        int h, p;
        cin >> h >> p;
        V.push_back(make_pair(h, p));
    }

}

int find_lower(int idx){
    int target = V[idx].first;

    int start = 0;
    int end = idx - 1;

    while(start <= end){
        int mid = (start + end) / 2;

        if(V[mid].first + S <= target){
            start = mid + 1;
            continue;
        }

        end = mid - 1;
    }

    return end;
}

void solve(){
    sort(V.begin(), V.end());

    DP[0] = V[0].second;


    for(int i = 1; i < N; i++){
        // cout << DP[i] << '\n';
        int idx = find_lower(i);

        //첫 그림 + S 보다 높이 올라가지 못한 경우
        if(idx == -1){
            DP[i] = max(DP[i - 1], V[i].second);
            continue;
        }

        DP[i] = max(DP[i - 1], DP[idx] + V[i].second);
    }

    cout << DP[N - 1];
}

int main(){
    input();
    solve();
}