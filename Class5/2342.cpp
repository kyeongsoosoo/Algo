#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;

vector<int> task;
int cache[5][5][MAX];

int move(int from, int to){
    if(from == to) return 1;
    switch(from){
        case 0: return 2;
        case 1: return to == 3 ? 4 : 3;
        case 2: return to == 4 ? 4 : 3;
        case 3: return to == 1 ? 4 : 3;
        case 4: return to == 2 ? 4 : 3;
    }
}

int solve(int l, int r, int n){
    if(n == task.size()) return 0;
    int& ret = cache[l][r][n];
    if(ret != 0) return ret;
    return ret = min(
        move(l, task[n]) + solve(task[n], r, n + 1),
        move(r, task[n]) + solve(l, task[n], n + 1)
    );
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        task.push_back(n);
    }

    cout << solve(0, 0, 0);

    return 0;
}