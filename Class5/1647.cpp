#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int N, M, ans;
int Parent[MAX];
vector< pair<int, pair<int, int>>> Edge;
vector<int> V;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Edge.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(Edge.begin(), Edge.end());
}

int find_P(int idx){
    if(idx == Parent[idx]) return idx;
    else return Parent[idx] = find_P(Parent[idx]);
}

void merge(int idx1, int idx2){
    idx1 = find_P(idx1);
    idx2 = find_P(idx2);

    if(idx1 == idx2) return;
    Parent[idx2] = idx1;
    N--;
}

void solution(){
    for(int i = 1; i <= N; i++) Parent[i] = i;

    for(int i = 0; i < Edge.size(); i++){
        int idx1 = Edge[i].second.first;
        int idx2 = Edge[i].second.second;

        if(find_P(idx1) == find_P(idx2) == false){
            merge(idx1, idx2);
            V.push_back(Edge[i].first);
        }
    }

    for(int i = 0; i < V.size() - 1; i++){
        ans += V[i];
    }

    cout << ans;
}

int main(){
    input();
    solution();
}