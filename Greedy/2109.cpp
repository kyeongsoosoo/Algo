#include <iostream>
#include <queue>
#define MAX 10001

using namespace std;

struct Pair{
    int pay;
    int due;

    Pair(int p, int d): pay(p), due(d) {}

    bool operator<(const Pair p) const {
        if(this->pay == p.pay)
            return this->due > p.due;
        return this->pay < p.pay;
    }
};

int n;
int arr[MAX];
priority_queue<Pair> pairs;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int p, d;

    for(int i =0; i < n; i++){
        cin >> p >> d;
        pairs.push({p, d});
    }

    for(int i = 1; i <= MAX; i++){
        arr[i] = i;
    }
}

int find(int idx){
    if(arr[idx] == idx) return idx;
    else return arr[idx] = find(arr[idx]);
}

void merge(int idx1, int idx2){
    int root1 = find(idx1);
    int root2 = find(idx2);

    if(root1 == root2) return;

    if(root1 < root2) arr[root2] = root1;
    else arr[root1] = root2;
}

int makeGreedy(){
    int sum = 0;

    while(!pairs.empty()){
        Pair P = pairs.top(); pairs.pop();

        int pay = P.pay;
        int due = P.due;

        int root_due = find(due);

        if(root_due == 0) continue;

        sum += pay;
        merge(root_due, root_due - 1);
    }

    return sum;
}

int main(){
    input();
    int result = makeGreedy();
    cout << result;
}