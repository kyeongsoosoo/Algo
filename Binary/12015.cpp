#include <iostream>
#include <algorithm>
#include <vector>
#define ret 1000000007

using namespace std;

int arr[1000001];
vector<int> L;
int N;

void input(){
    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
}

int find_lower_b(int num){
    int start = 0;
    int last = L.size() - 1;
    int next = ret;

    while( last >= start ){
        int mid = (start + last) / 2;
        if(L[mid] >= num){
            next = mid;
            last = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return next;
}

int main(){
    input();

    for(int i = 0; i < N; i++){
        if(L.empty()){
            L.push_back(arr[i]);
        }
        else if(arr[i] > L.back()){
            L.push_back(arr[i]);
        }
        else{
            int idx = find_lower_b(arr[i]);
            L[idx] = arr[i];
        }
    }

    cout << L.size();
}