#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 101
#define INF 987654321

using namespace std;

int N, M;
int map[MAX][MAX];
bool visit[MAX];
vector<int> ans;


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i < MAX; i++){
        for(int j = 1; j < MAX; j++){
            if(i == j) continue;
            map[i][j] = INF;
        }
    }

    cin >> N;
    cin >> M;

    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        map[s][e] = 1;
        map[e][s] = 1;
    }
}

void floyd(vector<int> group){
    int size = group.size();
    if(size == 1){
        ans.push_back(group[0]);
        return;
    }
    int tmp[MAX][MAX];

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == j) tmp[i][j] = 0;
            else if(map[group[i]][group[j]] == 1) tmp[i][j] = 1;
            else tmp[i][j] = INF;
        }
    }

    for(int mid = 0; mid < size; mid++){
        for(int start = 0; start < size; start++){
            for(int end = 0; end < size; end++){
                if(start == end) continue;

                int SM = tmp[start][mid];
                int ME = tmp[mid][end];

                if(tmp[start][end] > SM + ME){
                    tmp[start][end] = SM + ME;
                }
            }
        }
    }

    int leader;
    int leaderCost = INF;

    for(int i = 0; i < size; i++){
        int cost = 0;
        for(int j = 0; j < size; j++){
            cost = max(cost, tmp[i][j]);
        }
        if(cost < leaderCost){
            leaderCost = cost;
            leader = group[i];
        }
    }
    ans.push_back(leader);
}

void makeBFS(int idx){
    vector<int> group;
    queue<int> q;
    q.push(idx);
    visit[idx] = true;

    while(!q.empty()){
        idx = q.front(); q.pop();
        group.push_back(idx);
        for(int i = 1; i <= N; i++){
            if(visit[i] == true || map[i][idx] == INF) continue;
            q.push(i);
            visit[i] = true;
        }
    }
    floyd(group);
}

void makeAns(){
    for(int i = 1; i <= N; i++){
        if(!visit[i])
            makeBFS(i);
    }

    sort(ans.begin(), ans.end());
}

void printAns(){
    cout << ans.size() << '\n';

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
}

int main(){
    input();
    makeAns();
    printAns();
}