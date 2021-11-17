#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10001

using namespace std;

int V,E;
vector<pair<int, pair<int, int> > > Coord;
int arr[MAX];
int ans = 0;

int find(int idx)
{
    if (arr[idx] == idx)
        return idx;

    return arr[idx] = find(arr[idx]);
}

void merge(int a, int b)
{
    int a_idx = find(a);
    int b_idx = find(b);

    if (a_idx == b_idx)
        return;

    arr[a_idx] = b_idx;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        Coord.push_back(make_pair(cost, make_pair(from, to)));
    }

    for(int i = 1; i <= V; i++){
        arr[i] = i;
    }

    sort(Coord.begin(), Coord.end());
}

void makeMST(){
    int n = 0;
    for(int i = 0; i < Coord.size(); i++){
        if(n == V - 1) break;

        int from = Coord[i].second.first;
        int to = Coord[i].second.second;
        int cost = Coord[i].first;

        if(find(from) != find(to)){
            n++;
            merge(from, to);
            ans += cost;
        }
    }

    cout << ans;
}

int main(){
    input();
    makeMST();
}