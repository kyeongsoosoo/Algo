#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4001

using namespace std;

int n;
int A[MAX], B[MAX], C[MAX], D[MAX];
vector<int> first;
vector<int> second;
long long ans_count = 0;

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
            first.push_back(A[i] + B[j]);
            second.push_back(C[i] + D[j]);
        }
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
}

void countAns(){
    int start = 0;
    int end = second.size() - 1;

    while(start != first.size() && end != -1){
        int first_v = first[start];
        int second_v = second[end];
        int total = first_v + second_v;

        if(total == 0){
            int a_eq = 0, c_eq = 0;
            int tmp = first[start];
            while((second[end] == -tmp) && end >= 0)
                a_eq++, end--;
            while((first[start] == tmp) && start < n*n)
                c_eq++, start++;

            ans_count += (long long)a_eq * c_eq;
        }
        else if(total > 0){
            end -= 1;
        }
        else{
            start += 1;
        }
    }
}

int main(){
    input();
    countAns();
    cout << ans_count;
}