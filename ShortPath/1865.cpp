#include <iostream>
#include <vector>
#include <cstring>
#define INF 987654321
#define V_MAX 510
#define E_MAX 2501
#define W_MAX 201

using namespace std;

int T;
int N, M, W;
vector<pair<int, pair<int, int>>> Edges;
int map[V_MAX];

int checkNode(int idx, int end_idx){
    for(int i = 0; i < Edges.size(); i++){
        if((Edges[i].first == idx) && (Edges[i].second.first == end_idx)) return idx;
    }
    return -1;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

}

void caseInput(){
    cin >> N >> M >> W;
    Edges.clear();
    
    for(int i = 0; i < V_MAX; i++){
        map[i] = INF;
    }
    memset(map, -1, sizeof(map));

    for(int i = 0; i < M; i++){
        int start, end, cost;

        cin >> start >> end >> cost;
        Edges.push_back({start, {end, cost}});
        Edges.push_back({end, {start, cost}});
        // int startCheck = checkNode(start, end);
        // int endCheck = checkNode(end, start);
        // if(startCheck == -1){
        //     Edges.push_back({start, {end, cost}});
        // }
        // else{
        //     Edges[startCheck] = {start, {end, cost}};
        // }
        // if(endCheck == -1){
        //     Edges.push_back({end, {start, cost}});
        // }
        // else{
        //     Edges[endCheck] = {end, {start, cost}};
        // }
    }

    for(int i = 0; i < W; i++){
        int start, end, cost;

        cin >> start >> end >> cost;
        Edges.push_back({start, {end, -cost}});
        // int startCheck = checkNode(start, end);

        // // cout << "startCheck: " << startCheck << '\n';
        // if(startCheck == -1){
        //     Edges.push_back({start, {end, -cost}});
        // }
        // else{
        //     Edges[startCheck] = {start, {end, -cost}};
        // }
    }
}

void calcBell(){

    map[1] = 0;

    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < Edges.size(); j++){
            pair<int, pair<int, int>> P = Edges[j];
            int start = P.first;
            int end = P.second.first;
            int cost = P.second.second;
            // cout << "start: " << start << " end: " << end << " cost: " << cost << '\n';

            if(map[start] != INF && map[end] > map[start] + cost){
                map[end] = map[start] + cost;
                // cout << "end " <<  map[end] << '\n';
                // cout << "size " <<  Edges.size() << '\n';
            }
        }
    }
}

bool checkNegativeCycle(){
        for(int j = 0; j < Edges.size(); j++){
            pair<int, pair<int, int>> P = Edges[j];
            int start = P.first;
            int end = P.second.first;
            int cost = P.second.second;

            if(map[start] != INF && map[end] > map[start] + cost){
                return true;
            }
        }
        return false;
}



int main(){
    input();
    while(T--){
        caseInput();
        calcBell();
        bool hasNegativeCycle = checkNegativeCycle();

        cout << (hasNegativeCycle ? "YES" : "NO") << '\n';
    }
}