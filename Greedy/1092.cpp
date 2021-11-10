#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int crane_weight, box_weight;

vector<int> cranes;
vector<int> boxes;
int answer = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> crane_weight;
        cranes.push_back(crane_weight);
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> box_weight;
        boxes.push_back(box_weight);
    }

    sort(cranes.begin(), cranes.end(), greater<int>());
    sort(boxes.begin(), boxes.end(), greater<int>());
}

void makeAns(){
    if(boxes[0] > cranes[0] ){
        cout << -1;
        return;
    }

    while(!boxes.empty()){
        answer++;
        for(int i = 0; i < cranes.size(); i++){
            for(int j = 0; j < boxes.size(); j++){
                if(cranes[i] >= boxes[j]){
                    boxes.erase(boxes.begin() + j);
                    break;
                }
            }
        }
    }
    cout << answer;
}

int main(){
    input();
    makeAns();
}