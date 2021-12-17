#include <iostream>
#include <algorithm>
#include <vector>
#define N_MAX 1000

using namespace std;

long long T;
int n, m;
long long listA[N_MAX];
long long listB[N_MAX];
long long result = 0;
vector<long long> subsetA;
vector<long long> subsetB;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> listA[i];
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> listB[i];
    }
}

vector<long long> makeSubsetSum(long long* list, int list_length){
    vector<long long> subset_vector;

    for (int i = 0; i < list_length; i++){
        long long sum = list[i];
        subset_vector.push_back(sum);
        for (int j = i + 1; j < list_length; j++)
        {
                sum += list[j];
                subset_vector.push_back(sum);
        }
    }
    return subset_vector;
}



void solve(){
    subsetA = makeSubsetSum(listA, n);
    subsetB = makeSubsetSum(listB, m);

    sort(subsetA.begin(), subsetA.end());
    sort(subsetB.begin(), subsetB.end());

    for (int i = 0; i < subsetA.size(); i++)
    {
        int low = lower_bound(subsetB.begin(), subsetB.end(), T - subsetA[i]) - subsetB.begin();
        int high = upper_bound(subsetB.begin(), subsetB.end(), T - subsetA[i]) - subsetB.begin();
        result += high - low;
    }
}

int main(){
    input();
    solve();

    cout << result;
}