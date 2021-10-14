#include <iostream>
#include <queue>
#include <string>
#define MAX 1000

using namespace std;

int N, M;
int arr[MAX][MAX];
bool visited[MAX][MAX][2];

int X_POS[4] = {-1, 1, 0, 0};
int Y_POS[4] = {0, 0, -1, 1};

struct node{
    int x;
    int y;
    int distance;
    bool chance;
};

deque<node> Q;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int y = 0; y < N; y++){
        string tmp;
        cin >> tmp;
        for(int x = 0; x < M; x++){
            arr[y][x] = tmp[x] - '0';
        }
    }
}

bool hasBlock(int x, int y){
    return arr[y][x] == 1;
}

bool checkPossible(int x, int y){

    if(x < 0 || x >= M){
        return false;
    }

    if(y < 0 || y >= N){
        return false;
    }

    if(hasBlock(x, y)){
        return false;
    }

    return true;
}

int findWay(){
    Q.push_back({0, 0, 0, true});
    visited[0][0][0] = true;

    while(Q.size()){
        node elem = Q.front();
        Q.pop_front();

        

        if(elem.x == M - 1 && elem.y == N - 1) {
            return elem.distance + 1 ;    
        };
    
        for(int dir = 0; dir < 4; dir++){
            int X = elem.x + X_POS[dir];
            int Y = elem.y + Y_POS[dir];
                
            if(visited[Y][X][elem.chance]){
                continue;
            } 

            if(checkPossible(X, Y)){
                Q.push_back({X, Y, elem.distance + 1, elem.chance});
                visited[Y][X][elem.chance] = true;
            }
            else{
                if(hasBlock(X, Y) && elem.chance){
                    Q.push_back({X, Y, elem.distance + 1, false});
                    visited[Y][X][false] = true;
                }
            }
        }
    }

    return -1;
}



int main(){
    input();

    cout <<  findWay() << '\n';
}