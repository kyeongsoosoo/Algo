#include <iostream>
#include <vector>
#include <cstring>
#define MAX 20001

using namespace std;

int K;
int V, E;
int colors[MAX];
vector<int> Edge[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
}

void caseInput(){
    for(int i = 0; i < MAX; i++){
        Edge[i].clear();
    }

    memset(colors, 0, sizeof(colors));

    cin >> V >> E;

    int v1, v2;
    for(int i = 0; i < E; i++){
        cin >> v1 >> v2;
        Edge[v1].push_back(v2);
        Edge[v2].push_back(v1);
    }
}

void coloringDFS(int v_num, int color){
    for(int i = 0; i < Edge[v_num].size(); i++){
        int next_node = Edge[v_num][i];

        if(!colors[next_node]){
            colors[next_node] = 3 - color;
            coloringDFS(next_node, 3 - color);
        }
    }
}

bool checkBipartite(){
    for(int i = 1; i <= V; i++){

        int curColor = colors[i];

        for(int j = 0; j < Edge[i].size(); j++){
            int nextColor = colors[Edge[i][j]];
            if(curColor == nextColor ){
                return false;
            }
        }
    }
    return true;
}

void findAns(){

    for(int i = 1; i <= V; i++){
        if(!colors[i]){
            colors[i] = 1;
            coloringDFS(i, 1);
        }
    }


    bool isBipartite = checkBipartite();

    if(isBipartite){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
}

int main(){
    input();

    for(int i = 0; i < K; i++){
        caseInput();
        findAns();
    }

    return 0;
}