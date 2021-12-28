#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> PQ;
int ans = 0;


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        PQ.push(tmp);
    }
}

void makeGreedy(){
    while(PQ.size() != 1){
        int first = PQ.top(); PQ.pop();
        int second = PQ.top(); PQ.pop();

        int res = first + second;

        ans += res;

        PQ.push(res);
    }
}

int main(){
    input();
    makeGreedy();

    cout << ans;
}