#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define V_MAX 2010
#define E_MAX 50005
#define INF 987654321

using namespace std;

int TC;
int N, M, T;
int S, G, H;
int A, B, D;
int mid_len;

vector<pair<int, int>> edges[V_MAX];
vector<int> candi;
vector<int> ans;

int diTotal[V_MAX];
int diG[V_MAX];
int diH[V_MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
}

void caseInput(){
    for(int i = 0; i < V_MAX; i++){
        edges[i].clear();
        diTotal[i] = INF;
        diG[i] = INF;
        diH[i] = INF;
    }
    candi.clear();
    ans.clear();

    cin >> N >> M >> T;
    cin >> S >> G >> H;

    int start, end, cost;
    for(int i = 0; i < M; i++){
        cin >> start >> end >> cost;
        edges[start].push_back({cost, end});
        edges[end].push_back({cost, start});

        if((start == G && end == H) || (end == G && start == H)){
            mid_len = cost;
        }
    }

    for(int i = 0; i < T; i++){
        int tmp;
        cin >> tmp;
        candi.push_back(tmp);
    }
}

void makeDi(int start_node, int* di){
    priority_queue<pair<int, int>> PQ;

    di[start_node] = 0;
    PQ.push({0, start_node});

    while(!PQ.empty()){
        pair<int, int> cur = PQ.top(); PQ.pop();
        int cur_cost = -cur.first;
        int cur_pos = cur.second;

        for(int i = 0; i < edges[cur_pos].size(); i++){
            pair<int, int> next = edges[cur_pos][i];
            int next_cost = next.first;
            int next_pos = next.second;

            if(di[next_pos] > cur_cost + next_cost){
                di[next_pos] = cur_cost + next_cost;
                PQ.push({-(cur_cost + next_cost), next_pos});
            }
        }
    }
}

bool conditionTest(int end){
    if(diTotal[end] == diG[S] + diH[end] + mid_len){
        return true;
    }
    if(diTotal[end] == diH[S] + diG[end] + mid_len){
        return true;
    }
    return false;
}

int main(){
    input();
    
    while(TC--){
        caseInput();
        makeDi(S, diTotal);
        makeDi(G, diG);
        makeDi(H, diH);

        for(int i = 0; i < T; i++){
            int tester = candi[i];
            if(conditionTest(tester)) ans.push_back(tester);
        }

        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}