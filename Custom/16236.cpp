#include <iostream>
#include <queue>
#include <cstring>

#define MAX 20


using namespace std;

int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> baby;
int baby_level = 2;
int feed_number = 0;

int y_move[4] = {-1, 0, 0, 1};
int x_move[4] = {0, -1, 1, 0};

struct compare{
    bool operator()(pair<int, pair<int, int>> A, pair<int, pair<int, int>> B){
        if(A.first > B.first) return true;
        else if(A.first == B.first){
            if(A.second.first > B.second.first) return true;
            else if(A.second.first == B.second.first){
                if(A.second.second > B.second.second) return true;
            }
        }
        return false;
    }
};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int tmp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> tmp;
            if(tmp == 9){
                baby = make_pair(i, j);
                map[i][j] = 0;
                continue;
            }
            map[i][j] = tmp;
        }
    }
}

bool canMove(int y, int x){
    if(y < 0 || y >= N || x < 0  || x >= N) return false;
    if(visited[y][x]) return false;
    if(map[y][x] > baby_level) return false;
    return true;
}

bool canEat(int y, int x){
    if(map[y][x] && map[y][x] < baby_level) return true;
    return false;
}

void control_level(){
    feed_number += 1;

    if(feed_number == baby_level){
        baby_level += 1;
        feed_number = 0;
    }
}

int find_food(){
    int cost = 0;
    queue<pair<int, pair<int, int>> > pos_queue;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare > PQ;
    memset(visited, false, sizeof(visited));

    pos_queue.push(make_pair(0, baby));

    while(!pos_queue.empty()){
        pair<int, pair<int, int>> cur_pos = pos_queue.front(); pos_queue.pop();
        // cout << pos_queue.size() << '\n';
        
        int cur_cost = cur_pos.first;
        int cur_y = cur_pos.second.first;
        int cur_x = cur_pos.second.second;

        for(int i = 0; i < 4; i++){
            int next_y = cur_y + y_move[i];
            int next_x = cur_x + x_move[i];

            if(!canMove(next_y, next_x)) continue;

            visited[next_y][next_x] = true;
            pos_queue.push(make_pair(cur_cost + 1, make_pair(next_y, next_x)));

            if(!canEat(next_y, next_x)) continue;
            PQ.push(make_pair(cur_cost + 1, make_pair(next_y, next_x)));
        }
    }

    if(PQ.empty()) return 0;

    pair<int, pair<int, int>> selected = PQ.top();

    int next_y = selected.second.first;
    int next_x = selected.second.second;

    // cout << "y: " << next_y << " x: " << next_x << " cost: " << selected.first <<  " level: " << baby_level << '\n';
    
    control_level();
    baby = make_pair(next_y, next_x);
    map[next_y][next_x] = 0;


    return selected.first;
}

void find_ans(){
    int total_time = 0;

    while(true){
        int cost_time = find_food();

        // cout << "cur: " << cost_time << '\n';

        if(cost_time == 0) break;
        total_time += cost_time;
    }

    cout << total_time;
}

int main(){
    input();
    find_ans();
}
