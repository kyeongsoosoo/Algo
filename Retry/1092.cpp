#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define BOX_WEIGHT 1000001
#define CRANE_NUM 51
#define BOX_NUM 10001

using namespace std;

int N, M;
vector<int> cranes;
vector<int> boxes;
int ans_count = 0;

bool compare(int a, int b){
    return a > b;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp; 
        cin >> tmp;
        cranes.push_back(tmp);
    }

    cin >> M;

    for(int i = 0; i < M; i++){
        int tmp;
        cin >> tmp;
        boxes.push_back(tmp);
    }
    sort(cranes.begin(), cranes.end(), compare);
    sort(boxes.begin(), boxes.end(), compare);

}

void makeGreedy(){
    if(boxes[0] > cranes[0]){
        ans_count = -1;
        return;
    }

    while(!boxes.empty()){
        ans_count += 1;
        for(int i = 0; i < cranes.size(); i++){
            for(int j = 0; j < boxes.size(); j++){
                if(cranes[i] >= boxes[j]){
                    boxes.erase(boxes.begin() + j);
                    break;
                }
            }
        }
    }
}


int main(){
    input();
    makeGreedy();

    cout << ans_count;
}