#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000

using namespace std;

int T;
int n, m;
long long arr1[MAX];
long long arr2[MAX];
vector<long long> A;
vector<long long> B;

long long ans_counter = 0;


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    for(int i = 0; i < n; i++){
        long long sum = 0;
        for(int j = i; j < n; j++){
            sum += arr1[j];
            A.push_back(sum);
        }
    }

    for(int i = 0; i < m; i++){
        long long sum = 0;
        for(int j = i; j < m; j++){
            sum += arr2[j];
            B.push_back(sum);
        }
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
}

void search(){
    int pointer_A = 0;
    int pointer_B = B.size() - 1;

    int a_max = A.size();

    while(pointer_A < a_max && pointer_B >= 0){
        // cout << pointer_A << " " << pointer_B << '\n';
        long long sumA = A[pointer_A];
        long long sumB = B[pointer_B];

        long long sum = sumA + sumB;

        if(sum < T){
            pointer_A += 1;
        }
        else if(sum == T){
            int origin_A = pointer_A;
            int origin_B = pointer_B;

            long long case_a = 0;
            long long case_b = 0;

            while(pointer_A < a_max && A[pointer_A] == A[origin_A]){
                case_a += 1;
                pointer_A += 1;
            }

            while(pointer_B >= 0 && B[pointer_B] == B[origin_B]){
                case_b += 1;
                pointer_B -= 1;
            }

            ans_counter += (case_a * case_b);
        }
        else{
            pointer_B -= 1;
        }
    }
}

int main(){
    input();
    search();

    cout << ans_counter;
}