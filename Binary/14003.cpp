#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int N;
int arr[MAX];
int idx[MAX];
vector<int> longest_list;
vector<int> ans;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void findLongest(){
    for(int i = 0; i < N; i++){
        if(longest_list.size() == 0 || arr[i] > longest_list[longest_list.size() - 1]){
            longest_list.push_back(arr[i]);
            idx[i] = longest_list.size() - 1;
            continue;
        }

        int start = 0, end = longest_list.size() - 1;
        while(start <= end){
            int mid = (start + end) / 2;

            if(longest_list[mid] >= arr[i]) end = mid - 1;
            else start = mid + 1;
        }
        idx[i] = start;
        longest_list[start] = arr[i];
    }
}

void printAns(){
    cout << longest_list.size() << '\n';

    // for(int i = 0; i < N; i++){
    //     cout << idx[i] << '\n';
    // }

    int max_idx = longest_list.size() - 1;
    for(int i = N - 1; i >= 0; i--){
        if(max_idx == idx[i]){
            ans.push_back(arr[i]);
            max_idx--;
        }
    }

    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
}

int main(){
    input();
    findLongest();
    printAns();
} 