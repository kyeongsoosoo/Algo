#include <iostream>
#include <queue>
#define MAX 200001

using namespace std;

struct Pair{
    int due;
    int val;

    Pair(int d, int v): due(d), val(v){}

    bool operator<(const Pair p) const {
        if(this->val == p.val)
            return this->due > p.due;
        return this->val < p.val;
    }
};

int N;
int arr[MAX];
priority_queue<Pair> pairs;


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int d,v;

    for(int i = 0; i < N; i++){
        cin >> d >> v;
        pairs.push({d, v});
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

        int d = P.due;
        int v = P.val;

        int root_d = find(d);

        if(root_d == 0) continue;

        sum += v;
        merge(root_d, root_d - 1);
    }

    return sum;
}

int main(){
    input();
    int ans = makeGreedy();

    cout << ans;
}