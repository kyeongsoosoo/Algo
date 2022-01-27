#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4000


using namespace std;

int n;
long long A[MAX], B[MAX], C[MAX], D[MAX];
vector<long long> arr1;
vector<long long> arr2;

long long ans_counter = 0;


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr1.push_back(A[i] + B[j]);
            arr2.push_back(C[i] + D[j]);
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int findLowerBound(vector<long long> arr, int idx){
    long long target = arr[idx];

    int start = 0;
    int end = idx;

    while(start < end){
        int mid = (start + end) / 2;
        long long next_target = arr[mid];

        if(next_target >= target){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
    return end;
}

int findUpperBound(vector<long long> arr, int idx){
    long long target = arr[idx];

    int start = idx;
    int end = arr.size();

    while(start < end){
        int mid = (start + end) / 2;
        long long next_target = arr[mid];

        if(next_target > target){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
    return end;
}

void find(){
    int start = 0;
    int end = arr2.size() - 1;

    while(start < arr1.size() && end >= 0){
        long long sum = arr1[start] + arr2[end];

        if(sum < 0) start++;
        else if(sum > 0) end--;
        else{
            int origin1 = start;
            int origin2 = end;

            long long arr1_count = 0;
            long long arr2_count = 0;

            while(start < arr1.size() && arr1[start] == arr1[origin1]){
                arr1_count += 1;
                start += 1;
            }

            while (end >= 0 && arr2[end] == arr2[origin2]){
                arr2_count += 1;
                end -= 1;
            }

            ans_counter += (arr1_count * arr2_count);

            // int new_idx1 = findUpperBound(arr1, start);
            // int new_idx2 = findLowerBound(arr2, end);

            // long long count1 = new_idx1 - start;
            // long long count2 = end - new_idx2 + 1;

            // ans_counter += (count1 * count2);

            // start = new_idx1;
            // end = new_idx2 - 1;
        }
    }
}

int main(){
    input();
    find();

    cout << ans_counter;
}