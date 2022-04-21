#include <iostream>

#define MAX 310

using namespace std;

int N, M;
int map[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> map[i];
    }
}

bool is_possible(int mid){
    int sum = 0;
    int group = 1;

    for(int i = 0; i < N; i++){
        if(map[i] > mid) return false;
        sum += map[i];

        if(sum > mid){
            group += 1;
            sum = map[i];
        }
    }

    return group <= M;
}

void print_ans(int ans){
    cout << ans << '\n';

    int sum = 0;
    int elem_count = 0;
    int group_count = 0;

    // 범위까지 다 차면 다음으로


    for(int i = 0; i < N; i++){
        int left_elem = N - i;

        sum += map[i];
        elem_count += 1;


        // if(M - group_count == left_elem) {
        //     cout << elem_count - 1 << " ";
        //     group_count += 1;
        //     break;
        // };

        if(sum > ans){
            cout << elem_count - 1 << " ";
            group_count += 1;
            elem_count = 1;
            sum = map[i];
        }

        if(left_elem == M - group_count) break;
    }

    if(elem_count > 1){
            cout << elem_count << " ";
            group_count += 1;
            elem_count = 1;
    }

    while(group_count != M){
        cout << "1 ";
        group_count += 1;
    }
}

void solve(){
    int start = 0;
    int end = 30000;

    while(start < end){
        int mid = (start + end) / 2;

        if(is_possible(mid)){
            end = mid;
            continue;
        }

        start = mid + 1;
    }

    print_ans(end);
}

int main(){
    input();
    solve();
}