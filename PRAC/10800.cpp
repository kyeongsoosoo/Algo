#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200005

using namespace std;

struct ball{
    int weight, color, idx;
};

vector<ball> V;
int ans[MAX] = {0, };
int C[MAX] = {0, };
int S[MAX] = {0, };
int N;

bool comp(ball &a, ball &b){
    if(a.weight == b.weight) return a.color < b.color;
    return a.weight < b.weight;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int c, w;

    for(int i = 0; i < N; i++){
        cin >> c >> w;
        V.push_back({w, c, i});
    }
    sort(V.begin(), V.end(), comp);
}

void find_ans(){
    int sum = 0;

    for(int i = 0; i < N; i++){
        int weight = V[i].weight;
        int color = V[i].color;
        int idx = V[i].idx;


        sum += weight;
        S[weight] += weight;
        C[color] += weight;

        ans[idx] = sum - S[weight] - C[color] + weight;
        // cout << weight << " " << color << " " << idx << " " << ans[idx] << '\n';
        if(i != 0 && (V[i-1].color == color) && (V[i-1].weight == weight)) ans[idx] = ans[V[i-1].idx];
    }
}

void print_ans(){
    for(int i = 0; i < N; i++){
        cout << ans[i] << '\n';
    }
}

int main(){
    input();
    find_ans();
    print_ans();
}
