#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 10001

using namespace std;

int UNSELECTED = 0;
int SELECTED = 1;

int n;
vector<int> Edges[MAX];
int weight[MAX];

bool visited[MAX][2];
bool path_visited[MAX];
vector<int> Path;
int DP[MAX][2];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> weight[i];
    }

    for(int i = 0; i < n - 1; i++){
        int start, to;
        cin >> start >> to;

        Edges[start].push_back(to);
        Edges[to].push_back(start);
    }
}

int makeDFS(int idx, int type){
    visited[idx][type] = true;

    if(DP[idx][type]) return DP[idx][type];

    DP[idx][SELECTED] = weight[idx];

    for(int i = 0; i < Edges[idx].size(); i++){
        int child_idx = Edges[idx][i];

        if(visited[child_idx][type]) continue;

        int child_unselected = makeDFS(child_idx, UNSELECTED);
        int child_selected = makeDFS(child_idx, SELECTED);
        int child_max = max(child_selected, child_unselected );

        DP[idx][UNSELECTED] += child_max;
        DP[idx][SELECTED] += child_unselected;
    }

    return DP[idx][type];
}

void track(int now, int prev){
    if(DP[now][SELECTED] > DP[now][UNSELECTED] && !path_visited[prev]){
        Path.push_back(now);
        path_visited[now] = true;
    }

    for(int i = 0; i < Edges[now].size(); i++){
        int next = Edges[now][i];
        if(next == prev) continue;
        track(next, now);
    }
}

void makeAns(){
    int UnselectedRoot = makeDFS(1, UNSELECTED);
    int SelectedRoot = makeDFS(1, SELECTED);

    int max_root = max(UnselectedRoot, SelectedRoot);

    track(1, 0);

    sort(Path.begin(), Path.end());

    cout << max_root << '\n';
    for(auto &w: Path){
        cout << w << " ";
    }

}

int main(){
    input();
    makeAns();
}