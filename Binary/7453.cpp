#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4010

using namespace std;

int N;
int ans;
int arr[4][MAX];
vector<int> ab, cd;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            ab.push_back(arr[0][i] + arr[1][j]);
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            cd.push_back(arr[2][i] + arr[3][j]);
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
}

long long makeSearch(){
    long long res = 0;
    int lo = 0, hi = N * N - 1;

    while(hi >= 0 && lo < N * N){
        if(ab[hi] + cd[lo] == 0){
            int a_eq = 0, c_eq = 0;
            int tmp = cd[lo];
            while((ab[hi] == -tmp) && hi >= 0)
                a_eq++, hi--;
            while((cd[lo] == tmp) && lo < N*N)
                c_eq++, lo++;

            res += (long long)a_eq * c_eq;
        }
        else if(ab[hi] + cd[lo] > 0)
            hi--;
        else lo++;
    }
    return res;
}

int main(){
    input();
    long long res = makeSearch();
    cout << res;
}