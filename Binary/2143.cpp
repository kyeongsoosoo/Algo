#include <iostream>
#include <vector>
#define MAX 100010

using namespace std;

int N;
vector<int> Edges;
vector<int> L;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        Edges.push_back(tmp);
    }
}

void makeLongest(){
    for(int i = 0; i < Edges.size(); i++){
        int tmp = Edges[i];

        if(L.empty() || L[L.size() - 1] < tmp){
            L.push_back(tmp);
            continue;
        }

        int start = 0, end = L.size() - 1;
        while(start <= end){
            int mid = (start + end) / 2;

            if(L[mid] < tmp) start = mid + 1;
            else end = mid - 1;

            cout << "?";
        }
        L[start] = tmp;
    }
}

int main(){
    input();
    makeLongest();
    int R = N - L.size();
    cout << R;
}