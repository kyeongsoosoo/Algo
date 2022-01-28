#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int, int> b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

int TC;
int N, M;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> PQ;
int map[MAX];
int ans_count = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
}

void caseInput(){
    while(!PQ.empty()) PQ.pop();

    for(int i = 0; i < MAX; i++){
        map[i] = i;
    }
    ans_count = 0;

    cin >> N;
    cin >> M;

    for(int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;
        PQ.push(make_pair(start, end));
    }
}

int find(int idx){
    if(map[idx] == idx) return idx;
    return map[idx] = find(map[idx]);
}

bool merge(int idx1, int idx2){
    int root1 = find(idx1);
    int root2 = find(idx2);

    if(root1 == root2) return false;

    if(root1 < root2) map[root2] = root1;
    else map[root1] = root2;

    return true;
}

void countBook(){
    while(!PQ.empty()){
        pair<int, int> range = PQ.top(); PQ.pop();

        int avail = find(range.second);

        if(avail > 0 && avail >= range.first){
            ans_count += 1;
            merge(avail, avail - 1);
        }
    }
}


int main(){
    input();
    while(TC--){
        caseInput();
        countBook();

        cout << ans_count << '\n';
    }
}