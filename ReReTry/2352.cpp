#include <iostream>
#include <vector>
#define MAX 40000

using namespace std;

int n;
int map[MAX];
vector<int> arr;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> map[i];
    }
}

int findLowerBound(int num){
    int start = 0;
    int end = arr.size() - 1;

    while(start < end){
        int mid = (start + end) / 2;

        if(arr[mid] >= num){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }

    return end;
}

void search(){
    for(int i = 0; i < n; i++){
        if(arr.size() == 0 || arr[arr.size() - 1] < map[i]){
            arr.push_back(map[i]);
            continue;
        }
        int point = findLowerBound(map[i]);
        arr[point] = map[i];
    }
}

int main(){
    input();
    search();
    cout << arr.size();
}