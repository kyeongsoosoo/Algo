#include <iostream>
#include <algorithm>
#define MAX 10010
#define INF 9876543212

using namespace std;

int N, M;
int ride[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> ride[i];
    }
}

long long binarySearch(){
    long long low = 0;
    long long high = 2000000000LL * 30LL;
    long long result = -1;
    while(low <= high){
        long long mid = (low + high) / 2;
        long long children = M;
        for(int i = 0; i < M; i++)
            children += mid / ride[i];
        
        if(children >= N){
            result = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
        

    }
    return result;
}

int findAns(){
    if(N <= M) return N;

    long long time = binarySearch();
    long long children = M;
    for(int i = 0; i< M; i++){
        children += (time - 1) / ride[i];
    }

    for(int i = 0; i < M; i++){
        if(!(time % ride[i])) children++;

        if(children == N) return i + 1;
    }
    return 0;
}

int main(){
    input();
    int ans = findAns();
    cout << ans;
}