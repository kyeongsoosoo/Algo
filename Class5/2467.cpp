#include <iostream>
#include <algorithm>
#define MAX 100001
#define INF 3000000000

using namespace std;

int N;
long long arr[MAX];
int min_num, max_num;
int ans_min, ans_max;
long long min_sum = INF;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);
}

void twoPointer(){
    min_num = 0;
    max_num = N - 1;

    while(min_num < max_num){
        long long sum = arr[min_num] + arr[max_num];
        if(abs(sum) < min_sum){
            ans_min = min_num;
            ans_max = max_num;
            min_sum = abs(sum);
        }

        if(sum < 0){
            min_num++;
        }
        else{
            max_num--;
        }
    }
}

int main(){
    input();
    twoPointer();

    cout << arr[ans_min] << " " << arr[ans_max];
}