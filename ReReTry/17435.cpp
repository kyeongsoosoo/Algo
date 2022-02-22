#include <iostream>
#include <vector>
#include <cmath>
#define MAX 200001
#define MAX_D 19

using namespace std;

int height;
int m;
int q;
vector<pair<int, int>> query;

int arr[MAX][MAX_D];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;

    height = (int)ceil(log2(m));

    for(int i = 1; i <= m; i++){
        cin >> arr[i][0];
    }

    cin >> q;

    int a, b;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        query.push_back(make_pair(a, b));
    }


}

void make_sparse(){
    for(int i = 1; i < MAX_D; i++){
        for(int j = 1; j <= m; j++){
            arr[j][i] = arr[arr[j][i - 1]][i -1];
        }
    }
}

void print_ans(){
    for(int i = 0; i < query.size(); i++){
        int jump = query[i].first;
        int start = query[i].second;

        for(int j = MAX_D - 1; j >= 0; --j){
            if(jump >= 1 << j){
                jump -= 1 << j;
                start = arr[start][j];
            }
        }

        cout << start << '\n';
    }
}

int main(){
    input();
    make_sparse();
    print_ans();
}