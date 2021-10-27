#include <iostream>
#include <vector>
#include <algorithm>
#define MAX = 1000000000 + 1

using namespace std;

int N;
vector<int> weight;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    weight.resize(N);

    for(int i = 0; i < N; i++){
        cin >> weight[i];
    }

    sort(weight.begin(), weight.end());
}

void greedy(){
    if(weight[0] != 1)
        cout << 1;
    else {
        int sum = 1;

        for(int i = 1; i < N; i++){
            if(weight[i] > sum + 1)
                break;
            sum += weight[i];
        }

        cout << sum + 1 << '\n';
    }
}


int main(){
    input();
    greedy();
}