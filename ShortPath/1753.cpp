#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
#include <queue>
#define VMAX 20001
#define EMAX 300001
#define INF 98764321

using namespace std;

struct costTo{
    int cost;
    int to;
};
struct costStart{
    int cost;
    int start;

    costStart(int cost, int start): cost(cost), start(start){}
    
    bool operator<(const costStart s) const {
        return this->cost > s.cost;
    }
};

int V,E;
int K;
vector<costTo> Edges[VMAX];
int di[VMAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;
    cin >> K;

    int u,v,w;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        Edges[u].push_back({w, v});
    }

    memset(di, INF, sizeof(di));
}

void makeDi(){
    int start = K;
    priority_queue<costStart> PQ;

    PQ.push({0, start});
    di[K] = 0;

    while(PQ.size()){
        costStart curNode = PQ.top(); PQ.pop();
        int curCost = curNode.cost;

        for(int i = 0; i < Edges[curNode.start].size(); i++){
            costTo toNode = Edges[curNode.start][i];
            int newCost = curCost + toNode.cost;
            int oldCost = di[toNode.to];

            if(newCost < oldCost){
                di[toNode.to] = newCost;
                PQ.push({newCost, toNode.to});
            }
        }
    }
}

void printAns(){
    for(int i = 1; i <= V; i++){
        if(di[i] >= INF){
            cout << "INF" << '\n';
        }
        else{
            cout << di[i] << '\n';
        }
    }
}

int main(){
    input();

    makeDi();

    printAns();
}