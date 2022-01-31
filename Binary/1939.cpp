#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 100001

using namespace std;

int N, M, Max_cost, start, fac_end;
bool visit[MAX];
vector<pair<int, int> > V[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int pos1, pos2, cost;
        cin >> pos1 >> pos2 >> cost;
        V[pos1].push_back(make_pair(pos2, cost));
        V[pos2].push_back(make_pair(pos1, cost));

        Max_cost = max(Max_cost, cost);
    }

    cin >> start >> fac_end;
}

bool BFS(int cur_cost){
    queue<int> Q;
    Q.push(start);
    visit[start] = true;

    while(Q.empty() == 0){
        int cur_fac = Q.front();
        Q.pop();

        if(cur_fac == fac_end) return true;

        for(int i = 0; i < V[cur_fac].size(); i++){
            int next_fac = V[cur_fac][i].first;
            int next_fac_cost = V[cur_fac][i].second;

            if(visit[next_fac] == false && cur_cost <= next_fac_cost){
                visit[next_fac] = true;
                Q.push(next_fac);            
            }
        }
    }
    return false;
}

void findAns(){
    int low = 0;
    int high = Max_cost;
    while(low <= high){
        memset(visit, false, sizeof(visit));
        int mid = (low + high) / 2;
        if(BFS(mid) == true) low = mid + 1;
        else high = mid - 1;
    }
    cout << high << '\n';
}

int main(){
    input();
    findAns();
}