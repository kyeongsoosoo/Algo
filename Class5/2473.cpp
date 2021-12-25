#include <iostream>
#include <algorithm>
#define INF 3000000001

using namespace std;
long long arr[5000];
long long ans[3];
long long limit = INF;

int N;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i =0 ; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);
}

void binarySearch(){
    for(int fixed = 0; fixed < N - 2; fixed++){
        int left = fixed + 1, right = N - 1;
        while(left < right){
            long long val = arr[fixed] + arr[left] + arr[right];
            if(abs(val) < limit){
                limit = abs(val);
                ans[0] = arr[fixed];
                ans[1] = arr[left];
                ans[2] = arr[right];
            }

            if(val < 0) left++;
            else right--;
        }
    }
}

int main(){
    input();
    binarySearch();

    for(int i = 0; i < 3; i++){
        cout << ans[i] << " ";
    }
}