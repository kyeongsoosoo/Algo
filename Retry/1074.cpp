#include <iostream>

using namespace std;

int N, r, c;

int mr[4] = {0, 0, 1, 1};
int mc[4] = {0, 1, 0, 1};


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> r >> c;
}

void find(int size, int r_s, int c_s, int total){
    int len = size / 2;

    if(r < r_s || r >= r_s + size || c < c_s || c >= c_s + size) return;

    if(size == 1){
       cout << total << '\n';
    }

    for(int i = 0; i < 4; i++){
        find(size / 2, r_s + (mr[i] * len), c_s + (mc[i] * len), total);
        total += (len * len);
    }
}

int main(){
    input();
    find((1 << N), 0, 0, 0);
}