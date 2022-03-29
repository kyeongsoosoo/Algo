#include <iostream>
#include <vector>
#include <queue>

#define MAX 1010
#define INF 987654321

using namespace std;

int N, M;
int di[MAX];
int prev_path[MAX];
vector<pair<int, int>> edges[MAX];
vector<pair<int, int>> paths;

struct compare{
    bool operator()(pair<int, int> A, pair<int, int> B){
        return A.second < B.second;
    }
};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int s, e, c;
    for(int i = 1; i <= M; i++){
        cin >> s >> e >> c;
        edges[s].push_back(make_pair(e, c));
        edges[e].push_back(make_pair(s, c));

    }

    for(int i = 1; i <= N; i++){
        di[i] = INF;
        prev_path[i] = i;
    }
}

void make_di(){

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> PQ;
    PQ.push(make_pair(1, 0));

    while(!PQ.empty()){
        pair<int, int> cur = PQ.top(); PQ.pop();
        int cur_pos = cur.first;
        int cur_cost = cur.second;

        for(int i = 0; i < edges[cur_pos].size(); i++){
            pair<int, int> next = edges[cur_pos][i];
            int next_pos = next.first;
            int next_cost = next.second;
            int total_cost = cur_cost + next_cost;

            if(total_cost < di[next_pos]){
                di[next_pos] = total_cost;
                prev_path[next_pos] = cur_pos;
                PQ.push(make_pair(next_pos, total_cost));
            }
        }
    }
}

void find_path(){
    for(int i = 2; i <= N; i++){
        int prev_path_pos = prev_path[i];
        paths.push_back(make_pair(i, prev_path_pos));
    }
}

void print_path(){
    cout << paths.size() << '\n';

    for(int i = 0; i < paths.size(); i++){
        pair<int, int> path = paths[i];
        cout << path.first << " " << path.second << '\n';
    }
}

int main(){
    input();
    make_di();
    find_path();
    print_path();
}