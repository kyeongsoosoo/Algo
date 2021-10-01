#include <iostream>
#include <vector>

using namespace std;

int N;

int q_count = 0;

vector<int> v;

void queen(int idx){
    if(idx == N){
        q_count++;
        return;
    }

    for(int i=0; i<N; i++){
        int isTrue = 1;
        for(int j=0; j<idx; j++){
            if(v[j] == i || (abs(v[j] - i)) == idx - j){
                isTrue = 0;
                break;
            }
        }
        if(isTrue){
            v.push_back(i);
            queen(idx+1);
            v.pop_back();
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    queen(0);

    cout << q_count;
}