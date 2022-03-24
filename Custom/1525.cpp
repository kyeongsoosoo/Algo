#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string>

#define endl "\n"

using namespace std;

string Start, End;
set<string> Visit;


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    End = "123456780";

    int tmp;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> tmp;
            char tmp_s = tmp + '0';
            Start = Start + tmp_s;
        }
    }
}

int bfs(){
    queue< pair<string, int> > Q;
    
    Q.push(make_pair(Start, 0));
    Visit.insert(Start);

    while(Q.empty() == 0){
        string cur = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();

        if(cur == End) return cnt;

        int zero = cur.find('0');
        int x= zero / 3;
        int y = zero % 3;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < 3 && ny < 3){
                string next = cur;
                swap(next[x * 3 + y], next[nx * 3 + ny]);

                if(Visit.find(next) == Visit.end()){
                    Visit.insert(next);
                    Q.push(make_pair(next, cnt + 1));
                }
            }
        }
    }

    return -1;
}

int main(){
    input();
    cout << bfs();
}