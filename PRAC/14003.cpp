#include <iostream>
#include <vector>

#define MAX 1000100
#define INF 987654321

using namespace std;

int N;
vector<int> arr;
vector<int> ans;
vector<int> ans_set;
vector<int> idx_map;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
}

int binary_search(int target){
    int start = 0;
    int end = ans.size();

    while(start < end){
        int mid = (start + end) / 2;

        if(ans[mid] < target) start = mid + 1;
        else end = mid;
    }

    return end;
}

void find(){
    for(int i = 0; i < N; i++){
        if(ans.size() == 0 || ans[ans.size() - 1] < arr[i]) ans.push_back(arr[i]);

        int position = binary_search(arr[i]);

        ans[position] = arr[i];
        idx_map.push_back(position);
    }
}

void collect_ans(){
    int end_idx = ans.size() - 1;

    for(int i = idx_map.size() - 1; i >= 0; i--){
        if(idx_map[i] == end_idx){
            ans_set.push_back(arr[i]);
            end_idx -= 1;
        }
    }
}

void print_ans(){
    cout << ans.size() << '\n';

    for(int i = ans_set.size() - 1; i >= 0; i--){
        cout << ans_set[i] << " ";
    }
}

int main(){
    input();
    find();
    collect_ans();
    print_ans();
}