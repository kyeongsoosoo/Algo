#include <iostream>
#include <cstring>
#define MAX 100001

using namespace std;

int TC;
int n;
int arr[MAX];
bool visited[MAX];
bool editied[MAX]; 

int ans_counter = 0;


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
}

void caseInput(){
    memset(arr, 0, sizeof(arr));
    memset(visited, false, sizeof(visited));
    memset(editied, false, sizeof(editied));

    ans_counter = 0;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
}

int tracking(int idx){
    if(editied[idx]) {
        // cout << idx << '\n';
        ans_counter += 1;
        return idx;
    }
    if(visited[idx]) return -1;

    visited[idx] = true;
    editied[idx] = true;

    int next = arr[idx];
    int res = tracking(next);

    editied[idx] = false;

    if(res != -1){
        if(idx != res){
            // cout << "idx: " << idx << " res: " << res << '\n';
            ans_counter += 1;
        }
        else{
            return -1;
        }
    }
    return res;
}

int main(){
    input();
    while(TC--){
        caseInput();
        for(int i = 1; i <= n; i++){
            if(!visited[i]) tracking(i);
        }
        cout << (n - ans_counter) << '\n';
    }
}