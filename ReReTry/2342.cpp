#include <iostream>
#include <vector>
#define MAX 100001
#define INF 987654321

using namespace std;

vector<int> arr;
int DP[MAX][5][5];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tmp;
    
    while(arr.size() == 0 || tmp){
        cin >> tmp;
        arr.push_back(tmp);
    }
}

int calcCost(int start, int goal){
    if(start == 0){
        return 2;
    }
    if(start == goal){
        return 1;
    }
    if(abs(start - goal) == 2){
        return 4;
    }
    return 3;
}

int makeMove(int left, int right, int idx){
    if(idx == arr.size() - 1) return 0;
    if(DP[idx][left][right]) return DP[idx][left][right];

    DP[idx][left][right] = INF;

    int goal = arr[idx];

    DP[idx][left][right] = min(
        makeMove(goal, right, idx + 1) + calcCost(left, goal),
        makeMove(left, goal, idx + 1) + calcCost(right, goal)
    );
    // cout << "idx: " << idx << '\n';
    // cout << "left: " << left << " right: " << right << " cost: " << DP[idx][left][right] << '\n';

    return DP[idx][left][right];
}

int main(){
    input();
    cout << makeMove(0, 0, 0);
}

