#include <iostream> 
#include <vector>

#define N_MAX 110
#define M_MAX 2010
#define INF 987654321

using namespace std;

int N;
int M;
int nodes[N_MAX][N_MAX];
int map[N_MAX][N_MAX];

void input(){
    ios::sync_with_stdio(false);
    cin >> N >> M;

    int node1, node2;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            nodes[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++){
        cin >> node1 >> node2;
        nodes[node2][node1] = 1;
    }
}

void floyd(){
    for(int mid = 1; mid <= N; mid++){
        for(int end = 1; end <= N; end++){
            for(int start = 1; start <= N; start++){
                if(start == mid || mid == end || start == end) continue;
                if(nodes[start][mid] == INF || nodes[mid][end] == INF) continue;

                nodes[start][end] = min(nodes[start][end], nodes[start][mid] + nodes[mid][end]);
            }
        }
    }
}

void counting_inf(){
    for(int i = 1; i <= N; i++){
        int sum = 0;

        for(int j = 1; j <= N; j++){
            // cout << "i: " << i << " j: " << j << " " << nodes[i][j] << " " << nodes[j][i] << '\n';
            if(i == j) continue;
            if(nodes[i][j] != INF || nodes[j][i] != INF) continue;
            sum += 1;
        }

        cout << sum << '\n';
    }
}

int main(){
    input();
    floyd();
    counting_inf();
}