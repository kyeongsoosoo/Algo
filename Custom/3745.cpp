#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX 100005

using namespace std;

int N;
int map[MAX];
vector<int> V;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int custom_lower(int num){
    int start = 0;
    int end = V.size() - 1;

    while(start < end){
        int mid = (start + end) / 2;

        if(V[mid] >= num){
            end = mid;
            continue;
        }
        start = mid + 1;
    }

    return end;
}

int main(){
    input();

    while(cin >> N){
        V.clear();
        memset(map, 0, sizeof(map));

        for(int i = 0; i < N; i++){
            cin >> map[i];
        }

        for(int i = 0; i < N; i++){
            int last_idx = V.size() - 1;

            if(V.empty() || V[last_idx] < map[i]){
                V.push_back(map[i]);
                continue;
            }
            // int idx = lower_bound(V.begin(), V.end(), map[i]) - V.begin();
            int idx = custom_lower(map[i]);
            V[idx] = map[i];
        }

        cout << V.size() << '\n';
    }
}