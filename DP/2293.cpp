#include <iostream>
#include <vector>
#define LIMIT 10001

using namespace std;

int n,k;
int DP[LIMIT];
vector<int> arr;


bool isIncluded(int n){
    int size = arr.size();
    for(int i = 0; i < size; i++){
        if(arr[i] == n)
            return true;
    }
    return false;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(!isIncluded(tmp))
            arr.push_back(tmp);
    }

    DP[0] = 1;
}

void makeDP(){
    while(!arr.empty()){
        int val = arr.back();
        arr.pop_back();
        int tmp = val;

        while(val < LIMIT){
            DP[val] += DP[ val - tmp ];
            val += 1;
        }
    }
}

int main() {
    input();

    makeDP();

    cout << DP[k];

    return 0;
}