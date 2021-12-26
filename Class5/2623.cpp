#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define PD_MAX 101

using namespace std;

int N, M;
int incoming[MAX];
vector<int> edges[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int line_num;
    for(int i = 0; i < M; i++){
        cin >> line_num;

        int tmp1 = 0, tmp2 = 0;

        for(int j = 0; j < line_num; j++){
            tmp1 = tmp2;

            cin >> tmp2;

            if(tmp1 != 0){
                edges[tmp1].push_back(tmp2);
                incoming[tmp2]++;
            }
        }
    }
}

void topologySort(){
    queue<int> Q;
    vector<int> ans;

    for(int i = 1; i <= N; i++){
        if(incoming[i] == 0){
            Q.push(i);
        }
    }

    if(Q.empty()){
        cout << 0;
        return;
    }

    while(!Q.empty()){
        int idx = Q.front(); Q.pop();
        ans.push_back(idx);

        for(int j = 0; j < edges[idx].size(); j++){
            int next_node = edges[idx][j];
            incoming[next_node]--;
            if(incoming[next_node] == 0){
                Q.push(next_node);
                incoming[next_node] = -1;
            }
        }
    }

    if(ans.size() != N){
        cout << 0;
        return;
    }
    else{
        for(int i = 0 ; i < ans.size(); i++){
            cout << ans[i] << '\n';
        }
    }
}

int main(){
    input();
    topologySort();
}