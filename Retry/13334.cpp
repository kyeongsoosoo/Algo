#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000001

using namespace std;
typedef pair<int, int> P;

struct sortByLessEnd{
    bool operator()(P a1, P a2){
        if(a1.second > a2.second) return true;
        return false;
    }
};

struct sortByLessFirst{
    bool operator()(P a1, P a2){
        if(a1.first > a2.first) return true;
        return false;
    }
};

int N;
int D;
priority_queue<P, vector<P>, sortByLessEnd> PQ;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        int a1, a2;
        cin >> a1 >> a2;
        if(a2 < a1) swap(a1, a2);
        PQ.push(make_pair(a1, a2));
    }

    cin >> D;
}

void solve(){
    priority_queue<P, vector<P>, sortByLessFirst> PQ2;
    int size = 0;
    int start = -MAX;
    int end = -MAX;

    while(!PQ.empty()){
        P pair_elem = PQ.top(); PQ.pop();
        int elem_start = pair_elem.first;
        int elem_end = pair_elem.second;
        int len = elem_end - elem_start;

        if(len > D) continue;
        if(elem_end == -MAX){
            start = elem_start;
            end = elem_end;
            size += 1;
            PQ2.push(pair_elem);
            continue;
        }

        PQ2.push(pair_elem);
        end = elem_end;
        start = min(start, elem_start);

        while(!PQ2.empty()){
            P pair2_elem = PQ2.top();

            if(end - pair2_elem.first <= D){
                start = pair2_elem.first;
                break;
            }
            else{
                PQ2.pop();
            }
        }

        int tmp_size = PQ2.size();

        size = max(size, tmp_size);
    }

    cout << size;
}

int main(){
    input();
    solve();
}