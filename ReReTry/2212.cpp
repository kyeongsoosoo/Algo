#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001

using namespace std;

int N, K;
vector<int> censor;
priority_queue<int> PQ;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        censor.push_back(tmp);
    }

    sort(censor.begin(), censor.end());

    for(int i = 1; i < censor.size(); i++){
        PQ.push(censor[i] - censor[i - 1]);
    }
}

int findMin(){
    int totalMinus = 0;

    if(K >= N) return 0;

    for(int i = 0; i < K - 1; i++){
        int maxLong = PQ.top(); PQ.pop();
        totalMinus += maxLong;
        // cout << "maxLong: " << maxLong << " total: " << totalMinus << '\n';
    }

    return censor[censor.size() - 1] - censor[0] - totalMinus;
}

int main(){
    input();
    cout << findMin();
}