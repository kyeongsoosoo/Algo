#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

struct Assign{
    int due;
    int score;

    Assign(int d, int s): due(d), score(s){}

    bool operator<(const Assign a) const {
        if(this->score == a.score)
            return this->due > a.due;
        return this->score < a.score;
    }
};

int N;
int arr[MAX];
priority_queue<Assign> assigns;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int d,w;

    for(int i = 0; i < N; i++){
        cin >> d >> w;
        assigns.push({d, w});
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

    while(!assigns.empty()){
        Assign task = assigns.top(); assigns.pop();
        int due = task.due;
        int score = task.score;

        int root_due = find(due);

        if(root_due == 0) continue;

        merge(root_due, root_due - 1);
        sum += score;
    }
    return sum;
}

int main(){
    input();
    int result = makeGreedy();

    cout << result;
}