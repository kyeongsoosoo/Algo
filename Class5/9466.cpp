#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int TC;
int N;
int* edges;
bool* visited;
bool* counted;
int ans_count = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
}

void caseInput(){
    cin >> N;
    ans_count = 0;

    edges = new int[N + 1];
    visited = new bool[N + 1];
    counted = new bool[N + 1];

    for(int i = 1; i <= N; i++){
        cin >> edges[i];
    }
}

void makeDFS(int cur_node){
    visited[cur_node] = true;

    int next = edges[cur_node];
    if(!visited[next]){
        makeDFS(next);
    }
    else if(!counted[next]){
        for(int i = next; i != cur_node; i = edges[i]){
            ans_count++;
        }
        ans_count++;
    }

    counted[cur_node] = true;
}

int main(){
    input();
    while(TC--){
        caseInput();
        for(int i = 1; i <= N; i++){
            if(!visited[i])
                makeDFS(i);
        }

        cout << N - ans_count << '\n';
    }
}