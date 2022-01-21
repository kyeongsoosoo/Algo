#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

int N, K;
int order[MAX];
vector<int> plug;
int counter = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for(int i = 0; i < K; i++){
        cin >> order[i];
    }
}

bool hasIdx(int idx){
    for(int i = 0; i < plug.size(); i++){
        // cout << "plug: " << plug[i] << '\n';
        if(plug[i] == order[idx]) return true;
    }
    return false;
}

int lastUsage(int start_idx){
    int last_usage_idx = 0;
    int plug_idx = 0;

    for(int k = 0; k < plug.size(); k++){
        bool selected = false;
        for(int i = start_idx; i < K; i++){
            if(order[i] == plug[k]) {
                selected = true;
                if( i > last_usage_idx){
                    last_usage_idx = i;
                    plug_idx = k;
                }
                break;
            };
        }
        if(!selected) return k;
    }
    return plug_idx;
}

void play(){
    int play_time = K;
    int idx = -1;

    while(play_time--){
        // cout << '\n';
        idx += 1;
        if(hasIdx(idx)) continue;
        if(plug.size() < N){
            plug.push_back(order[idx]);
        }
        else{
            int last_usage_idx = lastUsage(idx);
            // cout << "last: " << last_usage_idx << " idx: " << idx << '\n';
            plug[last_usage_idx] = order[idx];
            counter += 1;
        }

    }
}

int main(){
    input();
    play();
    cout << counter;
}