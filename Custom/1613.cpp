#include <iostream>
#include <vector>

#define MAX 50010
#define INF 987654321

using namespace std;
typedef pair<int, int> P;

int n, k, s;
int map[410][410];
vector<P> event;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < 405; i++){
        for(int j = 0; j < 405; j++){
            map[i][j] = INF;
        }
    }

    int a, b;

    for(int i = 0; i < k; i++){
        cin >> a >> b;
        map[a][b] = 1;
    }

    cin >> s;

    for(int i = 0; i < s; i++){
        cin >> a >> b;
        event.push_back(make_pair(a, b));
    }
}

void floyd(){
    for(int mid = 1; mid <= n; mid++){
        for(int start = 1; start <= n; start++){
            for(int end = 1; end <= n; end++){
                if(start == end || start == mid || end == mid) continue;
                if(map[start][mid] == INF || map[mid][end] == INF) continue;

                int new_edge = map[start][mid] + map[mid][end];

                if(new_edge < map[start][end]) map[start][end] = new_edge;
            }
        }
    }
}

void solve(){
    for(int i = 0; i < event.size(); i++){
        P c = event[i];
        if(map[c.first][c.second] != INF) cout << "-1" << '\n';
        else if(map[c.second][c.first] != INF) cout << "1\n";
        else cout << "0\n";
    }
}

int main(){
    input();
    floyd();
    solve();
}