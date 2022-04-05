#include <iostream>
#include <cstring>

#define N_MAX 210
#define M_MAX 20010
#define L_MAX 110
#define INF 987654321

using namespace std;

int N, M;
int map[N_MAX][N_MAX];
int origin[N_MAX][N_MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    memset(map, -1, sizeof(map));
    memset(origin, -1, sizeof(origin));

    int s, e, l;

    for(int i = 0; i < M; i++){
        cin >> s >> e >> l;

        if(map[s][e] == -1){
            map[s][e] = l;
            map[e][s] = l;
            origin[e][s] = l;
            origin[s][e] = l;
        }
        else{
            map[s][e] = min(map[s][e], l);
            map[e][s] = min(map[e][s], l);
            origin[e][s] = max(origin[e][s], l);
            origin[s][e] = max(origin[s][e], l);
        }
    }




    for(int i = 1; i <= N; i++){
        map[i][i] = 0;
    }
}

void floyd(){
    for(int mid = 1; mid <= N; mid++){
        for(int start = 1; start <= N; start++){
            for(int end = 1; end <= N; end++){
                if(map[start][mid] == -1 || map[mid][end] == -1) continue;

                int sum = map[start][mid] + map[mid][end];

                if(map[start][end] == -1 || map[start][end] > sum){
                    map[start][end] = sum;
                }
            }
        }
    }
}

void find(){
    float ans = INF;

    for(int point = 1; point <= N; point++){
        float point_max = 0;

        for(int start = 1; start <= N; start++){
            for(int to = 1; to <= N; to++){
                if(origin[start][to] == -1) continue;

                float time = (map[point][start] + map[point][to] + origin[start][to]) / (float)2;

                // cout << map[point][start] << " " << map[point][to] << " " << origin[start][to] << " " << time << '\n';
                point_max = max(point_max, time);

            }
        }

        ans = min(ans, point_max);
    }

    cout << fixed;
    cout.precision(1);
    cout << ans;
}

int main(){
    input();
    floyd();
    find();
}
