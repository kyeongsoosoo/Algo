#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int N;
int sum = 0;
priority_queue<int, vector<int>, greater<int>> PQ;

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

void greedySum(){
    while(PQ.size() != 1){
        int first = PQ.top(); PQ.pop();
        int second = PQ.top(); PQ.pop();

        int tmpSum = first + second;
        sum += tmpSum;

        PQ.push(tmpSum);
    }
}

int main(){
    input();
    greedySum();
    cout << sum;
}