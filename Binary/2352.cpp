#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 40010

using namespace std;

int N;
vector<int> V;
int Arr[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> Arr[i];
    }
}

void makeBinary(){
    for(int i = 1; i <= N; i++){
        if(V.size() == 0 || V[V.size() - 1] < Arr[i]) V.push_back(Arr[i]);
        else{
            int Pos = lower_bound(V.begin(), V.end(), Arr[i]) - V.begin();
            V[Pos] = Arr[i];
        }
    }
}

int main(){
    input();
    makeBinary();
    cout << V.size();
}