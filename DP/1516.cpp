#include <iostream>
#include <vector>
#include <queue>
#define MAX 501

using namespace std;

int N;
int inDegree[MAX];
vector<int> Edges[MAX];
int duration[MAX];
int DP[MAX];

queue<int> q;


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++){
        int tmp;
        cin >> tmp;
        duration[i] = tmp;

        while(true){
            int node;
            cin >> node;

            if(node == -1) break;

            inDegree[i]++;
            Edges[node].push_back(i);
        }

    }
}

void makeBFS(){
    for(int i = 1; i <= N; i++){
        if(inDegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i = 0; i < Edges[node].size(); i++){
            int nextNode = Edges[node][i];

            DP[nextNode] = max(DP[nextNode], DP[node] + duration[node]);

            if(--inDegree[nextNode] == 0) q.push(nextNode);
        }
    }
}

int main(){
    input();
    makeBFS();

    for(int i = 1; i <= N; i++){
        cout << DP[i] + duration[i] << '\n';
    }
}