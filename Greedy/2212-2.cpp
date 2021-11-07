#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

int sensor[MAX];
int diff[MAX];

int main(){
    int n, k;
    int len = 0;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> sensor[i];
    }
    sort(sensor, sensor + n);

    for(int i= 1; i < n; i++){
        diff[i - 1] = sensor[i] - sensor[i - 1];
    }

    sort(diff, diff + n);

    for(int i = 0; i < n - k + 1; i++){
        len += diff[i];
    }

    cout << len;
}