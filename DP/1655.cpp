#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int> > maxQ;
priority_queue<int, vector<int>, greater<int> > minQ;

int N;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

bool isBalanced(){
    int maxTop = maxQ.top();
    int minTop = minQ.top();

    if(maxTop <= minTop){
        return true;
    }
    else
        return false;
}

void swapQ(){
    int maxTop = maxQ.top();
    int minTop = minQ.top();

    maxQ.pop();
    minQ.pop();

    maxQ.push(minTop);
    minQ.push(maxTop);
}

void makeAns(){
    for(int i = 0; i < N; i++){
        int elem;
        int maxQSize = maxQ.size();
        int minQSize = minQ.size();

        cin >> elem;

        if(maxQSize == minQSize)
            maxQ.push(elem);
        else
            minQ.push(elem);

        if(maxQ.size() != 0 && minQ.size() != 0 && maxQ.top() > minQ.top())
            swapQ();

        cout << maxQ.top() << '\n';
    }
}


int main(){
    input();

    makeAns();

    return 0;
}