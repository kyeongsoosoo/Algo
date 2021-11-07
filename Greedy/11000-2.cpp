#include <iostream>
#include <functional>
#include <queue>
#define MAX 200000

using namespace std;

struct Time{
    int start,to;
}

bool compare(const Time& Time1, const Time& Time2){
    return Time1.start < Time2.start;
}

priority_queue<int, vector<int>, greater<int>> pq;
int N;
vector<Time> num;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        int start, to;
        cin >> start >> to;
        num.push_back({start, to});
    }

    sort(num.begin(), num.end(), compare);
}

void greedy(){
    pq.push(num[0].to);

    for(int i = 1; i < N; i++){
        if(pq.top() <= num[i].start){
            pq.pop();
            pq.push(num[i].to);
        }
        else {
            pq.push(num[i].to);
        }
    }
}

int main(){
    input();
    greedy();
}