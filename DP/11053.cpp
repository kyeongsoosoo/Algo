#include <iostream>
#define max(a,b) (a>b ? a : b)

using namespace std;

int main() {
    int N;
    int arr[1000];
    int DP[1000];

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<N; i++){
        DP[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i])
                DP[i] = max(DP[i], DP[j] + 1);
        }
    }
    int max_N = DP[0];
    for(int i=1; i<N; i++){
        max_N = max(DP[i], max_N);
    }
    cout << max_N;
}

