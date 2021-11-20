#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000010

using namespace std;

int N;
vector<int> A;
vector<int> L;
vector<int> ans;
int Idx[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
}

void findLongest(){
    for(int i = 0; i < A.size(); i++){
        if(L.empty() || A[i] > L[L.size() - 1]){
            L.push_back(A[i]);
            Idx[i] = L.size() - 1;
            continue;
        }
        else
        {
            int Left = 0;
            int Right = L.size() - 1;
            while (Left <= Right)
            {
                int Mid = (Left + Right) / 2;
                
                if (L[Mid] >= A[i]) Right = Mid - 1;
                else Left = Mid + 1;
            }
            L[Left] = A[i];
            Idx[i] = Left;
        }
    }
}

void printAns(){
    int find_idx = L.size() - 1;
    for(int i = N - 1; i >= 0; i--){
        if(Idx[i] == find_idx){
            find_idx--;
            ans.push_back(A[i]);
        }
    }
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
}

int main(){
    input();
    findLongest();
    cout << L.size() << '\n';
    printAns();
}
