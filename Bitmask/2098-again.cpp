#include <iostream>
#include <cstring>

#define MAX 16
#define INF 987654321

using namespace std;

int N, Answer_Bit;
int MAP[MAX][MAX];
int Cost[MAX][1 << MAX];


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }

    Answer_Bit = (1 << N) - 1;

    memset(Cost, -1, sizeof(Cost));
}

int makeDFS(int cur_node, int cur_bit){
    if(cur_bit == Answer_Bit){
        if(MAP[cur_node][0] == 0) return INF;
        else return MAP[cur_node][0];
    }

    if(Cost[cur_node][cur_bit] != -1) return Cost[cur_node][cur_bit];
    Cost[cur_node][cur_bit] = INF;

    for(int next_node = 0; next_node < N; next_node++){
        if((cur_bit & (1 << next_node))== (1 << next_node)) continue;
        if(MAP[cur_node][next_node] == 0) continue;

        Cost[cur_node][cur_bit] = min(Cost[cur_node][cur_bit], makeDFS(next_node, (cur_bit | (1 << next_node))) + MAP[cur_node][next_node]);
    }
    return Cost[cur_node][cur_bit];
}

int main(){
    input();
    makeDFS(0, 1);

    cout << Cost[0][1];
}